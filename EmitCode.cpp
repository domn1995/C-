//  TM Code emitting utilities
//  implementation for the TINY compiler
//  Compiler Construction: Principles and Practice
//  Kenneth C. Louden
//  Modified slightly by Jorge L. Williams
//  Modified Nov 13, 2015 Robert Heckendorn
//
//  The two comment string forms of the calls allow you to easily
//  compose a comment from text and a symbol name for example. 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "EmitCode.h"

extern FILE *code;

//  TM location number for current instruction emission
static int emitLoc = 0;
static int litLoc = 0;
static int maxLoc = 0;

//  Procedure emitComment prints a comment line 
// with a comment that is the concatenation of c and d
// 
void EmitComment(char *c, char *cc)
{
    fprintf(code, "* %s %s\n", c, cc);
}

//  Procedure emitComment prints a comment line 
// with comment c in the code file
// 
void EmitComment(char *c)
{
    fprintf(code, "* %s\n", c);
}

void EmitComment(std::string comment)
{
    fprintf(code, "* %s\n", (char*)comment.c_str());
}

void EmitEmptyLine()
{
    EmitComment("");
    fprintf(code, "* ** ** ** ** ** ** ** ** ** ** ** **\n");
}

void EmitInstruction(Instruction i, int r, int s, int t, std::string c, bool parens/*=true*/)
{
    if (parens)
    {
        fprintf(code, "%3d:  %5s  %d,%d(%d)\t%s \n", emitLoc, InstructionToStr(i), r, s, t, (char*)c.c_str());
    }
    else
    {
        fprintf(code, "%3d:  %5s  %d,%d,%d\t%s \n", emitLoc, InstructionToStr(i), r, s, t, (char*)c.c_str());    
    }
    
    fflush(code);
    emitLoc++;
    
    if (emitLoc > maxLoc)
    {
        maxLoc = emitLoc;
    }
}

// emitRO emits a REGISTER-ONLY TM instruction
// op = the opcode
// r = target register
// s = 1st source register
// t = 2nd source register
// c = a comment to be printed if TraceCode is TRUE
// 
void EmitRO(char *op, int r, int s, int t, char *c, char *cc)
{
    fprintf(code, "%3d:  %5s  %d,%d,%d\t%s %s\n", emitLoc, op, r, s, t, c, cc);
    fflush(code);
    emitLoc++;
}

void EmitRO(char *op, int r, int s, int t, char *c)
{
    EmitRO(op, r, s, t, c, (char *)"");
}

// emitRM emits a REGISTER-TO-MEMORY TM instruction
// op = the opcode
// r = target register
// d = the offset
// s = the base register
// c = a comment to be printed if TraceCode is TRUE
// 
void EmitRM(char *op, int r, int d, int s, char *c, char *cc)
{
    fprintf(code, "%3d:  %5s  %d,%d(%d)\t%s %s\n", emitLoc, op, r, d, s, c, cc);
    fflush(code);
    emitLoc++;
}

void EmitRM(char *op, int r, int d, int s, char *c)
{
    EmitRM(op, r, d, s, c, (char *)"");
}


void EmitGoto(int d, int s, char *c, char *cc)
{
    EmitRM((char *)"LDA", PC, d, s, c, cc);
}

void EmitGoto(int d, int s, char *c)
{
    EmitGoto(d,  s, c, (char *)"");
}

// emitRMAbs converts an absolute reference 
// to a pc-relative reference when emitting a
// register-to-memory TM instruction
// op = the opcode
// r = target register
// a = the absolute location in memory
// c = a comment to be printed if TraceCode is TRUE
// 
void EmitRMAbs(char *op, int r, int a, char *c, char *cc)
{
    fprintf(code, "%3d:  %5s  %d,%d(%d)\t%s %s\n", emitLoc, op, r, a - (emitLoc + 1),
	    PC, c, cc);
    fflush(code);
    emitLoc++;
}

void EmitRMAbs(char *op, int r, int a, char *c)
{
    EmitRMAbs(op, r, a, c, (char *)"");
}

void EmitGotoAbs(int a, char *c, char *cc)
{
    EmitRMAbs((char *)"LDA", PC, a, c, cc);
}

void EmitGotoAbs(int a, char *c)
{
    EmitGotoAbs(a, c, (char *)"");
}

// emit a literal instruction
void EmitLit(char *s)
{
    litLoc += strlen(s);
    fprintf(code, "%3d:  %5s  \"%s\"\n", litLoc, (char *)"LIT", s);
    EmitRM((char *)"LDC", 3, litLoc, 6, (char *)"Load literal value");
    litLoc++;
}

// 
//  Backpatching Functions
// 

// emitSkip skips "howMany" code
// locations for later backpatch.
// It also returns the current code position.
// emitSkip(0) tells you where you are and reserves no space.
// 
int EmitSkip(int howMany)
{
    int i = emitLoc;
    emitLoc += howMany;

    return i;
}

// emitBackup backs up to 
// loc = a previously skipped location
// 
void EmitBackup(int loc)
{
    emitLoc = loc;
}

void EmitRestore()
{
    emitLoc = maxLoc;
}

// this back patches a LDA at the instruction address addr that
// jumps to the current instruction location now that it is known.
// This is essentially a backpatched "goto"
void BackPatchAJumpToHere(int addr, char *comment)
{
    int currloc;

    currloc = EmitSkip(0);          // remember where we are
    EmitBackup(addr);               // go to addr
    EmitGotoAbs(currloc, comment);  // the LDA to here
    EmitBackup(currloc);            // restore addr
}

// this back patches a JZR or JNZ at the instruction address addr that
// jumps to the current instruction location now that it is known.
void BackPatchAJumpToHere(char *cmd, int reg, int addr, char *comment)
{
    int currloc;

    currloc = EmitSkip(0);          // remember where we are
    EmitBackup(addr);               // go to addr
    EmitRMAbs(cmd, reg, currloc, comment);  // cmd = JZR, JNZ
    EmitBackup(currloc);            // restore addr
}

char* InstructionToStr(Instruction i)
{
    if (i == HALT)  return strdup("HALT");
    if (i == NOP)   return strdup("NOP");
    if (i == IN)    return strdup("IN");
    if (i == OUT)   return strdup("OUT");
    if (i == INB)   return strdup("INB");
    if (i == OUTB)  return strdup("OUTB");
    if (i == INC)   return strdup("INC");
    if (i == OUTC)  return strdup("OUTC");
    if (i == OUTNL) return strdup("OUTNL");
    if (i == ADD) return strdup("ADD");
    if (i == SUB) return strdup("SUB");
    if (i == MUL) return strdup("MUL");
    if (i == DIV) return strdup("DIV");
    if (i == AND) return strdup("AND");
    if (i == OR)  return strdup("OR");
    if (i == XOR) return strdup("XOR");
    if (i == NOT) return strdup("NOT");
    if (i == SWP) return strdup("SWP");
    if (i == RND) return strdup("RND");
    if (i == LDC) return strdup("LDC");
    if (i == LDA) return strdup("LDA");
    if (i == LD)  return strdup("LD");
    if (i == LDL) return strdup("LDL");
    if (i == LDI) return strdup("LDI");
    if (i == ST)  return strdup("ST");
    if (i == STI) return strdup("STI");
    if (i == JNZ) return strdup("JNZ");
    if (i == JZR) return strdup("JZR");
    if (i == TLT) return strdup("TLT");
    if (i == TLE) return strdup("TLE");
    if (i == TEQ) return strdup("TEQ");
    if (i == TNE) return strdup("TNE");
    if (i == TGE) return strdup("TGE");
    if (i == TGT) return strdup("TGT");
    if (i == MOV) return strdup("MOV");
    if (i == SET) return strdup("SET");
    if (i == CMP) return strdup("CMP");
    if (i == CPI) return strdup("CPI");
    printf("Unknown instruction in InstructionToStr()\n");
    return strdup("UNK");
}
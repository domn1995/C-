#ifndef EMITCODEH
#define EMITCODEH

#include <string>
//
//  Special register defines for optional use in calling the 
//  routines below.
//

enum Instruction
{
    HALT, NOP, IN, OUT, INB, OUTB, INC, OUTC, OUTNL,
    ADD, SUB, MUL, DIV, AND, OR, XOR, NOT, SWP, RND,
    LDC, LDA, LD, LDL, LDI, ST, STI, JNZ, JZR,
    TLT, TLE, TEQ, TNE, TGE, TGT, MOV, SET, CMP, CPI
};

#define GP   0	//  The global pointer
#define FP   1	//  The local frame pointer
#define RT   2	//  Return value
#define AC   3  //  Accumulator
#define AC1  4  //  Accumulator
#define AC2  5  //  Accumulator
#define AC3  6  //  Accumulator
#define PC   7	//  The program counter

//
//  No comment please...
//

#define NO_COMMENT (char *)""

//
//  We always trace the code
//
#define TraceCode   1

//
//  The following functions were borrowed from Tiny compiler code generator
//
int EmitSkip(int howMany);    // emitSkip(0) tells you where you are and reserves no space
void EmitBackup(int loc);

// Optional parameter indicates whether parens wrap the 't' register.
void EmitInstruction(Instruction i, int r, int s, int t, std::string c, bool parens = true);

void EmitComment(std::string str);
void EmitComment(char *c);
void EmitComment(char *c, char *cc);

void EmitEmptyLine();

void EmitGoto(int d, int s, char *c);
void EmitGoto(int d, int s, char *c, char *cc);
void EmitGotoAbs(int a, char *c);
void EmitGotoAbs(int a, char *c, char *cc);

void EmitRM(char *op, int r, int d, int s, char *c);
void EmitRM(char *op, int r, int d, int s, char *c, char *cc);
void EmitRMAbs(char *op, int r, int a, char *c);
void EmitRMAbs(char *op, int r, int a, char *c, char *cc);

void EmitRO(char *op, int r, int s, int t, char *c);
void EmitRO(char *op, int r, int s, int t, char *c, char *cc);

void BackPatchAJumpToHere(int addr, char *comment);
void BackPatchAJumpToHere(char *cmd, int reg, int addr, char *comment);

void EmitLit(char *s);

char* InstructionToStr(Instruction i);

#endif
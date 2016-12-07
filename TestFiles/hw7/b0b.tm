* C- compiler version C-F16
* Built: Nov 13, 2016
* Author: Robert B. Heckendorn
* File compiled:  b0b.c-
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION input
  1:     ST  3,-1(1)	Store return address 
  2:     IN  2,2,2	Grab int input 
  3:     LD  3,-1(1)	Load return address 
  4:     LD  1,0(1)	Adjust fp 
  5:    LDA  7,0(3)	Return 
* END FUNCTION input
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION output
  6:     ST  3,-1(1)	Store return address 
  7:     LD  3,-2(1)	Load parameter 
  8:    OUT  3,3,3	Output integer 
  9:    LDC  2,0(6)	Set return to 0 
 10:     LD  3,-1(1)	Load return address 
 11:     LD  1,0(1)	Adjust fp 
 12:    LDA  7,0(3)	Return 
* END FUNCTION output
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputb
 13:     ST  3,-1(1)	Store return address 
 14:    INB  2,2,2	Grab bool input 
 15:     LD  3,-1(1)	Load return address 
 16:     LD  1,0(1)	Adjust fp 
 17:    LDA  7,0(3)	Return 
* END FUNCTION inputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputb
 18:     ST  3,-1(1)	Store return address 
 19:     LD  3,-2(1)	Load parameter 
 20:   OUTB  3,3,3	Output bool 
 21:    LDC  2,0(6)	Set return to 0 
 22:     LD  3,-1(1)	Load return address 
 23:     LD  1,0(1)	Adjust fp 
 24:    LDA  7,0(3)	Return 
* END FUNCTION outputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputc
 25:     ST  3,-1(1)	Store return address 
 26:    INC  2,2,2	Grab char input 
 27:     LD  3,-1(1)	Load return address 
 28:     LD  1,0(1)	Adjust fp 
 29:    LDA  7,0(3)	Return 
* END FUNCTION inputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputc
 30:     ST  3,-1(1)	Store return address 
 31:     LD  3,-2(1)	Load parameter 
 32:   OUTC  3,3,3	Output char 
 33:    LDC  2,0(6)	Set return to 0 
 34:     LD  3,-1(1)	Load return address 
 35:     LD  1,0(1)	Adjust fp 
 36:    LDA  7,0(3)	Return 
* END FUNCTION outputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outnl
 37:     ST  3,-1(1)	Store return address 
 38:  OUTNL  3,3,3	Output a newline 
 39:     LD  3,-1(1)	Load return address 
 40:     LD  1,0(1)	Adjust fp 
 41:    LDA  7,0(3)	Return 
* END FUNCTION outnl
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION main
 42:     ST  3,-1(1)	Store return address. 
* COMPOUND
* Compound Body
* EXPRESSION
*                       Begin call to  outputb
 43:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
 44:    LDC  3,0(6)	Load Boolean constant 
 45:     ST  3,-4(1)	Save left side 
 46:    LDC  3,0(6)	Load Boolean constant 
 47:     LD  4,-4(1)	Load left into ac1 
 48:     OR  3,4,3	Op OR 
 49:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
 50:    LDA  1,-2(1)	Load address of new frame 
 51:    LDA  3,1(7)	Return address in ac 
 52:    LDA  7,-35(7)	CALL outputb
 53:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
 54:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
 55:    LDC  3,0(6)	Load Boolean constant 
 56:     ST  3,-4(1)	Save left side 
 57:    LDC  3,1(6)	Load Boolean constant 
 58:     LD  4,-4(1)	Load left into ac1 
 59:     OR  3,4,3	Op OR 
 60:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
 61:    LDA  1,-2(1)	Load address of new frame 
 62:    LDA  3,1(7)	Return address in ac 
 63:    LDA  7,-46(7)	CALL outputb
 64:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
 65:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
 66:    LDC  3,1(6)	Load Boolean constant 
 67:     ST  3,-4(1)	Save left side 
 68:    LDC  3,0(6)	Load Boolean constant 
 69:     LD  4,-4(1)	Load left into ac1 
 70:     OR  3,4,3	Op OR 
 71:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
 72:    LDA  1,-2(1)	Load address of new frame 
 73:    LDA  3,1(7)	Return address in ac 
 74:    LDA  7,-57(7)	CALL outputb
 75:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
 76:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
 77:    LDC  3,1(6)	Load Boolean constant 
 78:     ST  3,-4(1)	Save left side 
 79:    LDC  3,1(6)	Load Boolean constant 
 80:     LD  4,-4(1)	Load left into ac1 
 81:     OR  3,4,3	Op OR 
 82:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
 83:    LDA  1,-2(1)	Load address of new frame 
 84:    LDA  3,1(7)	Return address in ac 
 85:    LDA  7,-68(7)	CALL outputb
 86:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
 87:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
 88:    LDC  3,0(6)	Load Boolean constant 
 89:     ST  3,-4(1)	Save left side 
 90:    LDC  3,0(6)	Load Boolean constant 
 91:     LD  4,-4(1)	Load left into ac1 
 92:    AND  3,4,3	Op AND 
 93:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
 94:    LDA  1,-2(1)	Load address of new frame 
 95:    LDA  3,1(7)	Return address in ac 
 96:    LDA  7,-79(7)	CALL outputb
 97:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
 98:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
 99:    LDC  3,0(6)	Load Boolean constant 
100:     ST  3,-4(1)	Save left side 
101:    LDC  3,1(6)	Load Boolean constant 
102:     LD  4,-4(1)	Load left into ac1 
103:    AND  3,4,3	Op AND 
104:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
105:    LDA  1,-2(1)	Load address of new frame 
106:    LDA  3,1(7)	Return address in ac 
107:    LDA  7,-90(7)	CALL outputb
108:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
109:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
110:    LDC  3,1(6)	Load Boolean constant 
111:     ST  3,-4(1)	Save left side 
112:    LDC  3,0(6)	Load Boolean constant 
113:     LD  4,-4(1)	Load left into ac1 
114:    AND  3,4,3	Op AND 
115:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
116:    LDA  1,-2(1)	Load address of new frame 
117:    LDA  3,1(7)	Return address in ac 
118:    LDA  7,-101(7)	CALL outputb
119:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
120:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
121:    LDC  3,1(6)	Load Boolean constant 
122:     ST  3,-4(1)	Save left side 
123:    LDC  3,1(6)	Load Boolean constant 
124:     LD  4,-4(1)	Load left into ac1 
125:    AND  3,4,3	Op AND 
126:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
127:    LDA  1,-2(1)	Load address of new frame 
128:    LDA  3,1(7)	Return address in ac 
129:    LDA  7,-112(7)	CALL outputb
130:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
131:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
132:    LDC  3,0(6)	Load Boolean constant 
133:    LDC  4,1(6)	Load 1 
134:    XOR  3,3,4	Op NOT 
135:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
136:    LDA  1,-2(1)	Load address of new frame 
137:    LDA  3,1(7)	Return address in ac 
138:    LDA  7,-121(7)	CALL outputb
139:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outputb
140:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Load param 1
141:    LDC  3,1(6)	Load Boolean constant 
142:    LDC  4,1(6)	Load 1 
143:    XOR  3,3,4	Op NOT 
144:     ST  3,-4(1)	Store parameter 
*                       Jump to outputb
145:    LDA  1,-2(1)	Load address of new frame 
146:    LDA  3,1(7)	Return address in ac 
147:    LDA  7,-130(7)	CALL outputb
148:    LDA  3,0(2)	Save the result in ac 
*                       End call to outputb
* EXPRESSION
*                       Begin call to  outnl
149:     ST  1,-2(1)	Store old fp in ghost frame 
*                       Jump to outnl
150:    LDA  1,-2(1)	Load address of new frame 
151:    LDA  3,1(7)	Return address in ac 
152:    LDA  7,-116(7)	CALL outnl
153:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* END COMPOUND
* Add standard closing in case there is no return statement
154:    LDC  2,0(6)	Set return value to 0 
155:     LD  3,-1(1)	Load return address 
156:     LD  1,0(1)	Adjust fp 
157:    LDA  7,0(3)	Return 
* END FUNCTION main
  0:    LDA  7,157(7)	Jump to init [backpatch] 
* INIT
158:     LD  0,0(0)	Set the global pointer 
159:    LDA  1,0(0)	set first frame at end of globals 
160:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
161:    LDA  3,1(7)	Return address in ac 
162:    LDA  7,-121(7)	Jump to main 
163:   HALT  0,0,0	DONE! 
* END INIT

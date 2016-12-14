* C- compiler version C-F16
* Built: Dec 01, 2016
* Author: Domn Werner
* File compiled: TestFiles/hw7/arraysize.c-
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
* FUNCTION ford
 42:     ST  3,-1(1)	Store return address. 
* COMPOUND
* Compound Body
 43:    LDC  3,13(6)	load size of array y 
 44:     ST  3,-4(1)	save size of array y 
* EXPRESSION
 45:     LD  3,-5(1)	Load address of base of array y 
 46:     ST  3,-18(1)	Save left side 
 47:    LDC  3,0(6)	Load integer constant 
 48:     LD  4,-18(1)	Load left into ac1 
* EXPRESSION
 49:     LD  3,-1(0)	Load address of base of array g 
 50:     ST  3,-18(1)	Save left side 
 51:    LDC  3,0(6)	Load integer constant 
 52:     LD  4,-18(1)	Load left into ac1 
* EXPRESSION
*                       Begin call to  output
 53:     ST  1,-18(1)	Store old fp in ghost frame 
*                        Load param 
*                        Load param 
 54:     LD  3,-2(1)	Load address of base of array x 
 55:     ST  3,-20(1)	Store parameter 
 56:     ST  3,-21(1)	Save left side 
 57:    LDC  3,0(6)	Load integer constant 
 58:     LD  4,-21(1)	Load left into ac1 
 59:     ST  3,-21(1)	Store parameter 
*                       Jump to output
 60:    LDA  1,-18(1)	Load address of new frame 
 61:    LDA  3,1(7)	Return address in ac 
 62:    LDA  7,-57(7)	CALL output 
 63:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  output
 64:     ST  1,-18(1)	Store old fp in ghost frame 
*                        Load param 
*                        Load param 
 65:     LD  3,-2(1)	Load address of base of array x 
 66:     ST  3,-20(1)	Store parameter 
 67:     LD  3,1(3)	Load array size 
 68:     ST  3,-21(1)	Store parameter 
*                       Jump to output
 69:    LDA  1,-18(1)	Load address of new frame 
 70:    LDA  3,1(7)	Return address in ac 
 71:    LDA  7,-66(7)	CALL output 
 72:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  output
 73:     ST  1,-18(1)	Store old fp in ghost frame 
*                        Load param 
 74:     LD  3,-1(0)	Load address of base of array g 
 75:     ST  3,-20(1)	Save left side 
 76:    LDC  3,0(6)	Load integer constant 
 77:     LD  4,-20(1)	Load left into ac1 
 78:     ST  3,-20(1)	Store parameter 
*                       Jump to output
 79:    LDA  1,-18(1)	Load address of new frame 
 80:    LDA  3,1(7)	Return address in ac 
 81:    LDA  7,-76(7)	CALL output 
 82:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  output
 83:     ST  1,-18(1)	Store old fp in ghost frame 
*                        Load param 
 84:     LD  3,-1(0)	Load address of base of array g 
 85:     ST  3,-20(1)	Save left side 
 86:    LDC  3,-1(6)	Load integer constant 
 87:     LD  4,-20(1)	Load left into ac1 
 88:     ST  3,-20(1)	Store parameter 
*                       Jump to output
 89:    LDA  1,-18(1)	Load address of new frame 
 90:    LDA  3,1(7)	Return address in ac 
 91:    LDA  7,-86(7)	CALL output 
 92:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
 93:     ST  1,-18(1)	Store old fp in ghost frame 
*                       Jump to outnl
 94:    LDA  1,-18(1)	Load address of new frame 
 95:    LDA  3,1(7)	Return address in ac 
 96:    LDA  7,-60(7)	CALL outnl 
 97:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
*                       Begin call to  output
 98:     ST  1,-18(1)	Store old fp in ghost frame 
*                        Load param 
 99:     LD  3,-5(1)	Load address of base of array y 
100:     ST  3,-20(1)	Save left side 
101:    LDC  3,0(6)	Load integer constant 
102:     LD  4,-20(1)	Load left into ac1 
103:     ST  3,-20(1)	Store parameter 
*                       Jump to output
104:    LDA  1,-18(1)	Load address of new frame 
105:    LDA  3,1(7)	Return address in ac 
106:    LDA  7,-101(7)	CALL output 
107:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  output
108:     ST  1,-18(1)	Store old fp in ghost frame 
*                        Load param 
109:     LD  3,-5(1)	Load address of base of array y 
110:     LD  3,1(3)	Load array size 
111:     ST  3,-20(1)	Store parameter 
*                       Jump to output
112:    LDA  1,-18(1)	Load address of new frame 
113:    LDA  3,1(7)	Return address in ac 
114:    LDA  7,-109(7)	CALL output 
115:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
116:     ST  1,-18(1)	Store old fp in ghost frame 
*                       Jump to outnl
117:    LDA  1,-18(1)	Load address of new frame 
118:    LDA  3,1(7)	Return address in ac 
119:    LDA  7,-83(7)	CALL outnl 
120:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* END COMPOUND
* Add standard closing in case there is no return statement
121:    LDC  2,0(6)	Set return value to 0 
122:     LD  3,-1(1)	Load return address 
123:     LD  1,0(1)	Adjust fp 
124:    LDA  7,0(3)	Return 
* END FUNCTION ford
* FUNCTION main
125:     ST  3,-1(1)	Store return address. 
* COMPOUND
* Compound Body
126:    LDC  3,11(6)	load size of array m 
127:     ST  3,-2(1)	save size of array m 
* EXPRESSION
128:     LD  3,-3(1)	Load address of base of array m 
129:     ST  3,-14(1)	Save left side 
130:    LDC  3,0(6)	Load integer constant 
131:     LD  4,-14(1)	Load left into ac1 
* EXPRESSION
*                       Begin call to  output
132:     ST  1,-14(1)	Store old fp in ghost frame 
*                        Load param 
133:     LD  3,-3(1)	Load address of base of array m 
134:     ST  3,-16(1)	Save left side 
135:    LDC  3,0(6)	Load integer constant 
136:     LD  4,-16(1)	Load left into ac1 
137:     ST  3,-16(1)	Store parameter 
*                       Jump to output
138:    LDA  1,-14(1)	Load address of new frame 
139:    LDA  3,1(7)	Return address in ac 
140:    LDA  7,-135(7)	CALL output 
141:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  output
142:     ST  1,-14(1)	Store old fp in ghost frame 
*                        Load param 
143:     LD  3,-3(1)	Load address of base of array m 
144:     LD  3,1(3)	Load array size 
145:     ST  3,-16(1)	Store parameter 
*                       Jump to output
146:    LDA  1,-14(1)	Load address of new frame 
147:    LDA  3,1(7)	Return address in ac 
148:    LDA  7,-143(7)	CALL output 
149:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  output
150:     ST  1,-14(1)	Store old fp in ghost frame 
*                        Load param 
151:     LD  3,-1(0)	Load address of base of array g 
152:     ST  3,-16(1)	Save left side 
153:    LDC  3,0(6)	Load integer constant 
154:     LD  4,-16(1)	Load left into ac1 
155:     ST  3,-16(1)	Store parameter 
*                       Jump to output
156:    LDA  1,-14(1)	Load address of new frame 
157:    LDA  3,1(7)	Return address in ac 
158:    LDA  7,-153(7)	CALL output 
159:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  output
160:     ST  1,-14(1)	Store old fp in ghost frame 
*                        Load param 
161:     LD  3,-1(0)	Load address of base of array g 
162:     LD  3,1(3)	Load array size 
163:     ST  3,-16(1)	Store parameter 
*                       Jump to output
164:    LDA  1,-14(1)	Load address of new frame 
165:    LDA  3,1(7)	Return address in ac 
166:    LDA  7,-161(7)	CALL output 
167:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
168:     ST  1,-14(1)	Store old fp in ghost frame 
*                       Jump to outnl
169:    LDA  1,-14(1)	Load address of new frame 
170:    LDA  3,1(7)	Return address in ac 
171:    LDA  7,-135(7)	CALL outnl 
172:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
*                       Begin call to  ford
173:     ST  1,-14(1)	Store old fp in ghost frame 
*                        Load param 
174:     LD  3,-3(1)	Load address of base of array m 
175:     ST  3,-16(1)	Store parameter 
*                       Jump to ford
176:    LDA  1,-14(1)	Load address of new frame 
177:    LDA  3,1(7)	Return address in ac 
178:    LDA  7,-137(7)	CALL ford 
179:    LDA  3,0(2)	Save the result in ac 
*                       End call to ford
* EXPRESSION
*                       Begin call to  ford
180:     ST  1,-14(1)	Store old fp in ghost frame 
*                        Load param 
181:     LD  3,-1(0)	Load address of base of array g 
182:     ST  3,-16(1)	Store parameter 
*                       Jump to ford
183:    LDA  1,-14(1)	Load address of new frame 
184:    LDA  3,1(7)	Return address in ac 
185:    LDA  7,-144(7)	CALL ford 
186:    LDA  3,0(2)	Save the result in ac 
*                       End call to ford
* EXPRESSION
*                       Begin call to  output
187:     ST  1,-14(1)	Store old fp in ghost frame 
*                        Load param 
188:     LD  3,-3(1)	Load address of base of array m 
189:     LD  3,1(3)	Load array size 
190:     ST  3,-16(1)	Save left side 
191:     LD  3,-1(0)	Load address of base of array g 
192:     LD  3,1(3)	Load array size 
193:     LD  4,-16(1)	Load left into ac1 
194:    MUL  3,4(3)	Op * 
195:     ST  3,-16(1)	Store parameter 
*                       Jump to output
196:    LDA  1,-14(1)	Load address of new frame 
197:    LDA  3,1(7)	Return address in ac 
198:    LDA  7,-193(7)	CALL output 
199:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
200:     ST  1,-14(1)	Store old fp in ghost frame 
*                       Jump to outnl
201:    LDA  1,-14(1)	Load address of new frame 
202:    LDA  3,1(7)	Return address in ac 
203:    LDA  7,-167(7)	CALL outnl 
204:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* END COMPOUND
* Add standard closing in case there is no return statement
205:    LDC  2,0(6)	Set return value to 0 
206:     LD  3,-1(1)	Load return address 
207:     LD  1,0(1)	Adjust fp 
208:    LDA  7,0(3)	Return 
* END FUNCTION main
  0:    LDA  7,208(7)	Jump to init [backpatch] 
* INIT
209:     LD  0,0(0)	Set the global pointer 
210:    LDA  1,-37(0)	set first frame at end of globals 
211:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
212:    LDC  3,12(6)	load size of array g 
213:     ST  3,0(0)	save size of array g 
214:    LDC  3,23(6)	load size of array h 
215:     ST  3,-13(0)	save size of array h 
* END INIT GLOBALS AND STATICS
216:    LDA  3,1(7)	Return address in ac 
217:    LDA  7,-93(7)	Jump to main 
218:   HALT  0,0,0	DONE! 
* END INIT

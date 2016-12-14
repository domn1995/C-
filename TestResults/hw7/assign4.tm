* C- compiler version C-F16
* Built: Dec 01, 2016
* Author: Domn Werner
* File compiled: TestFiles/hw7/assign4.c-
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
 43:     LD  4,-2(1)	load lhs variable x 
 44:    ADD  3,4(3)	op += 
 45:     ST  3,-2(1)	Store variable x 
* EXPRESSION
*                       Begin call to  output
 46:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
 47:     LD  3,-2(1)	Load variable x 
 48:     ST  3,-6(1)	Store parameter 
*                       Jump to output
 49:    LDA  1,-4(1)	Load address of new frame 
 50:    LDA  3,1(7)	Return address in ac 
 51:    LDA  7,-46(7)	CALL output 
 52:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
 53:     LD  4,-3(1)	load lhs variable y 
 54:    ADD  3,4(3)	op += 
 55:     ST  3,-3(1)	Store variable y 
* EXPRESSION
*                       Begin call to  output
 56:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
 57:     LD  3,-3(1)	Load variable y 
 58:     ST  3,-6(1)	Store parameter 
*                       Jump to output
 59:    LDA  1,-4(1)	Load address of new frame 
 60:    LDA  3,1(7)	Return address in ac 
 61:    LDA  7,-56(7)	CALL output 
 62:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
 63:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
 64:    LDA  1,-4(1)	Load address of new frame 
 65:    LDA  3,1(7)	Return address in ac 
 66:    LDA  7,-30(7)	CALL outnl 
 67:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
 68:     LD  4,0(0)	load lhs variable gx 
 69:    ADD  3,4(3)	op += 
 70:     ST  3,0(0)	Store variable gx 
* EXPRESSION
*                       Begin call to  output
 71:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
 72:     LD  3,0(0)	Load variable gx 
 73:     ST  3,-6(1)	Store parameter 
*                       Jump to output
 74:    LDA  1,-4(1)	Load address of new frame 
 75:    LDA  3,1(7)	Return address in ac 
 76:    LDA  7,-71(7)	CALL output 
 77:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
 78:     LD  4,-1(0)	load lhs variable gy 
 79:    ADD  3,4(3)	op += 
 80:     ST  3,-1(0)	Store variable gy 
* EXPRESSION
*                       Begin call to  output
 81:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
 82:     LD  3,-1(0)	Load variable gy 
 83:     ST  3,-6(1)	Store parameter 
*                       Jump to output
 84:    LDA  1,-4(1)	Load address of new frame 
 85:    LDA  3,1(7)	Return address in ac 
 86:    LDA  7,-81(7)	CALL output 
 87:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
 88:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
 89:    LDA  1,-4(1)	Load address of new frame 
 90:    LDA  3,1(7)	Return address in ac 
 91:    LDA  7,-55(7)	CALL outnl 
 92:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
 93:     LD  4,-2(1)	load lhs variable x 
 94:    ADD  3,4(3)	op += 
 95:     ST  3,-2(1)	Store variable x 
* EXPRESSION
*                       Begin call to  output
 96:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
 97:     LD  3,-2(1)	Load variable x 
 98:     ST  3,-6(1)	Store parameter 
*                       Jump to output
 99:    LDA  1,-4(1)	Load address of new frame 
100:    LDA  3,1(7)	Return address in ac 
101:    LDA  7,-96(7)	CALL output 
102:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
103:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
104:    LDA  1,-4(1)	Load address of new frame 
105:    LDA  3,1(7)	Return address in ac 
106:    LDA  7,-70(7)	CALL outnl 
107:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
108:     LD  4,0(0)	load lhs variable gx 
109:    ADD  3,4(3)	op += 
110:     ST  3,0(0)	Store variable gx 
* EXPRESSION
*                       Begin call to  output
111:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
112:     LD  3,0(0)	Load variable gx 
113:     ST  3,-6(1)	Store parameter 
*                       Jump to output
114:    LDA  1,-4(1)	Load address of new frame 
115:    LDA  3,1(7)	Return address in ac 
116:    LDA  7,-111(7)	CALL output 
117:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
118:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
119:    LDA  1,-4(1)	Load address of new frame 
120:    LDA  3,1(7)	Return address in ac 
121:    LDA  7,-85(7)	CALL outnl 
122:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
123:     LD  4,-2(1)	load lhs variable x 
124:    SUB  3,4(3)	op -= 
125:     ST  3,-2(1)	Store variable x 
* EXPRESSION
*                       Begin call to  output
126:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
127:     LD  3,-2(1)	Load variable x 
128:     ST  3,-6(1)	Store parameter 
*                       Jump to output
129:    LDA  1,-4(1)	Load address of new frame 
130:    LDA  3,1(7)	Return address in ac 
131:    LDA  7,-126(7)	CALL output 
132:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
133:     LD  4,-3(1)	load lhs variable y 
134:    SUB  3,4(3)	op -= 
135:     ST  3,-3(1)	Store variable y 
* EXPRESSION
*                       Begin call to  output
136:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
137:     LD  3,-3(1)	Load variable y 
138:     ST  3,-6(1)	Store parameter 
*                       Jump to output
139:    LDA  1,-4(1)	Load address of new frame 
140:    LDA  3,1(7)	Return address in ac 
141:    LDA  7,-136(7)	CALL output 
142:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
143:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
144:    LDA  1,-4(1)	Load address of new frame 
145:    LDA  3,1(7)	Return address in ac 
146:    LDA  7,-110(7)	CALL outnl 
147:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
148:     LD  4,0(0)	load lhs variable gx 
149:    SUB  3,4(3)	op -= 
150:     ST  3,0(0)	Store variable gx 
* EXPRESSION
*                       Begin call to  output
151:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
152:     LD  3,0(0)	Load variable gx 
153:     ST  3,-6(1)	Store parameter 
*                       Jump to output
154:    LDA  1,-4(1)	Load address of new frame 
155:    LDA  3,1(7)	Return address in ac 
156:    LDA  7,-151(7)	CALL output 
157:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
158:     LD  4,-1(0)	load lhs variable gy 
159:    SUB  3,4(3)	op -= 
160:     ST  3,-1(0)	Store variable gy 
* EXPRESSION
*                       Begin call to  output
161:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
162:     LD  3,-1(0)	Load variable gy 
163:     ST  3,-6(1)	Store parameter 
*                       Jump to output
164:    LDA  1,-4(1)	Load address of new frame 
165:    LDA  3,1(7)	Return address in ac 
166:    LDA  7,-161(7)	CALL output 
167:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
168:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
169:    LDA  1,-4(1)	Load address of new frame 
170:    LDA  3,1(7)	Return address in ac 
171:    LDA  7,-135(7)	CALL outnl 
172:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
173:     LD  4,-2(1)	load lhs variable x 
174:    SUB  3,4(3)	op -= 
175:     ST  3,-2(1)	Store variable x 
* EXPRESSION
*                       Begin call to  output
176:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
177:     LD  3,-2(1)	Load variable x 
178:     ST  3,-6(1)	Store parameter 
*                       Jump to output
179:    LDA  1,-4(1)	Load address of new frame 
180:    LDA  3,1(7)	Return address in ac 
181:    LDA  7,-176(7)	CALL output 
182:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
183:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
184:    LDA  1,-4(1)	Load address of new frame 
185:    LDA  3,1(7)	Return address in ac 
186:    LDA  7,-150(7)	CALL outnl 
187:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* EXPRESSION
188:     LD  4,0(0)	load lhs variable gx 
189:    SUB  3,4(3)	op -= 
190:     ST  3,0(0)	Store variable gx 
* EXPRESSION
*                       Begin call to  output
191:     ST  1,-4(1)	Store old fp in ghost frame 
*                        Load param 
192:     LD  3,0(0)	Load variable gx 
193:     ST  3,-6(1)	Store parameter 
*                       Jump to output
194:    LDA  1,-4(1)	Load address of new frame 
195:    LDA  3,1(7)	Return address in ac 
196:    LDA  7,-191(7)	CALL output 
197:    LDA  3,0(2)	Save the result in ac 
*                       End call to output
* EXPRESSION
*                       Begin call to  outnl
198:     ST  1,-4(1)	Store old fp in ghost frame 
*                       Jump to outnl
199:    LDA  1,-4(1)	Load address of new frame 
200:    LDA  3,1(7)	Return address in ac 
201:    LDA  7,-165(7)	CALL outnl 
202:    LDA  3,0(2)	Save the result in ac 
*                       End call to outnl
* RETURN
203:     LD  3,-1(1)	Load return address 
204:     LD  1,0(1)	Adjust fp 
205:    LDA  7,0(3)	Return 
* END COMPOUND
* Add standard closing in case there is no return statement
206:    LDC  2,0(6)	Set return value to 0 
207:     LD  3,-1(1)	Load return address 
208:     LD  1,0(1)	Adjust fp 
209:    LDA  7,0(3)	Return 
* END FUNCTION main
  0:    LDA  7,209(7)	Jump to init [backpatch] 
* INIT
210:     LD  0,0(0)	Set the global pointer 
211:    LDA  1,-2(0)	set first frame at end of globals 
212:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
213:    LDA  3,1(7)	Return address in ac 
214:    LDA  7,-173(7)	Jump to main 
215:   HALT  0,0,0	DONE! 
* END INIT

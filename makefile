BIN  = c-
CC   = g++
SRCS = $(BIN).y $(BIN).l Token.h SymbolTable.h SymbolTable.cpp TreeNode.h TreeNode.cpp 
OBJS = lex.yy.o $(BIN).tab.o SymbolTable.o TreeNode.o
CCFLAGS = -s
LIBS = -lm 

$(BIN): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o $(BIN)
	
SymbolTable.o: SymbolTable.h SymbolTable.cpp 
	$(CC) $(CCFLAGS) SymbolTable.cpp -c

TreeNode.o: TreeNode.h TreeNode.cpp
	$(CC) $(CCFLAGS) TreeNode.cpp -c
	
$(BIN).tab.h $(BIN).tab.c: $(BIN).y SymbolTable.o TreeNode.o
	bison -v -t -d $(BIN).y   # -d supplies defines file, -v supplies output

lex.yy.c: $(BIN).l $(BIN).tab.h SymbolTable.o
	flex $(BIN).l # --debug

all:    
	touch $(SRCS)
	make

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).tar *~ *.output

tar:
	tar -cvf $(BIN).tar $(SRCS) makefile 
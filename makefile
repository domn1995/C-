BIN  = c-
CC   = g++
SRCS = $(BIN).y $(BIN).l Token.h SymbolTable.h SymbolTable.cpp TreeNode.h TreeNode.cpp PrintTree.h PrintTree.cpp Semantic.h Semantic.cpp Utils.h Utils.cpp YyError.h YyError.cpp
OBJS = lex.yy.o $(BIN).tab.o SymbolTable.o TreeNode.o PrintTree.o Semantic.o Utils.o YyError.o
CCFLAGS = -ggdb -g -Wno-write-strings
LIBS = -lm 

$(BIN): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o $(BIN)

YyError.o: YyError.h YyError.cpp
	$(CC) $(CCFLAGS) YyError.cpp -c

Utils.o: Utils.h Utils.cpp
	$(CC) $(CCFLAGS) Utils.cpp -c
	
SymbolTable.o: SymbolTable.h SymbolTable.cpp 
	$(CC) $(CCFLAGS) SymbolTable.cpp -c

TreeNode.o: TreeNode.h TreeNode.cpp
	$(CC) $(CCFLAGS) TreeNode.cpp -c
	
PrintTree.o: PrintTree.h TreeNode.h PrintTree.cpp
	$(CC) $(CCFlags) PrintTree.cpp -c
	
Semantic.o: Semantic.h Semantic.cpp SymbolTable.cpp Utils.h Utils.cpp
	$(CC) $(CCFlags) Semantic.cpp -c
	
$(BIN).tab.h $(BIN).tab.c: $(BIN).y SymbolTable.o TreeNode.o YyError.o
	bison -v -t -d $(BIN).y   # -d supplies defines file, -v supplies output

lex.yy.c: $(BIN).l $(BIN).tab.h SymbolTable.o YyError.o TreeNode.o
	flex $(BIN).l # --debug

all:    
	touch $(SRCS)
	make

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).tar *~ *.output

tar:
	tar -cvf $(BIN).tar $(SRCS) makefile 
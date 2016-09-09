BIN  = c-
CC   = g++
SRCS = $(BIN).y $(BIN).l Token.h
OBJS = lex.yy.o $(BIN).tab.o 
LIBS = -lm 

$(BIN): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o $(BIN)
	
$(BIN).tab.h $(BIN).tab.c: $(BIN).y
	bison -v -t -d $(BIN).y   # -d supplies defines file, -v supplies output

lex.yy.c: $(BIN).l $(BIN).tab.h
	flex $(BIN).l # --debug

all:    
	touch $(SRCS)
	make

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).tar *~ *.output

tar:
	tar -cvf $(BIN).tar $(SRCS) makefile 
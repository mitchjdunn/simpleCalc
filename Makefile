EXE	= simpleCalc #variable for the executable
SRCS 	= $(shell find . -type f -name '*.c')
OBJS 	= $(patsubst %.c,%.o, $(SRCS)) # check syntax
CFLAGS 	= 

debug: CFLAGS += -g
debug: $(EXE)

$(EXE): $(OBJS) # Dependency oject -- compiling objects individually is quicker than all at once?
	$(CC) $(CFLAGS) -O0 -o $@ $^ # make with automagically compile .c's into .o's
clean: 
	rm $(EXE) $(OBJS)

.PHONY: clean

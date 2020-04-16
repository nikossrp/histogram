OBJS = demo.o bst-implementation.o item-implementation.o
EXEC = main
CFLAGS = -g -Wall
CC = gcc
ARGC = 10 0	

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGC)

clean: 
	rm -f $(OBJS) $(EXEC)


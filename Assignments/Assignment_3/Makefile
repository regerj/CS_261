CC=gcc --std=c99 -g

all: test unittest

unittest: unittest.c stack.o queue.o stack_from_queues.o queue_from_stacks.o list_reverse.o
	$(CC) unittest.c stack.o queue.o stack_from_queues.o queue_from_stacks.o list_reverse.o -o unittest

test: test.c stack.o queue.o stack_from_queues.o queue_from_stacks.o list_reverse.o
	$(CC) test.c stack.o queue.o stack_from_queues.o queue_from_stacks.o list_reverse.o -o test

stack.o: stack.c stack.h node.h
	$(CC) -c stack.c -o stack.o

queue.o: queue.c queue.h node.h
	$(CC) -c queue.c -o queue.o

stack_from_queues.o: stack_from_queues.c stack_from_queues.h queue.h
	$(CC) -c stack_from_queues.c -o stack_from_queues.o

queue_from_stacks.o: queue_from_stacks.c queue_from_stacks.h stack.h
	$(CC) -c queue_from_stacks.c -o queue_from_stacks.o

list_reverse.o: list_reverse.c list_reverse.h node.h
	$(CC) -c list_reverse.c -o list_reverse.o

clean:
	rm -rf *.dSYM/
	rm -f *.o test unittest

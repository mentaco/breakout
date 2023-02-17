CC = g++
LIBS = -lncurses
OBJS = main.o paddle.o controller.o

all: $(OBJS)
	$(CC) $(OBJS) $(LIBS)

clean:; rm -f *.o a.out

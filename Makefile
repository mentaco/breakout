CXX = g++-12
PROGRAM = breakout
INCDIR = -I./
LIBS = -lncurses
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(PROGRAM): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(INCDIR) -c $<

all: clean $(PROGRAM) 

clean:; rm -f $(OBJS) $(PROGRAM)

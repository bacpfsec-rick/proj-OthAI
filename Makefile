CFLAGS = -I -c -Wall
LIBDIR =
LNFLAGS =
OBJECTS1 = Cord.o Othello.o HM.o HMvsHM.o
OBJECTS2 = Cord.o Othello.o HM.o AI.o TestAI.o

all:   HMvsHM TestAI

HMvsHM: $(OBJECTS1)
	g++ -std=c++0x -o $@ $^

TestAI: $(OBJECTS2)
	g++ -std=c++0x -o $@ $^

	rm -rf *o *~

#	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)  

%.o : %.cc
	g++ -std=c++0x $(CFLAGS) -c $^

clean:
	rm -rf *o *~
	rm HMvsHM
	rm TestAI

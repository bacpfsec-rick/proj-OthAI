CFLAGS = -I -c -Wall
LIBDIR =
LNFLAGS =
OBJECTS1 = Cord.o Othello.o HM.o HMvsHM.o
OBJECTS2 = Cord.o Othello.o HM.o AI.o HMvsAI.o
OBJECTS3 = Cord.o Othello.o AI.o AIvsAI.o
OBJECTS4 = Cord.o Othello.o AI.o Learning.o

all:   HMvsHM HMvsAI AIvsAI Learning

HMvsHM: $(OBJECTS1)
	g++ -std=c++0x -o $@ $^

HMvsAI: $(OBJECTS2)
	g++ -std=c++0x -o $@ $^

AIvsAI: $(OBJECTS3)
	g++ -std=c++0x -o $@ $^

Learning: $(OBJECTS4)
	g++ -std=c++0x -o $@ $^
	rm -rf *o *~

#	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)  

%.o : %.cc
	g++ -std=c++0x $(CFLAGS) -c $^

clean:
	rm -rf *o *~
	rm HMvsHM
	rm HMvsAI
	rm AIvsAI
	rm Learning

CFLAGS = -I -c -Wall
LIBDIR =
LNFLAGS =
#OBJECTS1 = Cord.o Othello.o HM.o HMvsHM.o
OBJECTS1 = Cord.o Othello.o HM.o AI.o TestAI.o

#all:   HMvsHM
all: 	AItest

#HMvsHM: $(OBJECTS1)
AItest: $(OBJECTS1)
	g++ -std=c++0x -o $@ $^
	rm -rf *o *~

#	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)  

%.o : %.cc
	g++ -std=c++0x $(CFLAGS) -c $^

clean:
	rm -rf *o *~
	rm HMvsHM

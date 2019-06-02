CFLAGS = -Wall -lm -std=c99 -g

default: unittest1 unittest2
	
unittest1: unittest1.c dominion.c rngs.c playSmithyRefactor.c
	gcc -o unittest1 unittest1.c dominion.c rngs.c playSmithyRefactor.c $(CFLAGS)

unittest2: unittest2.c dominion.c rngs.c playAdventurerRefactor.c
	gcc -o unittest2 unittest2.c dominion.c rngs.c playAdventurerRefactor.c $(CFLAGS)

cleanall: 
	rm unittest1 unittest2


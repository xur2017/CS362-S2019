CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

unittestresults.out: dominion.c rngs.c playSmithyRefactor.c playAdventurerRefactor.c
	echo " " > unittestresults.out
		
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c playSmithyRefactor.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov playSmithyRefactor.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c playAdventurerRefactor.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov playAdventurerRefactor.c >> unittestresults.out
		
cleanall: 
	rm *.gcda *.gcno *.gcov unittest1 unittest2 unittestresults.out


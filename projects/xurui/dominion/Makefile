CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestresults.out

randomtestresults.out: dominion.c rngs.c playSmithyRefactor.c playAdventurerRefactor.c playVillageRefactor.c
	echo " " > randomtestresults.out
		
	echo "randomtestadventurer.c:" >> randomtestresults.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c playAdventurerRefactor.c $(CFLAGS)
	./randomtestadventurer >> randomtestresults.out
	gcov playAdventurerRefactor.c >> randomtestresults.out
	
	echo "randomtestcard1.c:" >> randomtestresults.out
	gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c playSmithyRefactor.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov playSmithyRefactor.c >> randomtestresults.out
	
	echo "randomtestcard2.c:" >> randomtestresults.out
	gcc -o randomtestcard2 randomtestcard2.c dominion.c rngs.c playVillageRefactor.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov playVillageRefactor.c >> randomtestresults.out
	
cleanall: 
	rm *.gcda *.gcno *.gcov randomtestresults.out randomtestadventurer randomtestcard1 randomtestcard2


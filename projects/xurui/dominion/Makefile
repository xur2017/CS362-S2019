CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

unittestresults.out: dominion.c rngs.c playSmithy.c playAdventurer.c playVillage.c playCouncilRoom.c playSmithyRefactor.c playAdventurerRefactor.c playVillageRefactor.c playCouncilRoomRefactor.c
	echo " " > unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c playSmithy.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov playSmithy.c >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.c rngs.c playAdventurer.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov playAdventurer.c >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.c rngs.c playVillage.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov playVillage.c >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c dominion.c rngs.c playCouncilRoom.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov playCouncilRoom.c >> unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c playSmithyRefactor.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov playSmithyRefactor.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c playAdventurerRefactor.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov playAdventurerRefactor.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c playVillageRefactor.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov playVillageRefactor.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c playCouncilRoomRefactor.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov playCouncilRoomRefactor.c >> unittestresults.out
	
cleanall: 
	rm *.gcda *.gcno *.gcov cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4


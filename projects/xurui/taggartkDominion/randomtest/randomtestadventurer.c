#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playAdventurerRefactor.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	int retVal;
		
	printf("** randomtestadventurer begin **\n");

	initializeGame(numPlayers, k, seed, &G);
	
	srand(time(0));
	int j;
	int check = 1;
	
	while(check)
	{
		for(int i=0; i<5; i++)
		{
			j = rand()%100;
			if(j<10)
			{
				G.deck[thisPlayer][i] = 6;
			}
			if(10<=j && j<55)
			{
				G.deck[thisPlayer][i] = 4;
			}
			if(55<=j && j<100)
			{
				G.deck[thisPlayer][i] = 5;
			}
		}
		
		memcpy(&testG, &G, sizeof(struct gameState));
		retVal = playAdventurerRefactor(&testG);
		
		for(int i=0; i<G.deckCount[thisPlayer]; i++)
		{
			printf("%d ", G.deck[thisPlayer][i]);
		}
		printf("\n");
		
		printf("handCount: before = %d, after = %d\n", G.handCount[thisPlayer], testG.handCount[thisPlayer]);
		assert1(G.handCount[thisPlayer]+2==testG.handCount[thisPlayer]);
	
		printf("deckCount: before = %d, after = %d\n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer]);
		assert1(G.deckCount[thisPlayer]-2==testG.deckCount[thisPlayer]);
		
		printf("returned value: retVal = %d\n", retVal);
		assert1(retVal==0);
		printf("\n");
		
		for(int i=0; i<testG.discardCount[thisPlayer]; i++)
		{
			if(testG.discard[thisPlayer][i] == 6)
			{
				printf("At least a gold card is revealed and discarded. Iterations end.\n");
				check = 0;
				break;
			}
		}
	}

	printf("** randomtestadventurer end **\n");
	
	return 0;
}
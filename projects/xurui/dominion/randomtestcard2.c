#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playVillageRefactor.h"
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
		
	printf("** randomtestcard2 begin **\n");

	initializeGame(numPlayers, k, seed, &G);
	
	srand(time(0));
	int n;
	
	//printf("%d \n", G.deckCount[thisPlayer]);
	//printf("%d \n", G.handCount[thisPlayer]);
	
	//memcpy(&testG, &G, sizeof(struct gameState));
	//retVal = playSmithyRefactor(&testG, 0);
	
	
	for(int i=0; i<10; i++)
	{
		printf("iteration %d:  ", i);
		printf("\n");
		for(int j=0; j<5; j++)
		{
			n = 1+rand()%6;
			G.deck[thisPlayer][j] = n;
			
			n = 1+rand()%6;
			G.hand[thisPlayer][j] = n;
		}
		
		printf("deck cards (before):  ");
		for(int i = 0; i<G.deckCount[thisPlayer]; i++)
		{
			printf("%d  ", G.deck[thisPlayer][i]);
		}
		printf("\n");
		printf("hand cards (before):  ");
		for(int i = 0; i<G.handCount[thisPlayer]; i++)
		{
			printf("%d  ", G.hand[thisPlayer][i]);
		}
		printf("\n");
		
		memcpy(&testG, &G, sizeof(struct gameState));
		retVal = playVillageRefactor(&testG, 0);
		
		printf("deck cards ( after):  ");
		for(int i = 0; i<testG.deckCount[thisPlayer]; i++)
		{
			printf("%d  ", testG.deck[thisPlayer][i]);
		}
		printf("\n");
		printf("hand cards ( after):  ");
		for(int i = 0; i<testG.handCount[thisPlayer]; i++)
		{
			printf("%d  ", testG.hand[thisPlayer][i]);
		}
		printf("\n");
		
		printf("played cards:  ");
		for(int i = 0; i<testG.playedCardCount; i++)
		{
			printf("%d  ", testG.playedCards[i]);
		}
		printf("\n");
				
		printf("handCount: before = %d, after = %d\n", G.handCount[thisPlayer], testG.handCount[thisPlayer]);
		assert1(G.handCount[thisPlayer]==testG.handCount[thisPlayer]);
	
		printf("deckCount: before = %d, after = %d\n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer]);
		assert1(G.deckCount[thisPlayer]-1==testG.deckCount[thisPlayer]);
	
		printf("numActions: before = %d, after = %d\n", G.numActions, testG.numActions);
		assert1(G.numActions+2==testG.numActions);
		
		printf("playedCardCount: before = %d, after = %d\n", G.playedCardCount, testG.playedCardCount);
		assert1(G.playedCardCount==testG.playedCardCount);
	
		printf("returned value: retVal = %d\n", retVal);
		assert1(retVal==0);
		
		printf("\n");
	}
	
	printf("** randomtestcard2 end **\n");
	
	return 0;
}
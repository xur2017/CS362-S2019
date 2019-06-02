#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playSmithyRefactor.h"
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
		
	printf("** randomtestcard1 begin **\n");

	initializeGame(numPlayers, k, seed, &G);
	
	srand(time(0));
	int n;
		
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
		retVal = playSmithyRefactor(&testG, 0);
		
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
		assert1(G.handCount[thisPlayer]+1==testG.handCount[thisPlayer]);
	
		printf("deckCount: before = %d, after = %d\n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer]);
		assert1(G.deckCount[thisPlayer]-2==testG.deckCount[thisPlayer]);
	
		printf("playedCardCount: before = %d, after = %d\n", G.playedCardCount, testG.playedCardCount);
		assert1(G.playedCardCount+1==testG.playedCardCount);
	
		printf("returned value: retVal = %d\n", retVal);
		assert1(retVal==0);
		
		printf("\n");
	}
	
	printf("** randomtestcard1 end **\n");
	
	return 0;
}
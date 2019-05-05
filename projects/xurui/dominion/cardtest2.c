#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playAdventurer.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	int retVal;
	
	printf("** cardtest2 begin **\n");

	initializeGame(numPlayers, k, seed, &G);
	G.deck[thisPlayer][4] = 5;
	printf("initial deck cards:  ");
	for(int i = 0; i<G.deckCount[thisPlayer]; i++)
	{
		printf("%d  ", G.deck[thisPlayer][i]);
	}
	printf("\n");
	printf("initial hand cards:  ");
	for(int i = 0; i<G.handCount[thisPlayer]; i++)
	{
		printf("%d  ", G.hand[thisPlayer][i]);
	}
	printf("\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));
	retVal = playAdventurer(&testG);
	printf("present deck cards:  ");
	for(int i = 0; i<testG.deckCount[thisPlayer]; i++)
	{
		printf("%d  ", testG.deck[thisPlayer][i]);
	}
	printf("\n");
	printf("present hand cards:  ");
	for(int i = 0; i<testG.handCount[thisPlayer]; i++)
	{
		printf("%d  ", testG.hand[thisPlayer][i]);
	}
	printf("\n");
	
	printf("handCount: before = %d, after = %d\n", G.handCount[thisPlayer], testG.handCount[thisPlayer]);
	assert1(G.handCount[thisPlayer]+2==testG.handCount[thisPlayer]);
	
	printf("deckCount: before = %d, after = %d\n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer]);
	assert1(G.deckCount[thisPlayer]-2==testG.deckCount[thisPlayer]);
	
	printf("discardCount: before = %d, after = %d\n", G.discardCount[thisPlayer], testG.discardCount[thisPlayer]);
	assert1(G.discardCount[thisPlayer]==testG.discardCount[thisPlayer]);
	
	printf("playedCardCount: before = %d, after = %d\n", G.playedCardCount, testG.playedCardCount);
	assert1(G.playedCardCount==testG.playedCardCount);
	
	printf("returned value: retVal = %d\n", retVal);
	assert1(retVal==0);
	
	printf("** cardtest2 end **\n");
	
	return 0;
}
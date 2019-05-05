#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playVillage.h"

int playVillage(struct gameState *state, int handPos)
{
	
	int currentPlayer = whoseTurn(state);
	
	//+1 Card
    drawCard(currentPlayer, state);
			
    //+2 Actions
    state->numActions = state->numActions + 2;
			
    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}
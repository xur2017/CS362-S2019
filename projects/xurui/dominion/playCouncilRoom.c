#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playCouncilRoom.h"

int playCouncilRoom(struct gameState *state, int handPos)
{	
	int i;
	int size = 4;
	int currentPlayer = whoseTurn(state);
	
	//+4 Cards
    for (i = 0; i < size; i++)
	{
		drawCard(currentPlayer, state);
	}
			
    //+1 Buy
    state->numBuys++;
			
    //Each other player draws a card
    for (i = 0; i < state->numPlayers; i++)
	{
		if ( i != currentPlayer )
	    {
			drawCard(i, state);
	    }
	}
			
    //put played card in played card pile
    discardCard(handPos, currentPlayer, state, 0);
			
    return 0;	
}
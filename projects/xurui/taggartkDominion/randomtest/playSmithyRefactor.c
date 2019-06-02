#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playSmithyRefactor.h"

int playSmithyRefactor(struct gameState *state, int handPos)
{	
	int currentPlayer = whoseTurn(state);
	int i;
	int size = 3;
	
    //+3 Cards
    for (i = 0; i < size; i++)
	{
		drawCard(currentPlayer, state);
	}
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 1);
    return 0;	     
}
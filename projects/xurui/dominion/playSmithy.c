#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playSmithy.h"

int playSmithy(struct gameState *state, int handPos)
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
    discardCard(handPos, currentPlayer, state, 0);
    return 0;	     
}
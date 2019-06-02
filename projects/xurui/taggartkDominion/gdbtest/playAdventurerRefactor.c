#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "playAdventurerRefactor.h"

int playAdventurerRefactor(struct gameState *state)
{	
	int z = 0;
	int drawntreasure = 0;
	int cardDrawn;
	int temphand[MAX_HAND];
	int currentPlayer = whoseTurn(state);
	
	while(drawntreasure<2)
	{
		if (state->deckCount[currentPlayer] <1)//if the deck is empty we need to shuffle discard and add to deck
		{
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver)
		{
			drawntreasure++;
		}
		else
		{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while(z-1>=0)
	{
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
    }
    return 0;
}
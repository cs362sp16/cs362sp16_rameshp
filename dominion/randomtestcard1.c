#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// this is for the smithy card
int main(){
	struct gameState g;
	int result;
	int random = 0;
	int currentPlayer = 1;
	int handCount, deckCount;
	int testPass = 0;
  int testFail = 0;
	int i, j;
	int handPos = 1;

	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion,
					mine, cutpurse, sea_hag, tribute, smithy};

	for(j = 0; j < 14; j++){

		for(i = 0; i < 500; i++){
			int numPlayers = rand() % 4;
			int randSeed = rand() % 5000;
			initializeGame(numPlayers, kingdomCards, randSeed, &g);
			random = rand() %9;
			if(random == 4){
				g.deckCount[currentPlayer] = 0;
				deckCount = 0;
			}else{
				deckCount = rand() % MAX_DECK;
				g.deckCount[currentPlayer] = deckCount;
			}

			handCount = rand() % MAX_HAND;
			g.handCount[currentPlayer] = handCount;
			g.discardCount[currentPlayer] = rand() % MAX_DECK;

			result = cardEffect(baron, 1, 1, 1, &g);
			if(result == 0){
				testPass++;
			}else{
				testFail++;
			}
		}
	}

	if(testPass > testFail){
		printf("Tests passed!\n\n");
		return 0;
	}else{
		printf("Tests failed!\n\n");
		return 1;
	}

}

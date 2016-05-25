// Pranav Ramesh
// CS 362

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// buys a card while checking for errors
int buyCustomCard(int cardBuy, struct gameState *state){
  if(supplyCount(cardBuy, state) < 1){
		return -1;
	}
	if(!buyCard(cardBuy, state)){
		printf("Card was bought!\n");
	}
	else
		printf("Card was NOT bought!\n");
	return 0;
}

// checks each players hand to see how many treasure cards they have.
int treasureCardCount(struct gameState *game, int player){
	int card;
	int j = 0;
  int i;
	for(i = 0; i < (game->handCount[player]); i++){
		card = game->hand[player][i];
    if(card == gold){
			j = j + 3;
		}
    if(card == silver){
			j = j + 2;
		}
		if(card == copper){
			j = j + 1;
		}
	}
	return j;
}

// shuffles the kingdom cards
void kingdomCardShuffle(int *array, size_t n){
	if (n > 1){
		size_t i;
		for(i = 0; i < (n - 1); i++){
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

int main(int argc, char *argv[]){

	//make sure correct number of arguments are provided
	if(argc > 2){
		printf("Too many arguments.\n");
		return -1;
	}
	if(argc < 2){
		printf("Not enough arguments entered.\n");
		return -1;
	}

	//setup game
	int randTestSeed = argv[1];
	struct gameState game;
	srand(randTestSeed);
	//get 10 random kingdom cards
	int allCards[20] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
	kingdomCardShuffle(allCards, 20);

	int k[10];
  int i;
	for(i = 0; i < 10; i++){
		k[i] = allCards[i];
	}

	kingdomCards(k[0], k[1], k[2], k[3], k[4], k[5], k[6], k[7], k[8], k[9]);

	// generate random number of players
  // there cannot be less than 2 players
  // and no more than 4 players
	int players = (rand() % MAX_PLAYERS);
	if(players < 2){
			players = players + 2;
	}
	srand(randTestSeed);
	int gameSeed = rand();

	// start the game and loop
	initializeGame(players, k, gameSeed, &game);
	while(!isGameOver(&game)){
		int currentPlayer = whoseTurn(&game);
		int playResult = 0;
		while(game.numActions > 0){
			int numActionCards = 0;
			//make sure there is an action card in hand
      int i;
			for(i = 0; i <numHandCards(&game); i++){
				if(game.hand[currentPlayer][i] >= adventurer && game.hand[currentPlayer][i] <= treasure_map){
					numActionCards++;
				}
			}
			if(numActionCards == 0){
				break;
			}
			int handPos = rand() % game.handCount[currentPlayer];
			int cardPlay = game.hand[currentPlayer][handPos];
			//check if selected card is kingdom card
			if(cardPlay >= adventurer && cardPlay <= treasure_map){
				playResult = playCard(handPos,0,0,0,&game);
			}
		}
		while(game.numBuys > 0){
			updateCoins(currentPlayer, &game, 0);
			int treasure = treasureCardCount(&game, currentPlayer);

			if(treasure >= 8){
				buyCustomCard(province, &game);
				treasure = treasureCardCount(&game, currentPlayer);
			}

			if(treasure >= 5){
				switch(rand() % 6){
					case 0:
						buyCustomCard(minion, &game);
						break;
					case 1:
						buyCustomCard(mine, &game);
						break;
					case 2:
						buyCustomCard(council_room, &game);
						break;
					case 3:
						buyCustomCard(duchy, &game);
						break;
					case 4:
						buyCustomCard(outpost, &game);
						break;
					default:
						buyCustomCard(tribute, &game);
						break;

				}
				treasure = treasureCardCount(&game, currentPlayer);
			}
			}
	}
		endTurn(&game);
	}
	int winners[5];
	getWinners(winners, &game);
	return 1;
}

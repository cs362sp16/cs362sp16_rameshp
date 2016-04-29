#include "dominion.h"
#include <stdio.h>

// Unit test for the shuffle()
int failed = 0;

int Assert(int b, char* msg){
  if(b == 0){
    printf("TEST PASSED. %s\n", msg);
  }
  else if(b != 0){
    printf("ASSERTION FAILED. %s\n", msg);
    failed = 1;
  }
}

void checkAssert(){
  if(!failed){
    printf("ALL TESTS COMPLETED. \n");
  }
}

int main(int argc, char *argv[]){
  int numPlayers = 2;
  int cards[] = {smithy,adventurer,gardens,embargo,cutpurse,mine,
                        ambassador,outpost,baron,tribute};
  struct gameState state;

  initializeGame(numPlayers, cards, 1234, &state);

  int player1 = 1;

  int shufflePlayer = shuffle(player1, &state);
  Assert(shufflePlayer, "PLAYER 1");

  // end turn

  int player2 = 2;

  int shufflePlayer2 = shuffle(player2, &state);
  Assert(shufflePlayer2, "PLAYER 2");

  checkAssert();

  return 0;
}

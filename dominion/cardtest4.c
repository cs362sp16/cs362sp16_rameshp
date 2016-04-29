#include "dominion.h"
#include <stdio.h>

// for the ambassador card
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
    struct gameState game;
    struct gameState *state = &game;

    initializeGame(numPlayers, cards, 1357, state);
    int ambassadorResult = cardEffect(ambassador, NULL, NULL, NULL, state, NULL, NULL);
    Assert((ambassadorResult == 0), "AMBASSADOR CARD.");

    checkAssert();

    return 0;
}

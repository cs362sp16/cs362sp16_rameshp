#include "dominion.h"
#include <stdio.h>

// Unit test for the numHandCards()
int failed = 0;

int Assert(int b, char* msg){
  if(b == 5){
    printf("TEST PASSED. %s\n", msg);
  }
  else if(b != 5){
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

  initializeGame(numPlayers, cards, 1212, &state);

  int nHCard = numHandCards(&state);
  Assert(nHCard, "\n");

  checkAssert();

  return 0;
}

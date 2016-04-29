#include "dominion.h"
#include <stdio.h>

// Unit test for the fullDeckCount()
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

  int player = 1;
  initializeGame(numPlayers, cards, 1111, &state);
  int fdCount = fullDeckCount(player, smithy, &state);
  Assert(fdCount, "");

  checkAssert();

  return 0;

}

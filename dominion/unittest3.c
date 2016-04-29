#include "dominion.h"
#include <stdio.h>

// Unit test for the supplyCount()
int failed = 0;

int Assert(int b, char* msg){
  if(b > 0 && b < 500){
    printf("TEST PASSED. %s\n", msg);
  }
  else if(b < 0 || b > 500){
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
  int i;
  int cardNum = 5;
  for(i = 0; i < cardNum; i++){
    int supplyNum = supplyCount(i, &state);
    Assert(supplyNum, "");
  }

  checkAssert();

  return 0;
}

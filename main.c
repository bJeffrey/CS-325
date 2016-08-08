#include <stdio.h>
#include "held_karp.h"

/*******************************************************************************
Description:  Test main for controlling flow of held-karp algorithm
Parameters:   none
Pre:          none
Post:         minimum path printed to screen
*******************************************************************************/
int main(){
  int i;
  struct nodeset Myset[SET_SIZE];

  int ** distances = initArray(SET_SIZE);

  initSet(Myset, SET_SIZE);
  buildDistanceTable(distances, Myset, SET_SIZE);

  for(i = 0; i < SET_SIZE; i++)
    printf("%d\t%d\t%d\n", Myset[i].point, Myset[i].x, Myset[i].y);

    printf("Distance from 0 to 1: %d\n", getDistance(Myset[0], Myset[1]) );





  printf("Program ending...\n");
  return 0;
}

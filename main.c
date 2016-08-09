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
  int cityList[SET_SIZE + 1];
  struct coord Myset[SET_SIZE];

  int** distances = initArray(SET_SIZE);

  initSet(Myset, SET_SIZE);

  for(i = 0; i < SET_SIZE; i++)
    printf("%d\t%d\t%d\n", Myset[i].city, Myset[i].x, Myset[i].y);

  held_karp_control(Myset, cityList, SET_SIZE);

  printf("Program ending...\n");
  return 0;
}

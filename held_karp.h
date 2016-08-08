#ifndef HELD_KARP_H
#define HELD_KARP_H
#include <stdio.h>
#define SET_SIZE 10

struct nodeset{
  int point;
  int x;
  int y;
};

int getDistance(struct nodeset node1, struct nodeset node2);
struct nodeset * initSet(struct nodeset * Myset, int size);
void buildDistanceTable(int ** distances, struct nodeset * Myset, int n);

int ** initArray(int size);
#endif

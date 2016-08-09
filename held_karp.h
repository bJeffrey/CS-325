#ifndef HELD_KARP_H
#define HELD_KARP_H
#include <stdio.h>
#define SET_SIZE 20

struct coord{
  int x, y, city;
};

int getDistance(struct coord node1, struct coord node2);
struct coord* initSet(struct coord * Myset, int size);
void buildDistanceTable(int ** distances, struct coord * Myset, int n);
void quickSort(struct coord * graph, int n);
void held_karp_control(struct coord * graph, int* cityList, int count);
void held_karp_compute(int ** distances, int* cityList, int count);

int** initArray(int size);
#endif

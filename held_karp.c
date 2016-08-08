/***************************************************************************
Program:     held_karp.c
Author:      Jeffrey Noe
Due Date:    8/7/2016
Description: Runs the held_karp algorithm to solve the traveling salesman problem
Input:       Struct with a set of points
Output:      The summation of the minimum distance travel-able while visiting
             all vertices
*****************************************************************************/

/*******************Note************************************
When compiling on flip, for use of the sqrt function,
you must add -L/path/to/Libs -lm to link the math
libraries.
Example: gcc held_karp.c -o held_karp -L/path/to/Libs -lm
***********************************************************/

#include <stdio.h>
#include <stdlib.h>/*malloc*/
#include <math.h>/*sqrt()*/
#include <time.h>/*rand()*/
#include "held_karp.h"/*header for held_karp*/

/*******************************************************************************
Description:  Applies the distance formula between two points
Parameters:   node1 - vertice containing x and y coordinates
              node2 - vertice containing x and y coordinates
Pre:           node1 and node2 initialized
Post:         distance between node1 and node2
*******************************************************************************/
int getDistance(struct nodeset node1, struct nodeset node2){
  return sqrt((node2.x - node1.x) * (node2.x - node1.x) + (node2.y - node1.y) * (node2.y - node1.y)) + 0.5;
}

/*******************************************************************************
Description:  initializes a test set
Parameters:   Myset - unallocated array of nodesets
              size - size of the graph for the traveling salesman problem
Pre:          N/A
Post:         points randomly allocated
*******************************************************************************/
struct nodeset * initSet(struct nodeset * Myset, int size){
  srand(time(NULL));
  int i;

  for(i = 0; i < size; i++){
    Myset[i].point = i;
    Myset[i].x = rand() % 150 + 1;
    Myset[i].y = rand() & 150 + 1;
  }
  return Myset;
}

/*******************************************************************************
Description:  builds the table of distances
Parameters:   distances - 2-d array for distances
              Myset - set of cities for traveling salesman problem
              n - number of cities
Pre:          distances dynamically allocated
Post:         distance table built (will be symmetrical)
*******************************************************************************/
void buildDistanceTable(int ** distances, struct nodeset * Myset, int n){
  printf("In buildDistanceTable\n");
  int row;
  int col;
  for(row = 0; row < n; row++){
    for(col = 0; col < n; col++){
      distances[row][col] = getDistance(Myset[row], Myset[col]);
      printf("Distance between %d and %d:\t%d\n", row, col, distances[row][col]);
    }
  }
}

/*******************************************************************************
Description:  dynamically allocates a 2-d array for the distance table
Parameters:   size - size of the array to be allocated
Pre:          N/A
Post:         array dynamically allocated
*******************************************************************************/
int ** initArray(int size){
  int i;
  int ** distances = (int**)malloc(size * sizeof(int*));

  for(i = 0; i < size; i++)
    distances[i] = (int *)malloc(size * sizeof(int));

  return distances;
}

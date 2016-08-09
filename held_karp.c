/***************************************************************************
Program:     held_karp.c
Author:      Jeffrey Noe
Due Date:    8/7/2016
Description: Runs the held_karp algorithm to solve the traveling salesman problem
Input:       Struct with a set of citys
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
Description:  Applies the distance formula between two citys
Parameters:   node1 - vertice containing x and y coordinates
              node2 - vertice containing x and y coordinates
Pre:           node1 and node2 initialized
Post:         distance between node1 and node2
*******************************************************************************/
int getDistance(struct coord node1, struct coord node2){
  return sqrt((node2.x - node1.x) * (node2.x - node1.x) + (node2.y - node1.y) * (node2.y - node1.y)) + 0.5;
}

/*******************************************************************************
Description:  initializes a test set
Parameters:   Myset - unallocated array of coords
              size - size of the graph for the traveling salesman problem
Pre:          N/A
Post:         citys randomly allocated
*******************************************************************************/
struct coord* initSet(struct coord* Myset, int size){
  srand(time(NULL));
  int i;

  for(i = 0; i < size; i++){
    Myset[i].city = i;
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
void buildDistanceTable(int** distances, struct coord* Myset, int n){
  int row;
  int col;
  for(row = 0; row < n; row++){
    for(col = 0; col < n; col++)
      distances[row][col] = getDistance(Myset[row], Myset[col]);
  }
}

/*******************************************************************************
Description:  controls the flow of the held-karp algorithm
Parameters:   graph - a graph with all the cities
              cityList - a list of the order in which cities are visited
              count - the number of cities in the set
Pre:          graph populated.  cityList empty.  count set.
Post:         Held-Karp algorithm applied.
*******************************************************************************/
void held_karp_control(struct coord* graph, int* cityList, int count){
  int** distances = initArray(SET_SIZE);
  buildDistanceTable(distances, graph, count);
  held_karp_compute(distances, cityList, count);

}

/*******************************************************************************
Description:  applies the Held-Karp algorithm to the TSP
Parameters:   distances - an array for the distances
              cityList - an array for the list of cities in order
              count - the number of cities being visited
Pre:          function called from held_karp_control
Post:         Held-Karp algorithm applied
*******************************************************************************/
void held_karp_compute(int** distances, int* cityList, int count){
  int row, col, k, min;
  int i = 0;
/******************************************************************************
*******************************Citation****************************************
The following code applies implementations and ideas of the Held-Karp algorithm
from the following sources:
  https://www.youtube.com/watch?v=-JjA4BLQyqE
  https://github.com/mission-peace/interview/blob/master/src/com/interview/graph/TravelingSalesmanHeldKarp.java
  https://github.com/iRitwik/algo11/blob/master/assignment01.c
  http://www.codeproject.com/Articles/762581/Held-Karp-algorithm-implementation-in-Csharp
******************************************************************************/
  int** B = (int**)malloc((int)pow(2, count - 1) * sizeof(int*));
  int** A = (int**)malloc((int)pow(2, count - 1) * sizeof(int*));

  for(row = 0; row < (int)pow(2,count-1); row++){
    B[row] = (int*)malloc((count-1)*sizeof(int));
    A[row] = (int*)malloc((count-1)*sizeof(int));
  }

  for(col=0; col < count - 1; col++){
    B[0][col] = distances[0][col+1];
    A[0][col] = 0;
  }

  for(row = 0; row < (int)pow(2, count -1); row++){
    for(col = 0; col < count - 1; col++){
      if( (row&(1<<col) ) != 0){
        B[row][col] = -1;
        A[row][col] = -1;
      }
    }
  }

  for(row = 1; row < (int)pow(2, count - 1); row++){
    for(col = 0; col < count - 1; col++){
      if(B[row][col] != -1){
        min = -1;
        for(k = 0; k < count - 1; k++){
          if( ( (1 << k) &row) != 0 ){
            int cost1= B[row - (int)pow(2,k)][k] + distances[k + 1][col + 1];

            if( (min == -1) || (min > cost1) ){
              min = cost1;
              A[row][col] = k + 1;
            }
          }
        }
        B[row][col] = min;
      }
    }
  }
  int minimum_leg = -1;
  min = -1;

  for(row = 0; row < count - 1; row++)
  {
    int min_cost = B[(int)(pow(2, count - 1) - pow(2, row)) - 1][row] + distances[row + 1][0];
    if( (min_cost < min) || (min == -1) )
    {
      min = min_cost;
      minimum_leg = row + 1;
    }
  }

  int setMin_value = (int)pow(2, count - 1) - 1 - (int)pow(2, minimum_leg - 1);
  printf("0-");
  cityList[i] = 0;
  while(minimum_leg != 0){
    i++;
    printf("%d-", minimum_leg);
    cityList[i] = minimum_leg;
    minimum_leg = A[setMin_value][minimum_leg - 1];
    setMin_value -= (int)pow(2, minimum_leg - 1);
  }
  /*****************************************************************************
                    ************End of Citation******************
  *****************************************************************************/
  cityList[i + 1] = 0;
  printf("Minimum Cost = %d\n",min);
}

/*******************************************************************************
Description:  dynamically allocates a 2-d array for the distance table
Parameters:   size - size of the array to be allocated
Pre:          N/A
Post:         array dynamically allocated
*******************************************************************************/
int** initArray(int size){
  int i;
  int** distances = (int**)malloc(size * sizeof(int*));

  for(i = 0; i < size; i++)
    distances[i] = (int*)malloc(size * sizeof(int));

  return distances;
}

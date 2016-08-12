#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>/*INT_MAX*/

struct coord
{
	int x, y, city;
};

//displays values for all cities
void display(struct coord *in, int count)
{
	int i = 0;
	while (i < count)
	{
		printf("City: %i: x = %i, y = %i\n",in[i].city, in[i].x, in[i].y);
		i++;
	}
}

//resets input to zero to avoid reusing previous values
void setZero(char *arr)
{
	int i = 0;
	while (i < 100)
	{
		arr[i] = NULL;
		i++;
	}
}

float distance(int x1, int y1, int x2, int y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int checkInput(char **argv, int argc)
{

	//check number of arguments
	if (argc != 2)
	{
		return 0;
	}

	//check if file exists
	FILE *file;
    if (file = fopen(argv[1], "r"))
    {
        fclose(file);
        return 1;
    }
	else
		return 0;
}

float get_total_distance(struct coord* dynOrder, int count){
	int i = 0;
	float dist;
	while (i < count-1)
	{
		dist += distance(dynOrder[i].x, dynOrder[i].y, dynOrder[i+1].x, dynOrder[i+1].y);
		i++;
	}
	dist += distance(dynOrder[i].x, dynOrder[i].y, dynOrder[0].x, dynOrder[0].y);

	//display results
	// printf("Total distance = %f\n", dist);
	//close file
	//fclose(fp);
	return dist;
}


struct coord *greedy(struct coord *city, int starting_point, int count)
{
	struct coord *path = malloc(sizeof(struct coord) * count);
	struct coord temp, current;
	//variable to keep track of number of remaining cities
	int control = 1;
	//set starting city
	path[starting_point] = city[starting_point];
	current = city[starting_point];
	temp = current;
	//accounts for what cities have been visited
	int list[count];
	int i = 1;
	while (i < count)
	{
		//sets all cities to unvisited
		list[i] = 0;
		i++;
	}
	//reset i for use
	i = 0;
	int x = 0;
	//sets starting city to true

	list[starting_point] = 1;
	while (control < count - 1)
	{
		while (i < count -1 )
		{
			if (list[i] == 0)
			{
				if (distance(current.x,current.y,city[i].x,city[i].y) < distance(current.x,current.y,temp.x,temp.y) || distance(current.x,current.y,temp.x,temp.y) == 0)
				{
					temp = city[i];
					x = i;
				}
			}
			i++;
		}
		list[x] = 1;
		//printf("Test1 list[x]: = %i\n", list[x]);

		int k;
		/*for(k=0; k< count; k++)
			printf("%i ",list[k]);

		printf("\n");

		printf("x = %i\n", x);*/
		path[control] = temp;
		current = temp;
		i = 0;
		control++;
	}
	i = 0;

	/*for (i = 0; i < count; i++){
			printf("City: %i\n", path[i].city);
		}*/
	return path;
}


void output_to_file(int shorest_path, int count, struct coord *dyn, char* file_name)
{
	FILE *fp;

	char ending[5] = ".tour";

	/* concatenates file name with .tour */
	strcat( file_name, ending);

	fp = fopen(file_name,"w");
	fprintf(fp, "%d\n", shorest_path);
	int j;
	for(j=0;j<count;j++)
	fprintf(fp, "%d\n", dyn[j].city);
	fclose(fp);
}

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


/*******************************************************************************
Description:  builds the table of distances
Parameters:   distances - 2-d array for distances
              Myset - set of cities for traveling salesman problem
              n - number of cities
Pre:          distances dynamically allocated
Post:         distance table built (will be symmetrical)
*******************************************************************************/
void buildDistanceTable(int** distances, const struct coord* Myset, int n){
  int row;
  int col;
  for(row = 0; row < n; row++){
    for(col = 0; col < n; col++)
      distances[row][col] = getDistance(Myset[row], Myset[col]);
  }
}

struct coord getNextClosestCity(const struct coord* old_graph, int** distance_table, int* visited_list, int current_city, int count){
	struct coord next_city;
  int shortest_path = INT_MAX;
	int i, j;

	// printf("\n\nOld_graph list of cities: \n");
	// for(i = 0; i < count; i++)
		// printf("%d\n", old_graph[i].city);
		// printf("%d\t", visited_list[i]);
	// printf("\n\n");

	for(i = 0; i < count; i++){

		//If you haven't visited the city and the distance to the city is less than your current shortest_path,
		//set your shortest path and next city to that city
		// printf("Looking at city %d\nVisited/not visitited: %d\nIts distance: %d\nThe current shortest_path: %d\n", i, visited_list[i], distance_table[current_city][i], shortest_path);
		if( (visited_list[i] == 0) && (distance_table[current_city][i] < shortest_path) ){
			shortest_path = distance_table[current_city][i];
			next_city = old_graph[i];
			// printf("\n\nUpdated next_city to: %d\n\n", next_city.city);
		}
	}
	// printf("\n\nCurrent city: %d\nNext closest city: %d\n\n\n", current_city, next_city.city);
	return next_city;
}

struct coord* jeffsGreedyAlg(const struct coord* old_graph, struct coord* new_graph, int current_city, int count){
	int i, j;
	int** distance_table = initArray(count);
	struct coord next_city;
	int visited_list[count];
	buildDistanceTable(distance_table, old_graph, count);

	//Due to unexplainable issue, the old_graph must get copied before being passed to getNextClosestCity
	// struct coord copied_old_graph[count];
	// for(i = 0; i < count; i++)
			// copied_old_graph[i]= old_graph[i];

	// printf("\n\nold_graph list of cities: \n");
	// for(i = 0; i < count; i++)
			// printf("%d\n", old_graph[i].city);


	//Initialize visited list to 0. Set our starting city to 1
	for(i = 0; i < count; i++)
		visited_list[i] = 0;
	visited_list[current_city] = 1;

	//Find the next nearest city, add it to the list, change it's visited_list value to 1
	new_graph[0] = old_graph[current_city];
	for(i = 1; i < count; i++){

		// printf("\n\nold_graph list of cities before calling NextClosestCity: \n");
		// for(j = 0; j < count; j++)
			// printf("%d\n", old_graph[j].city);
		// printf("\n\n");

		next_city = getNextClosestCity(old_graph, distance_table, visited_list, current_city, count);

		// printf("\n\nold_graph list of cities after calling NextClosestCity: \n");
		// for(j = 0; j < count; j++)
			// printf("%d\n", old_graph[j].city);
		// printf("\n\n");

		new_graph[i] = next_city;
		visited_list[next_city.city] = 1;
		current_city = next_city.city;

		// printf("next_city in jeffsGreedyAlg: %d\n", next_city.city);
		// printf("Visited list: \n");
		// for(j = 0; j < count; j++){
			// printf("%d\t", visited_list[i]);
		// }
		// printf("\n");


	}
	int mydistance;
	int distance_total = 0;
/*
		printf("\n\nCity List as follows: \n");
		printf("City: %d\t\tx: %d\t\t%d\n", new_graph[0].city, new_graph[0].x, new_graph[0].y);
		for(i = 0; i < count - 1; i++){

			mydistance = getDistance(new_graph[i], new_graph[i+1]);
			distance_total += mydistance;
			printf("City: %d\t\tx: %d\t\ty: %d\tDistance: %d\t\tTotal Distance: %d\n", new_graph[i].city, new_graph[i].x, new_graph[i].y, mydistance, distance_total);
		}
		mydistance = getDistance(new_graph[0], new_graph[count - 1]);
		distance_total += mydistance;
		printf("City: %d\t\tx: %d\t\ty: %d\t\tDistance: %d\t\tTotal Distance: %d\n", new_graph[0].city, new_graph[0].x, new_graph[0].y, mydistance, distance_total);
*/
	 return new_graph;
}

float greedy_control(struct coord* city, struct coord *current_city_list, int count, char* file_name){

	clock_t start, end;
	double time_used, time_check;
	float timer1 = 0.0;
	float timer2 = 0.0;
	start = clock();
	time_used = 0.00;
	time_check = 0.00;
/*
	int i;
	printf("\n\n\nCity List before any changes:\n");
	for(i = 0; i < count; i++){
		printf("%d\t%d\t%d\n", city[i].city, city[i].x, city[i].y);
	}
	printf("\n");
*/
	float shortest_distance = get_total_distance(city, count);
	float current_distance;
	struct coord* best_city_list = city;
	int i;
	for(i = 0; i < count; i++){
		current_city_list = jeffsGreedyAlg(city, current_city_list, i, count);
		current_distance = get_total_distance(current_city_list, count);


		if(current_distance < shortest_distance){
			best_city_list = current_city_list;
			shortest_distance = current_distance;
			// for(j = 0; j < count; j++){
				// printf("best_city_list city: %d\n", best_city_list[i].city);
			// }

		}

		end = clock();
		time_used += (double)(end - start)/CLOCKS_PER_SEC;
		time_check += (double)(end - start)/CLOCKS_PER_SEC;

		if(time_check >= 20){
			printf("Calculating...\n");
			time_check = 0.00;
		}

		if(time_used >= 21566.00)
			break;

	}
	// printf("last distancd: %f\n", distance(current_city_list[s].x, current_city_list[s].y, current_city_list[e].x, current_city_list[e].y));
	// shortest_distance += distance(best_city_list[0].x, best_city_list[0].y, best_city_list[count - 1].x, best_city_list[count - 1].y);

	for(i = 0; i < count; i++){
		printf("best_city_list city: %d\n", best_city_list[i].city);
	}

	output_to_file(shortest_distance, count, best_city_list, file_name);
	return shortest_distance;
}





int main(int argc, char *argv[])
{
	//check user input
	if (checkInput(argv, argc) == 0)
	{
		printf("Error, please make sure to enter a single file name, ending with '.txt'\n");
		return 0;
	}

	//initialize character array to store file data
	char input[100];
	char temp[100];
	int count = 0;
	float dist = 0;
	float shortest_distance;//Distance of the shortest path from the greedy algorithm
	//pointer to what will become a dynamic array
	// struct coord *dyn; moved to stack
	//pointer to what will become a dynamic array in the order to be traveled
	// struct coord *dynOrder;
	// struct coord *newOrder = malloc(sizeof(struct coord) * count);
	//create file pointer and open file
	FILE *fp;
	fp = fopen(argv[1], "r");
	//create while loop to read in data
	while (fgets(input, 100, fp) != NULL)
	{
		count++;
	}
	//allocate memory for array of cooridnates
	// dyn = malloc(sizeof(struct coord) * count); moved to stack
	struct coord *newOrder = malloc(sizeof(struct coord) * count);
	struct coord *dyn = malloc(sizeof(struct coord) * count);
	struct coord *dynOrder = malloc(sizeof(struct coord) * count);
	// dynOrder = malloc(sizeof(struct coord) * count);
	//close file to reset place
	fclose(fp);
	//reopen file
	fp = fopen(argv[1], "r");
	//set control variables
	int k = 0;
	int j = 0;
	while (k < count)
	{
		fscanf(fp, "%d %d %d", &(dyn[k].city),&(dyn[k].x),&(dyn[k].y));
		k++;
	}

	//display city and coord values (used for testing only)
	//display(dyn, count);

	//Call algorithm function
	int p;
	/*printf("\n\n\nCity List before any changes in main:\n");
	for(p = 0; p < count; p++){
		printf("%d\t%d\t%d\n", dyn[p].city, dyn[p].x, dyn[p].y);
	}*/
	//printf("\n");

	shortest_distance = greedy_control(dyn, newOrder, count, argv[1]);

	printf("Shortest path: %f\n", shortest_distance);



	//close file
	//fclose(fp);
}

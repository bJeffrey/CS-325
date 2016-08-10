#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

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
	i = 1;
	int x = 0;
	//sets starting city to true
	list[starting_point] = 1;
	while (control < count)
	{
		while (i < count)
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
		path[control] = temp;
		current = temp;
		i = 0;
		control++;
	}
	i = 0;
	return path;
}

float greedy_control(struct coord* city, int count){
	clock_t start, end;
	double time_used, time_check;
	float timer1 = 0.0;
	float timer2 = 0.0;
	start = clock();
	time_used = 0.00;
	time_check = 0.00;

	struct coord *current_city_list;
	int i;
	float shortest_distance = get_total_distance(city, count);
	float current_distance;

	for(i = 0; i < count; i++){
		current_city_list = greedy(city, i, count);
		current_distance = get_total_distance(current_city_list, count);

		if(current_distance < shortest_distance)
		shortest_distance = current_distance;

		end = clock();
		time_used += (double)(end - start)/CLOCKS_PER_SEC;
		time_check += (double)(end - start)/CLOCKS_PER_SEC;

		if(time_check >= 20){
			time_check = 0.00;
		}

		if(time_used >= 21566.00)
			break;

	}

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
	struct coord *dyn;
	//pointer to what will become a dynamic array in the order to be traveled
	struct coord *dynOrder;
	//create file pointer and open file
	FILE *fp;
	fp = fopen(argv[1], "r");
	//create while loop to read in data
	while (fgets(input, 100, fp) != NULL)
	{
		count++;
	}
	//allocate memory for array of cooridnates
	dyn = malloc(sizeof(struct coord) * count);
	dynOrder = malloc(sizeof(struct coord) * count);
	//close file to reset place
	fclose(fp);
	//reopen file
	fp = fopen(argv[1], "r");
	//set control variables
	int k = 0;
	int j = 0;
	while (fgets(input, 100, fp) != NULL)
	{
		//Sets i to the next available spot
		dyn[k].city = atoi(input);
		int i = 0;
		while (input[i] != ' ')
		{
			i++;
		}
		//incriments i value, as otherwise, it will be set on the " " value, and not enter other while loops
		i++;

		//sets x value in coord
		while (input[i] != ' ')
		{
			temp[j] = input[i];
			j++;
			i++;
		}
		//incriment to avoid space value
		i++;
		//set x value
		dyn[k].x = atoi(temp);
		//set all temp values to NULL to avoid writing incorrect value to coords
		setZero(temp);

		//sets y value in coord (same methodology as x)
		j = 0;
		while (input[i] != ' ')
		{
			temp[j] = input[i];
			j++;
			i++;
		}
		j = 0;
		dyn[k].y = atoi(temp);
		setZero(temp);
		//incriment to next spot in array
		k++;
	}

	//display city and coord values (used for testing only)
	//display(dyn, count);

	//Call algorithm function
	shortest_distance = greedy_control(dyn, count);
	printf("Shortest path: %f\n", shortest_distance);

	//close file
	//fclose(fp);
}

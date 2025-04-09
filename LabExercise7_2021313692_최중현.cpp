#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ArrayFunction(int x[]);

int main()
{
	int x[18];
	srand(time(NULL));
	
	// In the main function, create an one dimensional array consisting of 15 random integers in the range of -5 to 50.
	// Print out this one dimensional array.
	int i = 0;
	for(i = 0; i < 15; i++)
	{
		x[i] = rand() % 56 - 5;
		printf("%d ", x[i]);
	}
	printf("\n");
		
	ArrayFunction(x);
	
	// In the main function, print out these 3 values. 
	printf("max = %d\nmin = %d\nsum = %d", x[15], x[16], x[17]);
}

// Write a function that would take this array as argument by reference.
void ArrayFunction(int x[])
{
	int max = -5, min = 50, sum = 0;
	
	int i = 0;
	for(i = 0; i < 15; i++)
	{
		if(max < x[i])	max = x[i];
		if(min > x[i])	min = x[i];
		sum += x[i];
	}
	
	// Your function returns 3 values by reference:
	x[15] = max;	// The maximum value of the array
	x[16] = min;	// The minimum value of the array
	x[17] = sum;	// The sum of the array
}



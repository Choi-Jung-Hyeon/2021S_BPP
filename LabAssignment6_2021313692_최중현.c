#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL)); // Generate random seed
	 
	int i, j, array[10][8];
	int (*arrPtr)[8] = array;
	for(i = 0; i < 10; i++) // Define array
	{	
		for(j = 0; j < 8; j++)
			array[i][j] = rand() % 91 + 10;
	}
	
	int min = 100, max = 10, sum;
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 8; j++)
		{
			printf("%d ", arrPtr[i][j]); // Print out this array
			
			if(min > (*(arrPtr + i))[j]) // Find the smallest value
				min = *(arrPtr[i] + j);
			if(max < *(*(arrPtr + i) + j)) // Find the largest value
				max = array[i][j];
			sum += array[i][j];
		}
		printf("\n");
	}
	
	float avg;
	avg = (float)sum / 80.0; // Calculate the average value
	
	printf("The smallest value is %d\n", min); // Display the values
	printf("The largest value is %d\n", max);
	printf("The average value is %f\n", avg);

	return 0;
}




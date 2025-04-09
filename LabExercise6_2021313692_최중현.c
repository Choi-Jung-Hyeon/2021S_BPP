#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL)); // Generate random seed
	 
	int i, array[20]; 
	for(i = 0; i < 20; i++) // Define array
		*(array + i) = rand() % 76 + 25;
	
	int min = 100, max = 25, sum;
	
	printf("Array: ");
	for(i = 0; i < 20; i++)
	{
		printf("%d ", *(array + i)); // Print out this array
		
		if(min > *(array + i)) // Find the smallest value
			min = *(array + i);
		if(max < *(array + i)) // Find the largest value
			max = *(array + i);
		sum += *(array + i);
	}
	printf("\n");
	
	float avg;
	avg = (float)sum / 20.0; // Calculate the average value
	
	printf("The smallest value: %d\n", min); // Display the values
	printf("The largest value: %d\n", max);
	printf("The average value: %f\n", avg);

	return 0;
}



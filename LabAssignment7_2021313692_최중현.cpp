#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ArrayFunction(int number, int x[]);

int main()
{
	int x[10];
	srand(time(NULL));
	
	// In the main function, create an one dimensional array consisting of 10 random integers in the range of 1-99.
	// Print out this one dimensional array.
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		x[i] = rand() % 99 + 1;
		printf("A[%d]: %d, ", i, x[i]);
	}
	printf("\n");
	
	// Prompt the user to enter a number.
	int number = 1;
	printf("Enter the number you want to search: ");
	scanf("%d", &number);
		
	int Result = 0;
	Result = ArrayFunction(number, x);
	
	// In the main function, print out the result.
	if(Result == 1)
		printf("The number you entered is in the array.");
	else
		printf("The number you entered is not in the array.");
		
	return 0;
}

// Write a function that would take the number the user entered and the array as argument by reference.
// The array should be passed by reference in the function.
int ArrayFunction(int number, int x[])
{
	// Your function will search if the array contains the number the user entered.
	int i = 0;
	for(i = 0; i < 10; i++)
		if(x[i] == number)
			// Your function will return the result (about if the array contains the number the user entered or not.)
			return 1;	
}

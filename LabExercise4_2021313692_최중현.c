#include <stdio.h>
#include <math.h>

void PrintMenu(void); // Function Prototype

int AskUserInput(void);

void DisplayResult(int result);

int main(void)
{ 
	PrintMenu(); // Function Call
	
	int input = AskUserInput();
	int result = pow(input,3); // calculate the cube of input
	
	DisplayResult(result);
	
	return 0;
}

// Function Definition
void PrintMenu(void) // provide a menu
{
	printf("Please input an integer: ");
}

int AskUserInput(void) // save user's answer and print it
{
	int integer; 
	
	scanf("%d", &integer);
	printf("You entered: %d\n", integer);
	
	return integer; // return type is int
}

void DisplayResult(int result) // show the result
{
	printf("The result is: %d", result);
}

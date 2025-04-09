#include <stdio.h>

int main()
{
	// Make a number list.
	int index = 0, numbers[10];
	for(int i = 0; i < 10; i++)
	{
		printf("Enter number %d: ", index);
		scanf("%d", &numbers[i]);
		index++;
	}
	
	// Print the number list.
	printf("User entered: ");
	for(int i = 0; i < 10; i++)
		printf("%d ", numbers[i]);
	printf("\n");
	
	// Define pointer variables.
	int *head, *tail;
	head = &numbers[0];
	tail = &numbers[9];
	
	// Distinguish if the number list is a palindrome or not.
	int count = 0;
	for(int i = 0; i < 5; i++)
	{
		if(*(head + i) != *(tail - i))
			count++;
	}
	
	// Print the result.
	if(count == 0)
		printf("YES!!! It is a palindrome!");
	else
		printf("NO!!! It is not a palindrome!");
	return 0;
}



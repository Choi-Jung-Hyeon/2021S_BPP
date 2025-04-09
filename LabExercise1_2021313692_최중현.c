#include <stdio.h>

int main(void)
{
	int Number_1;
	int Number_2;
	
	printf("Enter the first number : ");
	scanf("%d", &Number_1);
	printf("Enter the second number : ");
	scanf("%d", &Number_2);
	
	int Sum;
	Sum = Number_1 + Number_2;
	printf("Sum : %d", Sum);
	
	return 0;
}

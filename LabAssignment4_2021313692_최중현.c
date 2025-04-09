  #include <stdio.h>

float CurrencyConversion(float AmountInWon, float rate); // Function Prototype
void Menu(void);

int main(void)
{
	int option, money;
	float exchange; 
	
	do // do-while loop
	{
		Menu();
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: // USD
				printf("Enter the amount in Korean Won: ");
				scanf("%d", &money);
				
				exchange = CurrencyConversion((float)money, 0.000905);
				printf("%d Won equals to %f USD\n\n", money, exchange);
				break;
				
			case 2: // Euro
				printf("Enter the amount in Korean Won: ");
				scanf("%d", &money);
				
				exchange = CurrencyConversion((float)money, 0.000807350908);
				printf("%d Won equals to %f Euro\n\n", money, exchange);
				break;
				
			case 3: // Yen
				printf("Enter the amount in Korean Won: ");
				scanf("%d", &money);
				
				exchange = CurrencyConversion((float)money, 0.0919061643);
				printf("%d Won equals to %f Yen\n\n", money, exchange);
				break;
				
			case 4: // RMB
				printf("Enter the amount in Korean Won: ");
				scanf("%d", &money);
				
				exchange = CurrencyConversion((float)money, 0.00603703605);
				printf("%d Won equals to %f RMB\n\n", money, exchange);
				break;
				
			case 5: // quit
				break;
				
			default: // invalid input
				printf("You entered an invalid input.\n\n");
				break;	
		}
	} while(option != 5); // loop condition

	return 0;	
}

float CurrencyConversion(float AmountInWon, float rate) // Function Definition
{
	return AmountInWon * rate;
}

void Menu(void)
{
	// Exchange Rate
	printf("Please choose which currency you want to convert:\n");
	printf("1 - Korean Won to US Dollar (Exchange Rate: 0.000905)\n");
	printf("2 - Korean Won to Euro (Exchange Rate: 0.000807350908)\n");
	printf("3 - Korean Won to Japanese Yen (Exchange Rate: 0.0919061643)\n");
	printf("4 - Korean Won to Chinese RMB (Exchange Rate: 0.00603703605)\n");
	printf("5 - Quit\n");
	printf("Enter your option: ");
}

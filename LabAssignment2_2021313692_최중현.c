#include<stdio.h>

int main(void)
{
	int calender;
	printf("Enter a date in numerical form (MMDDYYYY):");
	scanf("%d", &calender);
	
	int year, month, date;
	year = calender % 10000;
	month = calender / 1000000;
	date = (calender / 10000) - (month * 100);
	
	if(date > 31 || date < 1) // condition of date
	{
		printf("<End of program>");
		return 0;
	}
	
	printf("The date you entered is: %d", date); // date
	char after_date; // word after the date
	if(date == 1 || date == 21 || date == 31)
		printf("st ");
	else if(date == 2 || date == 22)
		printf("nd ");
	else if(date == 3 || date == 23)
		printf("rd ");
	else
		printf("th ");
	
	switch(month) // month
	{	
		case 1:		printf("January");		break;
		case 2:		printf("February");		break;
		case 3:		printf("March");		break;
		case 4:		printf("April");		break;
		case 5:		printf("May");			break;
		case 6:		printf("June");			break;
		case 7:		printf("July");			break;
		case 8:		printf("August");		break;
		case 9:		printf("September");	break;
		case 10:	printf("October");		break;
		case 11:	printf("November");		break;
		case 12:	printf("December");		break;
		
		default:
			printf("<End of program>");	
			return 0; // condition of month
	}
	
	printf(" %d\n", year); // year
	printf("<End of program>");
	return 0;
}

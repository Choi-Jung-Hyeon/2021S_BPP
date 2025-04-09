#include <stdio.h>
#include <conio.h>
#include <math.h>
#define Korean 51700000.000000 // Constant

// Global Variable
int Run, Day, S_percentage, E_percentage, I_percentage, R_percentage;
double Beta, Sigma, Gamma, infected_Day0;
double S_2_E, E_2_I, I_2_R;
double susceptible[82], exposed[82], infected[82], recover[82], number_population;
char Histogram_input, Histogram_display, Run_again_input, Run_again;

// Function Prototype
void Asking_user_input();
void Print_out_header_first();
char Ask_histogram();
void Display_histogram();
void Ask_histogram_again();
void Ask_run_again_again();
char Ask_run_again();

int main(void)
{	
	do{
	// Asking user input 
	Asking_user_input();
	
	// Print out header first
	Print_out_header_first();
	
	// Display results
	susceptible[0] = Korean;
	infected[0] = infected_Day0;
	number_population = Korean + infected_Day0;
	for(Day = 0; Day <= Run; Day++)
	{
		printf("Day %-2d:  %-15lf %-15lf %-15lf %-15lf\n", Day, susceptible[Day], exposed[Day], infected[Day], recover[Day]);
		
		S_2_E = Beta * (susceptible[Day] * infected[Day] / number_population);
		E_2_I = Sigma * exposed[Day];
		I_2_R = Gamma * infected[Day];
		
		if(susceptible[Day] - S_2_E >= 0)
		{
			susceptible[Day + 1] = susceptible[Day] - S_2_E;
			exposed[Day + 1] = exposed[Day] + S_2_E - E_2_I;
			infected[Day + 1] = infected[Day] + E_2_I - I_2_R;
			recover[Day + 1] = recover[Day] + I_2_R;
		}
		else
		{
			exposed[Day + 1] = exposed[Day] + susceptible[Day] - E_2_I;
			infected[Day + 1] = infected[Day] + E_2_I - I_2_R;
			recover[Day + 1] = recover[Day] + I_2_R;
			susceptible[Day + 1] = 0;
		}
		
		if(Day == Run)
			printf("\n");
	}
	Day = 0;
	
	// Ask if the user want to plot the result in histogram
	Histogram_display = Ask_histogram();
	if(Histogram_display == 'y')
		Display_histogram();
	
	// Ask if the user want to run the simulation again
	Run_again = Ask_run_again();
	printf("\n");
	if(Run_again == 'n')
		break;
	} while(Run_again == 'y');
	
	printf("<The End of Simulation>");
	return 0;
}

// Function Definition
void Asking_user_input()
{
	printf("Enter the number of infected people in Day 0: ");
	scanf("%lf", &infected_Day0);
	printf("Enter the value of Beta (Transmission Rate): ");
	scanf("%lf", &Beta);
	printf("Enter the value of Sigma (Incubation Rate): ");
	scanf("%lf", &Sigma);
	printf("Enter the value of Gamma (Recovery Rate): ");
	scanf("%lf", &Gamma);
	printf("How many days do you want to run the simulation: ");
	scanf("%d", &Run);
}

void Print_out_header_first()
{
	printf("Day      S               E               I               R               \n");
	printf("========================================================================\n");
}

char Ask_histogram()
{	
	printf("Do you want to plot the result [y/n]? ");
	scanf("%s", &Histogram_input);

	if(Histogram_input == 'y' || Histogram_input == 'n')
		return Histogram_input;
	else
	{
		printf("Input Error! Please enter [y/n]\n");
		Ask_histogram();
	}
}

// Plot the percentage value from Day 0 to Day X in the histogram
void Display_histogram()
{
    char select_plot;
    printf("Which data would you like to plot? [s/e/i/r] ");
    scanf("%s", &select_plot);

	int i;
    int susceptible_histogram, exposed_histogram, infected_histogram, recovered_histogram;
    switch (select_plot)
    {
    case 's':
        for (Day = 0; Day <= Run; Day++)
        {
        	susceptible_histogram = (int)(susceptible[Day] / number_population * 100);
            printf("Day %-2d:   (%2d%%)  | ", Day, susceptible_histogram);
            for (i = 0; i < susceptible_histogram; i++)
                printf("*");
            printf("\n");
        }
        printf("\n");
        break;

    case 'e':
        for (Day = 0; Day <= Run; Day++)
        {
            exposed_histogram = (int)(exposed[Day] / number_population * 100);
            printf("Day %-2d:   (%2d%%)  | ", Day, exposed_histogram);
            for (i = 0; i < exposed_histogram; i++)
                printf("*");
            printf("\n");
        }
        printf("\n");
        break;

    case 'i':
        for (Day = 0; Day <= Run; Day++)
        {
            infected_histogram = (int)(infected[Day] / number_population * 100);
            printf("Day %-2d:   (%2d%%)  | ", Day, infected_histogram);
            for (i = 0; i < infected_histogram; i++)
                printf("*");
            printf("\n");
        }
        printf("\n");
        break;

    case 'r':
        for (Day = 0; Day <= Run; Day++)
        {
            recovered_histogram = (int)(recover[Day] / number_population * 100);
            printf("Day %-2d:   (%2d%%)  | ", Day, recovered_histogram);
            for (i = 0; i < recovered_histogram; i++)
                printf("*");
            printf("\n");
        }
        printf("\n");
        break;

    default:
        printf("Input Error! Please enter [s/e/i/r]\n");
        Display_histogram();
        break;
    }
    
    Ask_histogram_again();
}

void Ask_histogram_again()
{
	printf("Do you want to plot the result [y/n]? ");
	scanf("%s", &Histogram_input);

	if(Histogram_input == 'y')
		Display_histogram();
	else if(Histogram_input == 'n')
		Ask_run_again_again();
	else
	{
		printf("Input Error! Please enter [y/n]\n");
		Ask_histogram_again();
	}
}

void Ask_run_again_again()
{
	Run_again = Ask_run_again();
		if(Run_again == 'n')
			return;
		else if(Run_again == 'y')
			main();
		else
		{
			printf("Input Error! Please enter [y/n]\n");
			Ask_run_again_again();
		}
}

char Ask_run_again()
{
	printf("Do you want to run the simulation again [y/n]? ");
	scanf("%s", &Run_again_input);
	
	if(Run_again_input == 'y' || Run_again_input == 'n')
		return Run_again_input;
	else
	{
		printf("Input Error! Please enter [y/n]\n");
		Ask_run_again();
	}
}

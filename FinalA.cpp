#include <stdio.h>
#include <string.h>

struct node {
	char country[80];
	char country_code[3];
	int totalCases;
	int totalDeaths;
	struct node * NextPtr;
};

// This function takes a pointer to a linked list as parameter, and calculate the length (i.e. number of node) in the linked list as return value.
int Length(node * chain) 
{	
}

// This function takes a pointer to a linked list as parameter, and then print out all the data in the linked list. This function does not have any return value.
void PrintALL(node * chain) 
{	
}

// This function takes a pointer to a linked list and a character string as input, and then find if there ia any node that matches the country_code with the 
// character string. The function returns a pointer pointing to the node if a match is found, and returns 0 if no found.
node * Find(node * chain, char * input) 
{	
}

int main(void)
{	node chain[500];			// The linked list!
	node * maxTotalCases=0;		// A pointer pointing at the node with max total infection cases
	node * maxTotalDeaths=0;	// A pointer pointing at the node with max total death cases
	node * head=&chain[0];		// A pointer pointing at the first node of the linked list

	/* Fill in your code here.
	Your code should:
		- Read data from the data file ("covid-19.csv").
		- Calculate the total infection cases and total death cases for each country.
		- Construct a linked list based on the calculated results.
	*/

	printf("There are %d countries in the data.\n",Length(chain));		// Display number of countries
	printf("Max Total Cases: %s %d\n",maxTotalCases->country,maxTotalCases->totalCases);		// Display country with maximum total infection cases
	printf("Max Total Deaths: %s %d\n",maxTotalDeaths->country,maxTotalDeaths->totalDeaths);	// Display country with maximum total death cases
		
	char Input[4];
	while(strcmp(Input,"q"))		// A loop asking for user input, and then display the corresponding data
	{	printf("===============================\n");
		printf("Enter the country code to display the total number of cases and total number of death of the country.\n");
		printf("Enter \"ALL\" to display all data.\n");
		printf("Enter (q to quit): ");
		scanf("%s",Input);
		
		if(!strcmp(Input,"ALL"))	// Display all data in the linked list
			PrintALL(chain);
		else
		{	node * ResultPtr = Find(chain,Input);
			if (ResultPtr == 0)		// Country code not found in the linked list
				printf("Country Code not found!\n");
			else					// Country code found, display data of that country
				printf("Country: %s; Country code: %s\nTotal Cases: %d\nTotal Deaths: %d\n",ResultPtr->country,ResultPtr->country_code,ResultPtr->totalCases,ResultPtr->totalDeaths);
		}
	}

	return 0;
}

// DASF004 Final Assignment 
// Written by Choi Jung Hyeon (2021313692) 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Country
{
	char Date[20];
	char CountryName[80];
	char CountryCode[3];
	int NewInfection;
	int NewDeath;
	struct Country * NextPTR;
};

struct node
{
	char country[80];
	char country_code[3];
	int totalCases;
	int totalDeaths;
	struct node * NextPtr;
};

int Length(node * chain);
void PrintALL(node * chain);
node * Find(node * chain, char * input);

int main(void)
{	
	node chain[500] = {};			// The linked list!
	node * maxTotalCases = 0;		// A pointer pointing at the node with max total infection cases
	node * maxTotalDeaths = 0;		// A pointer pointing at the node with max total death cases
	node * head = & chain[0];		// A pointer pointing at the first node of the linked list

	// Read data from the data file ("covid-19.csv").
	Country Head;
	Head.NextPTR = NULL;
	char date[20];
	char code[3];
	char name[80];
	int new_infection;
	int new_death;
	int Count_Data = 0;
	
	FILE * fPtr;
	if((fPtr = fopen("covid-19.csv", "r")) != NULL)
	{
		while(! feof(fPtr))
    	{
			// Make a new node.
			Country * NewNode;
			NewNode = (Country *) malloc(sizeof(Country));   
			NewNode->NextPTR = Head.NextPTR;
			Head.NextPTR = NewNode;
			
			// Set struct data.
			fscanf(fPtr, "%s %s %s %d %d", & date, & code, & name, & new_infection, & new_death);
			strcpy(NewNode->Date, date);
			strcpy(NewNode->CountryCode, code);
			strcpy(NewNode->CountryName, name);
			NewNode->NewInfection = new_infection;
			NewNode->NewDeath = new_death;
			Count_Data ++;
			
			/*
			printf("date: %s\n", NewNode->Date);
			printf("code: %s\n", NewNode->CountryCode);
			printf("name: %s\n", NewNode->CountryName);
			printf("new_infection: %d\n", NewNode->NewInfection);
			printf("new_death: %d\n", NewNode->NewDeath);
			*/
		}
	}
	fclose(fPtr);
	// printf("%d\n", Count_Data);
	
	// Calculate the total infection cases and total death cases for each country.
	// Construct a linked list based on the calculated results.
	Country * thisPtr = & Head;
	Country * nextPtr = thisPtr->NextPTR;
	int New_Country = 1;
	int Now_Country = 0;
	
	strcpy(head->country, nextPtr->CountryName);
	strcpy(head->country_code, nextPtr->CountryCode);
	head->totalCases = nextPtr->NewInfection;
	head->totalDeaths = nextPtr->NewDeath;
	
	/*
	printf("code: %s\n", chain[0].country_code);
	printf("name: %s\n", chain[0].country);
	printf("totalCases: %d\n", chain[0].totalCases);
	printf("totalDeaths: %d\n", chain[0].totalDeaths);
	*/
	
	for(int i = 0; i < Count_Data - 1; i++)
	{
		thisPtr = thisPtr->NextPTR;
		nextPtr = thisPtr->NextPTR;
		// printf("%d\n", strcmp(thisPtr->CountryCode, nextPtr->CountryCode));
		
		if(strcmp(thisPtr->CountryCode, nextPtr->CountryCode))					// One node, one country.
		{
			strcpy(chain[New_Country].country, nextPtr->CountryName);
			strcpy(chain[New_Country].country_code, nextPtr->CountryCode);
			chain[New_Country].totalCases = nextPtr->NewInfection;				// totalCases represents the total infection cases from day 1 to the last day in the data for one country.
			chain[New_Country].totalDeaths = nextPtr->NewDeath;					// totalDeaths represents the total death cases from day 1 to the last day in the data for one country.
			chain[Now_Country].NextPtr = & chain[New_Country];					// NextPtr points to the node for next country.	
			
			/*
			printf("New_Country: %d\n", New_Country);
			printf("code: %s\n", chain[New_Country].country_code);
			printf("name: %s\n", chain[New_Country].country);
			printf("totalCases: %d\n", chain[New_Country].totalCases);
			printf("totalDeaths: %d\n", chain[New_Country].totalDeaths);
			*/
			
			Now_Country = New_Country;
			New_Country ++;			
		}
		else
		{
			chain[Now_Country].totalCases += nextPtr->NewInfection;
			chain[Now_Country].totalDeaths += nextPtr->NewDeath;
			
			/*
			printf("Now_Country: %d\n", Now_Country);
			printf("code: %s\n", chain[Now_Country].country_code);
			printf("name: %s\n", chain[Now_Country].country);
			printf("totalCases: %d\n", chain[Now_Country].totalCases);
			printf("totalDeaths: %d\n", chain[Now_Country].totalDeaths);
			*/
		}
	}
	
	/*
	printf("code: %s\n", chain[4].country_code);
	printf("name: %s\n", chain[4].country);
	printf("totalCases: %d\n", chain[4].totalCases);
	printf("totalDeaths: %d\n", chain[4].totalDeaths);
	
	printf("code: %s\n", chain[0].country_code);
	printf("name: %s\n", chain[0].country);
	printf("totalCases: %d\n", chain[0].totalCases);
	printf("totalDeaths: %d\n", chain[0].totalDeaths);
	*/
	
	// Search the linked list for the country with maximum infection case, and then point the pointer "node * maxTotalCases" to this node.
	node * thisPtr_TC = head;
	int max_TC = thisPtr_TC->totalCases;
	// printf("%d\n", max_TC);
	
	for(int i = 0; i < Now_Country; i++)
	{
		if(max_TC < thisPtr_TC->totalCases)
		{
			max_TC = thisPtr_TC->totalCases;
			maxTotalCases = thisPtr_TC;	
		}
		thisPtr_TC = thisPtr_TC->NextPtr;
	}
	
	// Search the linked list for the country with maximum death case, and then point the pointer "node * maxTotalDeaths" to this node.
	node * thisPtr_TD = head;
	int max_TD = thisPtr_TD->totalDeaths;
	// printf("%d\n", max_TD);
	
	for(int i = 0; i < Now_Country; i++)
	{
		if(max_TD < thisPtr_TD->totalCases)
		{
			max_TD = thisPtr_TD->totalCases;
			maxTotalDeaths = thisPtr_TD;
		}
		thisPtr_TD = thisPtr_TD->NextPtr;
	}
	
	printf("There are %d countries in the data.\n", Length(chain));								// Display number of countries
	printf("Max Total Cases: %s %d\n", maxTotalCases->country, maxTotalCases->totalCases);		// Display country with maximum total infection cases
	printf("Max Total Deaths: %s %d\n", maxTotalDeaths->country, maxTotalDeaths->totalDeaths);	// Display country with maximum total death cases
		
	char Input[4];
	while(strcmp(Input, "q"))		// A loop asking for user input, and then display the corresponding data
	{	
		printf("===============================\n");
		printf("Enter the country code to display the total number of cases and total number of death of the country.\n");
		printf("Enter \"ALL\" to display all data.\n");
		printf("Enter (q to quit): ");
		scanf("%s", Input);
		
		if(! strcmp(Input, "ALL"))	// Display all data in the linked list
			PrintALL(chain);
		else
		{	
			node * ResultPtr = Find(chain, Input);
			if(ResultPtr == 0)		// Country code not found in the linked list
			{	
				if(! strcmp(Input, "q"))
					break;
				printf("Country Code not found!\n");
			}			
			else
			{						// Country code found, display data of that country
				printf("Country: %s; Country code: %s\n",  ResultPtr->country, ResultPtr->country_code);
				printf("Total Cases: %d\nTotal Deaths: %d\n", ResultPtr->totalCases, ResultPtr->totalDeaths);
			}
		}
	}
	
	printf("\n<End of Program>");
	return 0;
}

// This function takes a pointer to a linked list as parameter, and calculate the length (i.e. number of node) in the linked list as return value.
int Length(node * chain) 
{	
	node * thisPtr_L = & chain[0];
	int Count = 0;
	
	while(thisPtr_L != NULL)
	{
		Count ++;
		thisPtr_L = thisPtr_L->NextPtr;
	}
	return Count;
}

// This function takes a pointer to a linked list as parameter, and then print out all the data in the linked list. This function does not have any return value.
void PrintALL(node * chain) 
{	
	node * thisPtr_P = & chain[0];
	
	while(thisPtr_P != NULL)
	{
		printf("Country: %s; Country code: %s\n",  thisPtr_P->country, thisPtr_P->country_code);
		printf("Total Cases: %d\nTotal Deaths: %d\n", thisPtr_P->totalCases, thisPtr_P->totalDeaths);
		thisPtr_P = thisPtr_P->NextPtr;
	}
}

// This function takes a pointer to a linked list and a character string as input, and then find if there is any node that matches the country_code with the 
// character string. The function returns a pointer pointing to the node if a match is found, and returns 0 if no found.
node * Find(node * chain, char * input) 
{	
	node * thisPtr_F = & chain[0];
	
	while(thisPtr_F != NULL)
	{
		if(! strcmp(thisPtr_F->country_code, input))
			return thisPtr_F;
		else
			thisPtr_F = thisPtr_F->NextPtr;	
	}
	return 0;
}

#include "header.h"

int main()
{
	FILE* infile = fopen("UserData.csv", "r");

	Node* pHead = NULL;

	int initialChoice = 0;

	//int choice2 = 0;

	initialChoice = displayMenu();

	switch (initialChoice)
	{

	case 1: //new day
		loadData(&pHead, infile, 1);
		break;


	case 2: //same day
		loadData(&pHead, infile, 2);
		break;


	case 3: //start fresh log 
		loadData(&pHead, infile, 3);
		break;


	case 4:
		//FILE* outfile = fopen("Log.csv", "w");
		//store(pHead, outfile)
		break; //save data to file, exit program

	}

	return 0;
}
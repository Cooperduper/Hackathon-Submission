#include "header.h"

int displayMenu()
{

	char initialChoice[100] = "0";
	int choice = 0;

	printf("Type the number associated with the action you want to take:\n\n");

redisplay:

	printf("(1)	Start new day log\n");
	printf("(2)	Continue current day's log\n");
	printf("(3)	Clear all logs and start fresh\n");
	printf("(4)	Exit\n\n");

	printf("Choice: "); gets_s(initialChoice, 100); //get string from user and then convert it to an 
	//integer to avoid crashing from scanf %d for non-integers
	choice = atoi(initialChoice);

	if (choice < 1 || 3 < choice)
	{
		system("cls");
		printf("Please choose one of the numbers on the screen\n\n");
		goto redisplay;
	}


	putchar('\n');
	system("pause");
	system("cls");

	return choice;
}









void loadNewDay(Node* pList, FILE* infile, FILE* outfile)
{
	//Load prev data
	//Prompt user for new daily input








}










void loadCurrentDay(Node* pList, FILE* infile, FILE* outfile)
{
	//Load prev data up to today









}




void startNewLog(Node* pList, FILE* infile, FILE* outfile)
{








}
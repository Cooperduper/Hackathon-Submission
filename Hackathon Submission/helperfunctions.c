#include "header.h"







DailyData* getData(FILE* infile, int newLog)
{
	DailyData* newData = { (DailyData*)malloc(sizeof(DailyData)) };

	char username[100];
	int GainMaintainOrLose;
	int goalWeight;
	int maintainenceCals;
	int currentWeight;
	int dayCalories;
	int dayProtein;
	int dayCarbs;
	int dayFats;

	char line[500] = { '\0' };
	char token[100] = { '\0' };

	if (newLog == 3)
	{
		newData->dayNumber = 1;
		printf("\n1) Type your name: "); gets_s(username, 99);
		printf("\n2) Are you trying to lose weight (1), maintain weight (2), or gain weight (3)? Type the integer associated with your goals: ");	scanf("%d", &newData->GainMaintainOrLose);
		printf("\nWhat is your goal weight?"); 	scanf("%d", &newData->goalWeight);
		printf("\nWhat is your current weight?"); scanf("%d", &newData->currentWeight);
	}
	else if (newLog == 2) // adding to current day
	{

		fgets(line, 200, infile); //day number, username, weight goal, maintenance calories, weight, calories, protein, carbs, fats


		if (line[1] != '\0')
		{
			newData->dayNumber = atoi(strtok(line, ","));

			if (strstr(line, "\""))
			{
				strcpy(newData->username, (strtok(NULL, "\"")));
			}
			else
			{
				strcpy(newData->username, (strtok(NULL, ",")));
			}

			newData->GainMaintainOrLose = atoi(strtok(NULL, ","));

			newData->goalWeight = atoi(strtok(NULL, ","));

			newData->maintainenceCals = atoi(strtok(NULL, ","));

			newData->currentWeight = atoi(strtok(NULL, ","));

			newData->dayCalories = atoi(strtok(NULL, ","));;

			newData->dayProtein = atoi(strtok(NULL, ","));;

			newData->dayCarbs = atoi(strtok(NULL, ","));;

			newData->dayFats = atoi(strtok(NULL, ","));;

		}
		else if (newLog == 1)
		{

			fgets(line, 200, infile); //day number, username, weight goal, maintenance calories, weight, calories, protein, carbs, fats


			if (line[1] != '\0')
			{
				newData->dayNumber = atoi(strtok(line, ","));

				if (strstr(line, "\""))
				{
					strcpy(newData->username, (strtok(NULL, "\"")));
				}
				else
				{
					strcpy(newData->username, (strtok(NULL, ",")));
				}

				newData->GainMaintainOrLose = atoi(strtok(NULL, ","));

				newData->goalWeight = atoi(strtok(NULL, ","));

				newData->maintainenceCals = atoi(strtok(NULL, ",")); //need a function for calculating this

				newData->currentWeight = atoi(strtok(NULL, ","));

				newData->dayCalories = 0;

				newData->dayProtein = 0;

				newData->dayCarbs = 0;

				newData->dayFats = 0;

			}
			else
			{
				newData->dayNumber = 0;
			}
		}

		return newData;
	}
}







Node* makeNode(DailyData newData)
{
	Node* pNew = (Node*)malloc(sizeof(Node));

	if (pNew != NULL)
	{
		pNew->DailyLog = newData;
		pNew->pNext = NULL;
		pNew->pPrev = NULL;
		return pNew;
	}
	else
	{
		return NULL;
	}
}







int loadData(Node** pList, FILE* infile, int newLog)
{
	int count = 0;
	//open the file and parse the data into the linked list if the file isn't empty

	if (newLog == 1)
	{
		DailyData newData = *getData(infile, newLog);
		insertAtEnd(pList, newData);
	}
	else
	{
		while (!feof(infile))
		{
			if (count >= 1)
			{
				(*pList)->pPrev = (*pList); //set the pprev value
			}
			DailyData newData = *getData(infile, newLog);
			insertAtEnd(pList, newData);
			count++;
			printf("%d\n", newData.dayNumber);
		}
	}

	putchar('\n'); putchar('\n');
	system("pause");
	return count;
}








void insertAtEnd(Node** pList, DailyData newData)
{
	Node* pMem = makeNode(newData);
	Node* pCur = *pList;
	Node* pInit = *pList;

	if (*pList == NULL)
	{
		(*pList) = pMem;
	}
	else
	{
		while (pCur->pNext != NULL)
		{
			pCur = pCur->pNext;
		}

		pMem->pPrev = pCur;

		(*pList) = pCur;
		(*pList)->pNext = pMem;
	}

}





void save(Node* pList, FILE* outfile)
{
	if (pList != NULL) //Make sure pList was initialized
	{
		Node* pCur = pList;

		//print to the outfile while the node isn't empty
		while (pCur != NULL)
		{
			//if (strstr(pCur->DailyLog.dayNumber, ","))
			//{
			//	fprintf(outfile, "\"");
			//	fprintf(outfile, "%s", pCur->DailyLog.somestring);
			//	fprintf(outfile, "\",");
			//}

			fprintf(outfile, "%d,", pCur->DailyLog.dayNumber);

			pCur = pCur->pNext; //go to the next node

			if (pCur != NULL) //only print a new line if the next node isn't empty
			{				 //if an extra line is printed in the outfile it'll cause an error for the next run of the program when parsing
				fprintf(outfile, "\n");
			}
		}
	}
	else
	{
		printf("\nUse the \"load\" feature first to avoid storing an empty playlist");
	}
	putchar('\n'); putchar('\n');
	system("pause");
}

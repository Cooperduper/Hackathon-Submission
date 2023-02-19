#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////







//STRUCTS AND ENUMS //STRUCTS AND ENUMS
//STRUCTS AND ENUMS //STRUCTS AND ENUMS

//enum WeightGoal { CUT, MAINTAIN, BULK };

//typedef struct goal
//{
//	int weightgoal; ///1 = cut/lose weight///2 = maintain weight///3 = gain weight///
//	int goalweight; //Weight that you're trying to get to
//}Goal;

typedef struct dailydata
{
	int dayNumber;
	char username[100];
	int GainMaintainOrLose;
	int goalWeight;
	int maintainenceCals;
	int currentWeight;
	int dayCalories;
	int dayProtein;
	int dayCarbs;
	int dayFats;

	//char name[50]; 

	//double weight_lbs;
	//double height_in;
	//double BMI;
	//double carbs_grams;
	//double protien_grams;
	//double fats_grams; 

	//int sleep;
	//int dayofWeek;
	//int WeightGoal;
	//int steps;

}DailyData;


typedef struct node
{
	DailyData DailyLog;
	struct node* pNext;
	struct node* pPrev;
} Node;


//STRUCTS AND ENUMS //STRUCTS AND ENUMS
//STRUCTS AND ENUMS //STRUCTS AND ENUMS






////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////







//MAIN FUNCTIONS //MAIN FUNCTIONS
//MAIN FUNCTIONS //MAIN FUNCTIONS

int displayMenu();

void loadNewDay(Node* pList, FILE* infile, FILE* outfile);

void loadCurrentDay(Node* pList, FILE* infile, FILE* outfile);

void startNewLog(Node* pList, FILE* infile, FILE* outfile);

//MAIN FUNCTIONS //MAIN FUNCTIONS
//MAIN FUNCTIONS //MAIN FUNCTIONS






////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////






//HELPER FUNCTIONS //HELPER FUNCTIONS
//HELPER FUNCTIONS //HELPER FUNCTIONS

Node* makeNode(DailyData newData);

DailyData* getData(FILE* infile, int newLog);

int loadData(Node** pList, FILE* infile, int newLog);

void insertAtEnd(Node** pList, DailyData newData);

void save(Node* pList, FILE* outfile);

//double BMR_calculation(char gender, double weight, double inches, double age);


//insert node at end function

//HELPER FUNCTIONS //HELPER FUNCTIONS
//HELPER FUNCTIONS //HELPER FUNCTIONS






////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////




////////////////////// Function prototypes ////////////////////








#endif
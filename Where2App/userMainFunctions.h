#ifndef USERMAINFUNCTIONS_H_INCLUDED
#define USERMAINFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "eventFunctions.h"

void printEventDetails(char *index);     //function which prints an event with given index

//SORT FUNCTIONS
int getNumOfEventsFromFile();    //help function which gets number of events in file (FOR OPTIMISATION PURPOSE)
EVENT* getArrFromFile();        //help function which gets array of events from file

int compareName(const void *arg1, const void *arg2);    //comparator function
int compareDateTime(const void *arg1, const void *arg2);

void sortNameAtoZ(EVENT* arr, int numOfElements);
void sortNameZtoA(EVENT *arr, int numOfElements);
void sortDateTimeDesc(EVENT *arr, int numOfElements);
void sortDateTimeAsc(EVENT *arr, int numOfElements);

//FILTER FUNCTIONS
void filterToday(int d, int m, int y);
void filterAfter(int d, int m, int y);
void filterBefore(int d, int m, int y);

void filterCategory(char *categoryFilter);

void playQuiz();                         //function for playing a quiz game

#endif // USERMAINFUNCTIONS_H_INCLUDED

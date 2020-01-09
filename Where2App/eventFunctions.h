#ifndef EVENTFUNCTIONS_H_INCLUDED
#define EVENTFUNCTIONS_H_INCLUDED
/*Header file for event handling and necessary types*/

#include <stdio.h>

typedef struct event              //if you have a better idea, feel free to change this
{
    int  year,month,day,
         hours,minutes;
    char id[6],
         name[32],
         description[200],
         location[32],
         category[20];
}
EVENT;

typedef struct index
{
    int address;
    char idNum[6];
}INDEX;

typedef struct question
{
    int correctAnswer;
    char quizQuestion[100],
         answer1[25],
         answer2[25],
         answer3[25];
} QUESTION;

int eventIdSearch(char *);          //function that checks whether the event exists or not
int createNewEvent();             //function for creation of events
void readNewEvent(EVENT *,int);   //function for getting info about new event
int updateEvent();                //function for updating event info
void deleteEvent(char *eventID);  //function for deleting event

int  searchCategFile(FILE* categoriesFile, char* category);                 //function that searches for a category within a file
void placeCategory(FILE* categoriesFile, char* category);                   //function that places a new category in a file
void printCategories();                                                     //function that prints out existing categories
void deleteCategory(char* category);                                        //function that deletes selected category









#endif // EVENTFUNCTIONS_H_INCLUDED

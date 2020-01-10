#ifndef EVENTFUNCTIONS_H_INCLUDED
#define EVENTFUNCTIONS_H_INCLUDED
/*Header file for event handling and necessary types*/

#include <stdio.h>

typedef struct event
{
    int  year,month,day,
         hours,minutes,
         durationHours, durationMinutes;
    char name[32],
         id[6],
         location[32],
         description[200],
         category[20];
}
EVENT;

typedef struct index            //struct that we use when optimizing updateEvent and deleteEvent
{
    int address;
    char idNum[6];
}INDEX;

typedef struct question         //struct that we use in quiz for questions
{
    int correctAnswer;
    char quizQuestion[100],
         answer1[25],
         answer2[25],
         answer3[25];
} QUESTION;

int eventIdSearch(char *index);                     //function that checks whether the event with that ID already exists or not
int isAvailable(EVENT* event);                      //function that checks whether the location is available at that time
int createNewEvent();                               //function for creation of events
void readNewEvent(EVENT *newEvent, int control);    //function for getting info about new event
int updateEvent();                                  //function for updating event info
void deleteEvent(char *eventID);                    //function for deleting event
void updateEventLookUp(char *eventID);              //function for updating 'EventLookUp.txt' help file

int  searchCategFile(FILE* categoriesFile, char* category);                 //function that searches for a category within a file
void writeCategory(FILE* categoriesFile, char* category);                   //help function for addNewCategory() that writes a new category in a file
void addNewCategory(char* category);                                        //function which adds new category
void printCategories();                                                     //function that prints out existing categories
void deleteCategory(char* category);                                        //function that deletes selected category









#endif // EVENTFUNCTIONS_H_INCLUDED

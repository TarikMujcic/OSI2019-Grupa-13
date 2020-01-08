#ifndef EVENTFUNCTIONS_H_INCLUDED
#define EVENTFUNCTIONS_H_INCLUDED
/*Header file for event handling and necessary types*/


typedef struct event              //if you have a better idea, feel free to change this
{
    int eventID,year,month,day,hours,minutes;
    char eventName[32],
         eventDescription[200],
         eventLocation[32],
         eventCategory[20];
}
EVENT;

typedef struct index
{
    int idNum,address;
}INDEX;

typedef struct
{
    int correctAnswer;
    char quizQuestion[100],
         answer1[25],
         answer2[25],
         answer3[25];
} QUESTION;

int eventIdSearch(int );          //function that checks whether the event exists or not
int createNewEvent();             //function for creation of events
void readNewEvent(EVENT *,int);   //function for getting info about new event
int updateEvent();                //function for updating event info
void deleteEvent(int eventID);    //function for deleting event
void playQuiz();                  //function for playing a quiz game
void configureQuiz();             //function for quiz configuration



#endif // EVENTFUNCTIONS_H_INCLUDED

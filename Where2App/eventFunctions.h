#ifndef EVENTFUNCTIONS_H_INCLUDED
#define EVENTFUNCTIONS_H_INCLUDED
/*Header file for event handling and necessary types*/


typedef struct event              //if you have a better idea, feel free to change this
{
    int eventID,year,month,day,hours,minutes;
    char eventName[32],eventDescription[200],eventLocation[32],eventType[20];
}
EVENT;

typedef struct index
{
    int idNum,address;
}INDEX;

int eventIdSearch(int );              //function that checks whether the event exists or not
int createNewEvent();            //function for creation of events
void readNewEvent(EVENT *);      //function for getting info about new event

///YOU CAN ADD THE REST OF YOUR EVENT FUNCTIONS HERE

#endif // EVENTFUNCTIONS_H_INCLUDED

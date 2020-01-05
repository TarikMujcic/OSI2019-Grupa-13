#ifndef EVENTFUNCTIONS_H_INCLUDED
#define EVENTFUNCTIONS_H_INCLUDED
/*Header file for event handling and necessary types*/

typedef struct date
{
    unsigned year,month,day;
} Date;

typedef struct time
{
    unsigned hours,minutes;
} Time;

typedef struct event      //if you have a better idea, feel free to change this
{
    char eventName[32],eventDescription[200],eventLocation[32],eventType[20];
    Date eventDate;
    Time eventTime;
}
EVENT;

void createNewEvent(); //function for creation of events

#endif // EVENTFUNCTIONS_H_INCLUDED

/*Header file for event handling functions*/

#include "eventFunctions.h"
#include "adminMainFunctions.h"

int eventIdSearch(int index)
{
    FILE *fin;
    INDEX tmpIndex;
    int found=0;                    //variable that stops the loop if index was found
    if((fin=fopen("EventLookUp.txt","r"))!=NULL)
    {
        while(fscanf(fin,"%d %d",&tmpIndex.idNum,&tmpIndex.address)!=EOF && !found)
        {
            if(tmpIndex.idNum==index)
                found=1;
        }
        if(found==1)
            return 0;
        else
            return 1;
    }
    else
        return printf("ERROR! Couldn't open 'EventLookUp.txt' ...\n"),0;
}
void readNewEvent(EVENT *tmp)
{
    printf("PLEASE ENTER INFORMATION ABOUT YOUR EVENT:\n");
    printf("  Name of event:");
    scanf("%s",tmp->eventName);
    printf("  Event identification number:");
    scanf("%d",&tmp->eventID);
    printf("  Date (dd.mm.yy):");
    scanf("%d.%d.%d",&tmp->day,&tmp->month,&tmp->year);
    printf("  Time (hh:mm):");
    scanf("%d:%d",&tmp->hours,&tmp->minutes);
}
int createNewEvent()
{
    FILE *eventDatabaseFile,*eventLookUp;
    EVENT newEvent;
    INDEX eventIndex;
    readNewEvent(&newEvent);
    if(eventIdSearch(newEvent.eventID)!=0)       //if the event can be created, add it to the database
    {

        if((eventDatabaseFile=fopen("eventDatabase.dat","ab"))!=NULL)
        {
            eventIndex.address=ftell(eventDatabaseFile);
            fwrite(&newEvent,sizeof(EVENT),1,eventDatabaseFile);
            eventIndex.idNum=newEvent.eventID;
            fclose(eventDatabaseFile);
        }
        else
            printf("Error! Couldn't open event database!\n\n");
        if((eventLookUp=fopen("EventLookUp.txt","a"))!=NULL)
        {
            fprintf(eventLookUp,"%d %d\n",eventIndex.idNum,eventIndex.address);
            fclose(eventLookUp);
        }
        else
            printf("Error! Couldn't open event look-up file!\n\n");
        printf("\nYOUR EVENT WAS SUCCESSFULLY CREATED!\n\n");
        return 1;
    }
    else
        return printf("THAT EVENT CAN'T BE CREATED! PLEASE TRY AGAIN.\n\n"),0;
}

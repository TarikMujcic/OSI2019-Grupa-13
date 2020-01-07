/*Header file for event handling functions*/
///test for smartGit DT
#include "eventFunctions.h"
#include "adminMainFunctions.h"

int eventIdSearch(int index)
{
    FILE *fin;
    INDEX tmpIndex;
    int found=0,address=0;                    //found - variable that stops the loop if index was found
    if((fin=fopen("EventLookUp.txt","r"))!=NULL)
    {
        while(fscanf(fin,"%d %d",&tmpIndex.idNum,&tmpIndex.address)!=EOF && !found)
        {
            if(tmpIndex.idNum==index)
            {
                found=1;
                address=tmpIndex.address;     //save address of the event
            }
        }
        if(found==1)        //event already exists - return it's address; otherwise - return 0
            return address;
        else
            return 0;
    }
    else
        return printf("ERROR! Couldn't open 'EventLookUp.txt' ...\n"),0;
}
void readNewEvent(EVENT *tmp,int control)   //control==1 - read data about new event, control!=1 read new info about existing event
{
    printf("PLEASE ENTER INFORMATION ABOUT YOUR EVENT:\n");
    printf("  Name of event: ");
    scanf("%s", tmp->eventName);
    if(control==1)                         //we don't need a new ID number if we're just updating
    {
        printf("  Event identification number: ");
        scanf("%d",&tmp->eventID);
    }
    printf("  Add description for event: ");
    scanf("%s",tmp->eventDescription);
    printf("  Date (dd.mm.yy): ");
    scanf("%d.%d.%d",&tmp->day,&tmp->month,&tmp->year);
    printf("  Time (hh:mm): ");
    scanf("%d:%d",&tmp->hours,&tmp->minutes);
}
int createNewEvent()
{
    FILE *eventDatabaseFile,*eventLookUp;
    EVENT newEvent;
    INDEX eventIndex;
    readNewEvent(&newEvent,1);                   //second argument is 1 because we're reading info about a new event
    if(eventIdSearch(newEvent.eventID)==0)       //if the event can be created, add it to the database
    {
        //other criteria for this condition will be added later

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
int updateEvent()                  //return value: 1-successful update, 0-event doesn't exist
{
    FILE *eventDatabaseFile;
    EVENT updatedEvent;
    int address,eventID;
    printf("Enter ID of the event you want to update:");
    scanf("%d",&eventID);
    if((address=eventIdSearch(eventID))!=0)
    {
        readNewEvent(&updatedEvent,0);        //set control to 0 - function will read new info about an existing event
        if((eventDatabaseFile=fopen("eventDatabase.dat","r+b"))!=NULL)
        {
            fseek(eventDatabaseFile,address,SEEK_SET);
            fwrite(&updatedEvent,sizeof(EVENT),1,eventDatabaseFile);
            fclose(eventDatabaseFile);
            return printf("\nEvent was successfully updated!\n"),1;
        }
        else
            return printf("Error! Couldn't open file called 'eventDatabase.dat'!"),0;
    }
    else
        return printf("\nError! You can't update events that don't exist. Make sure you have a correct ID and try again!\n"),0;
}

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

void readNewEvent(EVENT *event,int control)
{
    int count=0,i,option=0;
    FILE *categoryFile;
    char categoryArray[20][20]= {},categoryHelp[20];
    if((categoryFile=fopen("eventCategory.txt","r"))!=NULL)
    {
        while(fscanf(categoryFile,"%s",categoryHelp)!=EOF)
        {
            strcpy(categoryArray[count],categoryHelp);
            count++;
        }
        fclose(categoryFile);
    }
    else
    {
        printf("Error! Can't open 'eventCategory.txt' file!\n");
        return;
    }
    printf("PLEASE ENTER INFORMATION ABOUT YOUR EVENT: \n");
    printf("  Name of event:     "); getchar(); gets(event->eventName);                   //ovaj dio je problematican; tu nastaje greska
    if(control==1)
    {
        printf("  Event ID number:   "); scanf("%d",&event->eventID);
    }
    printf("  Location:          "); getchar(); gets(event->eventLocation);
    printf("  Event description: "); fgets(event->eventDescription,199,stdin);
    printf("  Date (dd.mm.yy.):  "); scanf("%d.%d.%d.",&event->day,&event->month,&event->year);
    printf("  Time (hh:mm):      "); scanf("%d:%d",&event->hours,&event->minutes);
    if(count>0)
    {
        printf("  Choose event category:\n");
        for(i=0; i<count; i++)
            printf("    Type '%d' to select '%s'.\n", i+1, categoryArray[i]);
        char optionHelp[10];                //variable to take leftovers from the input stream
        int wrongOption = 0;                //variable to use for help to print out Error if user types in wrong option
        do
        {
            if(wrongOption)
            {
                printf("That is not a valid option! Try again! \n\n");
                gets(optionHelp);
            }
            printf("Your choice: "); scanf("%d", &option);
            wrongOption = 1;
        }
        while(option < 1 || option > count);
        strcpy(event->eventCategory, categoryArray[option - 1]);
    }
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
        system("pause");
        return 1;
    }
    else
    {
        return printf("THAT EVENT CAN'T BE CREATED! PLEASE TRY AGAIN.\n\n");
        system("pause");
        return 0;
    }
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

void deleteEvent(int eventID)
{
    FILE *eventDatabaseFile;
    EVENT emptyEvent = {0};
    int adress;                                 //variable to store adress from from eventLookUp.txt
    if((adress = eventIdSearch(eventID)) != 0)
    {
        readNewEvent(&emptyEvent,0);
        if((eventDatabaseFile=fopen("eventDatabase.dat","r+b"))!=NULL)
        {
            fseek(eventDatabaseFile,adress,SEEK_SET);
            fwrite(&emptyEvent,sizeof(EVENT),1,eventDatabaseFile);
            fclose(eventDatabaseFile);
            return printf("\nEvent was successfully deleted!\n"),1;
        }
        else
            return printf("\nError! Couldn't open file called 'eventDatabase.dat'!"),0;
    }
    else
        return printf("No event with a matching ID has been found!\n");
}

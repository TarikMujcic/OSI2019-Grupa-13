/*Header file for event handling functions*/

#include "eventFunctions.h"
#include "adminMainFunctions.h"

int eventIdSearch(char *index)
{
    FILE *fin;
    INDEX tmpIndex;
    int found=0,address=0;                    //found - variable that stops the loop if index was found
    if((fin=fopen("EventLookUp.txt","r"))!=NULL)
    {
        while(fscanf(fin,"%s %d",tmpIndex.idNum,&tmpIndex.address)!=EOF && !found)
        {
            if(!strcmp(tmpIndex.idNum, index))
            {
                found=1;
                address=tmpIndex.address;     //save address of the event
            }
        }
        if(found==1)        //event already exists - return it's address; otherwise - return 0
            return address;
        else
            return -1;
    }
    else
        return printf("ERROR! Couldn't open 'EventLookUp.txt' ...\n"),0;
}

int isAvailable(EVENT* event)
{
    FILE *eventDatabaseFile;
    if((eventDatabaseFile = fopen("eventDatabase.dat", "rb")) != NULL)
    {
        EVENT *eventTmp = (EVENT *)calloc(1, sizeof(EVENT));
        while(fread(eventTmp, 1, sizeof(EVENT), eventDatabaseFile))
        {
            if(strcmp(event->name, eventTmp->name) == 0)        //so that 2 events cant have the same name
                return printf("ERROR! That event can't be created!\That NAME is already in use by another event!\n\n"), 0;

            if(strcmp(event->location, eventTmp->location) == 0 &&                                           //if event location is equal
            eventTmp->day == event->day && eventTmp->month == event->month && eventTmp->year == event->year) //if event date is equal to another
            {
                int endTimeMTmp = eventTmp->minutes + eventTmp->durationMinutes,
                    moveTmp = 0;        //variable to move 1 hour to 'hours' if minutes are more than 60
                if(endTimeMTmp / 60)    //if its longer than 60minutes
                {
                    moveTmp = 1;
                    endTimeMTmp %= 60;
                }
                int endTimeHTmp = eventTmp->hours + eventTmp->durationHours + moveTmp;
        //------------------------------------------------------------------------------------------------------------------------
                int endTimeM = event->minutes + event->durationMinutes,
                    move = 0;        //variable to move 1 hour to 'hours' if minutes are more than 60
                if(endTimeM / 60)    //if its longer than 60minutes
                {
                    move = 1;
                    endTimeM %= 60;
                }
                int endTimeH = event->hours + event->durationHours + move;
         //-------------------------------------------------------------------------------------------------------------------------
                ///event is before eventTmp
                if(event->hours < eventTmp->hours ||
                   event->hours == eventTmp->hours && event->minutes < eventTmp->minutes)
                {
                    if(endTimeH < eventTmp->hours ||         //than end time of event must be before start time of eventTmp
                       endTimeH == eventTmp->hours && endTimeM <= eventTmp->minutes)
                    {
                        printf("Location is available!\n");
                        free(eventTmp);
                        return 1;
                    }
                    else
                    {
                        printf("ERROR! That event can't be created!\LOCATION is not available at that time!\n\n");
                        free(eventTmp);
                        return 0;
                    }
                }
                ///event is after eventTmp
                else if(event->hours > eventTmp->hours ||
                   event->hours == eventTmp->hours && event->minutes > eventTmp->minutes)
                {
                    if(endTimeHTmp < event->hours ||         //than end time of event must end before start time of eventTmp
                       endTimeHTmp == event->hours && endTimeMTmp <= event->minutes)
                    {
                        printf("Location is available!\n");
                        free(eventTmp);
                        return 1;
                    }
                    else
                    {
                        printf("ERROR! That event can't be created!\LOCATION is not available at that time!\n\n");
                        free(eventTmp);
                        return 0;
                    }
                }
            }
        }
        fclose(eventDatabaseFile);
    }
    else
        printf("ERROR! Can't open 'eventDatabase.dat' file!\n");
    return 1;
}


void readNewEvent(EVENT *event,int control)         //control == 1 for new event, control == 0 for updating old event
{
    int count=0,i,option=0;
    FILE *categoryFile;
    char categoryArray[20][20]= {},categoryHelp[20];
    if((categoryFile=fopen("eventCategory.txt","r"))!=NULL)
    {
        while(fscanf(categoryFile,"%[^\n]\n",categoryHelp)!=EOF)
        {
            strcpy(categoryArray[count],categoryHelp);
            count++;
        }
        fclose(categoryFile);
    }
    else
    {
        printf("ERROR! Can't open 'eventCategory.txt' file!\n");
        return;
    }
    char accOptionHelp[10];
    control ? gets(accOptionHelp) : control;
    printf("PLEASE ENTER INFORMATION ABOUT YOUR EVENT:\n");
    printf("  Name of event:       "); gets(event->name);
    if(control == 1)
    {
        printf("  Event ID [xxxxx]:    "); scanf("%s", event->id);
    }
    printf("  Location:            "); control ? getchar() : control ; gets(event->location);
    printf("  Event description:   "); gets(event->description);
    printf("  Date [dd.mm.yyyy.]:  "); scanf("%d.%d.%d.", &event->day, &event->month, &event->year);
    printf("  Time [hh:mm]:        "); scanf("%d:%d", &event->hours, &event->minutes);
    printf("  Duration [hh:mm]     "); scanf("%d:%d", &event->durationHours, &event->durationMinutes);
    if(count>0)
    {
        printf("  Choose event category:\n");
        for(i=0; i<count; i++)
            printf("    %-20s       -> Type in '%d'\n", categoryArray[i], i + 1);
            printf("    NEW CATEGORY               -> Type in '%d'\n", i + 1);
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
        while(option < 1 || option > count + 1);
        if(option == count + 1)
        {
            printf("\nName of the new category: "); getchar(); gets(event->category);
            addNewCategory(event->category);
        }
        else
            strcpy(event->category, categoryArray[option - 1]);
    }
}


int createNewEvent()
{
    FILE *eventDatabaseFile,*eventLookUp;
    EVENT newEvent;
    INDEX eventIndex;
    readNewEvent(&newEvent, 1);                   //second argument is 1 because we're reading info about a new event
    if(eventIdSearch(newEvent.id) == -1)          //if the event can be created, add it to the database
    {
        if(!isAvailable(&newEvent))
            return 0;

        if((eventDatabaseFile=fopen("eventDatabase.dat","ab"))!=NULL)
        {
            int confirmSuccess = fseek(eventDatabaseFile, 0, 2);        //variable to hold return value of fseek (0 if positioning is successful)
            eventIndex.address = ftell(eventDatabaseFile);              //holds the size of the current file
            fwrite(&newEvent,sizeof(EVENT),1,eventDatabaseFile);
            strcpy(eventIndex.idNum, newEvent.id);
            fclose(eventDatabaseFile);
        }
        else
            printf("Error! Couldn't open event database!\n\n");
        if((eventLookUp=fopen("EventLookUp.txt","a"))!=NULL)
        {
            fprintf(eventLookUp,"%s %d\n",eventIndex.idNum, eventIndex.address);
            fclose(eventLookUp);
        }
        else
            printf("Error! Couldn't open event look-up file!\n\n");
        printf("\nYOUR EVENT WAS SUCCESSFULLY CREATED!\n\n");
        return 1;
    }
    else
        return printf("ERROR! That event can't be created!\nID is not available!\n\n"), 0;
}


int updateEvent()                  //return value: 1-successful update, 0-event doesn't exist
{
    FILE *eventDatabaseFile;
    EVENT updatedEvent;
    int address;
    char eventID[6];
    printf("Enter ID of the event you want to update:"); getchar(); gets(eventID);
    if((address = eventIdSearch(eventID)) != -1)      //there is such event in the database
    {
        strcpy(updatedEvent.id, eventID);
        readNewEvent(&updatedEvent,0);        //set control to 0 - function will read new info about an existing event
        if((eventDatabaseFile=fopen("eventDatabase.dat","r+b"))!=NULL)
        {
            fseek(eventDatabaseFile,address,SEEK_SET);
            fwrite(&updatedEvent,sizeof(EVENT),1,eventDatabaseFile);
            fclose(eventDatabaseFile);
            return printf("\nEvent was successfully updated!\n"),1;
        }
        else
            return printf("ERROR! Couldn't open file called 'eventDatabase.dat'!"),0;
    }
    else
        return printf("\nERROR! You can't update events that don't exist. Make sure you have a correct ID and try again!\n"),0;
}

void updateEventLookUp(char *eventID)                   //function implemented into the deleteEvent function
{
    FILE *eventFile,
         *eventLookUp;
    EVENT tmpEvent;
    INDEX eventIndex;
    if((eventFile = fopen("eventDatabase.dat", "rb")) != NULL)
    {
        if((eventLookUp = fopen("EventLookUp.txt", "w")) != NULL)
        {
            eventIndex.address = ftell(eventFile);                  //addres of the first event will always be 0
            while(fread(&tmpEvent, sizeof(EVENT), 1, eventFile))
            {
                strcpy(eventIndex.idNum, tmpEvent.id);              //saving the ID of the event
                fprintf(eventLookUp,"%s %d\n",eventIndex.idNum, eventIndex.address);    //adding event ID & address into 'EventLookUp.txt'
                eventIndex.address = ftell(eventFile);                                  //saving the address for the next event
            }
            fclose(eventLookUp);
        }
        else printf("ERROR! Couldn't open file called 'EventLookUp.txt'!\n");
        fclose(eventFile);
    }
    else printf("ERROR! Couldn't open file called 'eventDatabase.dat'!\n");
}

void deleteEvent(char *eventID)
{
    FILE *eventFile,
         *tmpFile;
    EVENT tmpEvent;
    int finder = 0;
    if((eventFile = fopen("eventDatabase.dat", "rb")) != NULL)
    {
        if((tmpFile = fopen("tmpFile.dat", "wb")) != NULL)
        {
            while(fread(&tmpEvent, sizeof(EVENT), 1, eventFile))
                if(strcmp(eventID, tmpEvent.id) != 0)
                    fwrite(&tmpEvent, sizeof(EVENT), 1, tmpFile);
                else finder = 1;
            fclose(tmpFile);
        }
        else printf("ERROR! Couldn't open file called 'tmpFile.dat'!\n");
        fclose(eventFile);
    }
    else printf("ERROR! Couldn't open file called 'eventDatabase.dat'!\n");
    if(finder)
    {
        if((tmpFile = fopen("tmpFile.dat", "rb")) != NULL)
        {
            if((eventFile = fopen("eventDatabase.dat", "wb")) != NULL)
            {
                while(fread(&tmpEvent, sizeof(EVENT), 1, tmpFile))
                    fwrite(&tmpEvent, sizeof(EVENT), 1, eventFile);
                fclose(eventFile);
            }
            else printf("ERROR! Couldn't open file called 'eventDatabase.dat'!\n");
            fclose(tmpFile);
        }
        else printf("ERROR! Couldn't open file called 'tmpFile.dat'!\n");
        updateEventLookUp(eventID);
    }
    else return printf("ERROR! No matching event has been found!\n");
    printf("THE EVENT WAS SUCCESSFULLY DELETED!\n");

}

int searchCategFile(FILE* categoriesFile, char* category)
{
    char temp[21];
    while(fscanf(categoriesFile, "%[^\n]\n", temp) != EOF)
        if(strcmp(category, temp) == 0)
            return 1;
    return 0;
}

void writeCategory(FILE* categoriesFile, char* category)
{
    fprintf(categoriesFile, "%s\n", category);
    printf("\nThe category '%s' has been created.\n", category);
}

void addNewCategory(char* newCategory)
{
    FILE* categoriesFile;
    if (( categoriesFile = fopen("eventCategory.txt", "a+")) != NULL)
    {
        if(searchCategFile(categoriesFile, newCategory) == 0)
            writeCategory(categoriesFile, newCategory);
        else
            printf("A category with the same name already exists!\n");
        system("pause");
        fclose(categoriesFile);
    }
}

void printCategories()
{
    FILE* categoriesFile = NULL;
    char tmpString[21];
    if((categoriesFile = fopen("eventCategory.txt", "r")) != NULL)
    {
        printf("Existing categories:\n");
        while(fscanf(categoriesFile, "%[^\n]\n", tmpString) != EOF)
            printf("%s\n", tmpString);
        fclose(categoriesFile);
    }

}

void deleteCategory(char* category)
{
    FILE *categoriesFile = NULL,
         *tmpFile = NULL;
    char tmpString[21];
    int finder = 0;                                                 //variable which we use to confirm if we find matching category in file
    if((categoriesFile = fopen("eventCategory.txt", "r")) != NULL)
    {                                                               /*tmpFile where we place all categories that are not
                                                                      matched with the category which needs to be deleted*/
        if((tmpFile = fopen("tmpFile.txt", "w")) != NULL)
        {
            while(fscanf(categoriesFile,"%[^\n]\n", tmpString) != EOF)
            {
                if(strcmp(tmpString, category) != 0)
                    fprintf(tmpFile, "%s\n", tmpString);
                else finder++;
            }
            if(!finder)
                return printf("\nNo matching category has been found!\n");
            fclose(tmpFile);
        }
        fclose(categoriesFile);
    }
    if((tmpFile = fopen("tmpFile.txt", "r")) != NULL)
    {
        if((categoriesFile = fopen("eventCategory.txt", "w")) != NULL)
        {
            while(fscanf(tmpFile, "%[^\n]\n", tmpString) != EOF)
                fprintf(categoriesFile, "%s\n", tmpString);
            fclose(categoriesFile);
        }
        fclose(tmpFile);
    }
    printf("\nThe category '%s' has been sucessfully removed!\n", category);
}






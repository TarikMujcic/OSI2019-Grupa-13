#include "userMainFunctions.h"



void printEventDetails(char *index)
{
    FILE *eventDatabaseFile,
         *eventCommentsFile;
    EVENT *eventTmp = (EVENT*)calloc(1,sizeof(EVENT));
    if((eventDatabaseFile = fopen("eventDatabase.dat", "rb")) != NULL)
    {
        printf("EVENTS:\n");
        printf("===== ================================ ==================== ================================ =========== ===== =========\n");
        printf("ID     NAME OF THE EVENT                CATEGORY             LOCATION                         DATE       TIME  DURATION\n");
        printf("===== ================================ ==================== ================================ =========== ===== =========\n");
        while(fread(eventTmp, sizeof(EVENT), 1, eventDatabaseFile))
        {
            if(strcmp(index, eventTmp->id) == 0)
            {
                printf("%-5s %-32s %-20s %-32s %02d.%02d.%4d. %02d:%02d   %02d:%02d\n", eventTmp->id, eventTmp->name,
                                                                                        eventTmp->category, eventTmp->location,
                                                                                        eventTmp->day, eventTmp->month, eventTmp->year,
                                                                                        eventTmp->hours, eventTmp->minutes,
                                                                                        eventTmp->durationHours, eventTmp->durationMinutes);
                printf("===== ================================ ==================== ================================ =========== ===== =========\n");
                printf("DESCRIPTION: %s\n", eventTmp->description);

                /// PRINTING COMMENTS COMMENTS ---------------------------------------------------
                char fileName[21],
                     commentTmp[100];       //variable to store comments from files
                strcpy(fileName, eventTmp->id); strcat(fileName, "Comments.txt");
                printf("\nCOMMENTS:\n\n");
                if((eventCommentsFile = fopen(fileName, "r")) != NULL)
                {
                    while(fscanf(eventCommentsFile,"%[^\n]\n", commentTmp) != EOF)
                        printf("    %s\n\n",commentTmp);
                    fclose(eventCommentsFile);
                }
                else
                    printf("There are no comments about this event!\n");
                printf("===== ================================ ==================== ================================ =========== ===== =========\n");
                ///For adding comments
                printf("Do you want to add a comment:\n");
                printf("    1) YES   -> Type in '1'\n");
                printf("    2) NO    -> Type in '2'\n");
                int option;
                int wrongOption = 0;                //variable to use for help to print out Error if user types in wrong option
                char accOptionHelp[10];             //variable to take leftovers from the input stream
                do
                {
                    if(wrongOption)
                    {
                        printf("That is not a valid option! Try again!\n\n"); gets(accOptionHelp);
                    }
                    printf("Your option is:"); scanf("%d", &option);
                    wrongOption = 1;
                }
                while(option < 1 || option > 2);
                if(option == 1) //add a comment
                {
                    char comment[81],
                         commentUsername[21],
                         fullComment[103];      //comment that we will write in file
                    printf("Type in your comment: "); getchar(); gets(comment);
                    printf("Type in your username for comment: "); gets(commentUsername);
                    strcpy(fullComment, commentUsername);
                    strcat(fullComment, ": ");
                    strcat(fullComment, comment);
                    if((eventCommentsFile = fopen(fileName, "a")) != NULL)
                    {
                        fprintf(eventCommentsFile, "%s\n", fullComment);
                        fclose(eventCommentsFile);
                    }
                    else
                        printf("ERROR! Can't open '%s' file!\n", fileName);
                }
            }
        }
        fclose(eventDatabaseFile);
        free(eventTmp);
    }
    else
        printf("ERROR! Can't open 'eventDatabase.dat' file!\n");
}

///SORT FUNCTIONS

int getNumOfEventsFromFile()    //just for counting the number of elements
{
    FILE *eventDatabaseFile;
    int counter = 0;
    EVENT eventTmp;
    if((eventDatabaseFile = fopen("eventDatabase.dat", "rb")) != NULL)
    {
        while(fread(&eventTmp, 1, sizeof(EVENT), eventDatabaseFile))
            counter++;
        fclose(eventDatabaseFile);
        return counter;
    }
    else
        printf("ERROR! Can't open 'eventDatabase.dat' file!\n");
}

EVENT* getArrFromFile()
{
    FILE *eventDatabaseFile;
    int numOfElements = getNumOfEventsFromFile();
    int i = 0; //for while loop
    EVENT *arrEvents = (EVENT *)calloc(numOfElements, sizeof(EVENT));
    if((eventDatabaseFile = fopen("eventDatabase.dat", "rb")) != NULL)
    {
        while(fread(&arrEvents[i++], 1, sizeof(EVENT), eventDatabaseFile));

        fclose(eventDatabaseFile);
        return arrEvents;       //return the complete array
    }
    else
        printf("ERROR! Can't open 'eventDatabase.dat' file!\n");
}


int compareName(const void *arg1, const void *arg2)
{
    return strcmp( ((EVENT*)arg1)->name, ((EVENT *)arg2)->name );
}
int compareDateTime(const void *arg1, const void *arg2)
{
    EVENT a = *((EVENT *)arg1),
          b = *((EVENT *)arg2);
    if(a.year > b.year ||
       a.year == b.year && a.month > b.month ||
       a.year == b.year && a.month == b.month && a.day > b.day ||
       a.year == b.year && a.month == b.month && a.day == b.day && a.hours > a.minutes ||
       a.year == b.year && a.month == b.month && a.day == b.day && a.hours == a.minutes && a.minutes > b.minutes)
            return 1;
    else
        return -1;
}


void sortNameAtoZ(EVENT* arr, int numOfElements)
{
    qsort(arr, numOfElements, sizeof(EVENT), compareName);
    printf("SORTED BY NAME (DESCENDING) EVENTS:\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    printf("ID     NAME OF THE EVENT                CATEGORY             LOCATION                         DATE       TIME  DURATION\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    for(int i = 0; i < numOfElements; i++)
    {
        printf("%-5s %-32s %-20s %-32s %02d.%02d.%4d. %02d:%02d   %02d:%02d\n", arr[i].id, arr[i].name, arr[i].category, arr[i].location,
                                                                        arr[i].day, arr[i].month, arr[i].year,
                                                                        arr[i].hours, arr[i].minutes,
                                                                        arr[i].durationHours, arr[i].durationMinutes);
    }
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");


}

void sortNameZtoA(EVENT* arr, int numOfElements)
{
    qsort(arr, numOfElements, sizeof(EVENT), compareName);
    printf("SORTED BY NAME (DESCENDING) EVENTS:\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    printf("ID     NAME OF THE EVENT                CATEGORY             LOCATION                         DATE       TIME  DURATION\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    for(int i = numOfElements - 1; i >= 0; i--)
    {
        printf("%-5s %-32s %-20s %-32s %02d.%02d.%4d. %02d:%02d   %02d:%02d\n", arr[i].id, arr[i].name, arr[i].category, arr[i].location,
                                                                        arr[i].day, arr[i].month, arr[i].year,
                                                                        arr[i].hours, arr[i].minutes,
                                                                        arr[i].durationHours, arr[i].durationMinutes);
    }
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
}

void sortDateTimeDesc(EVENT* arr, int numOfElements)
{
    qsort(arr, numOfElements, sizeof(EVENT), compareDateTime);
    printf("SORTED BY NAME (DESCENDING) EVENTS:\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    printf("ID     NAME OF THE EVENT                CATEGORY             LOCATION                         DATE       TIME  DURATION\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    for(int i = 0; i < numOfElements; i++)
    {
        printf("%-5s %-32s %-20s %-32s %02d.%02d.%4d. %02d:%02d   %02d:%02d\n", arr[i].id, arr[i].name, arr[i].category, arr[i].location,
                                                                        arr[i].day, arr[i].month, arr[i].year,
                                                                        arr[i].hours, arr[i].minutes,
                                                                        arr[i].durationHours, arr[i].durationMinutes);
    }
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");

}

void sortDateTimeAsc(EVENT* arr, int numOfElements)
{
    qsort(arr, numOfElements, sizeof(EVENT), compareDateTime);
    printf("SORTED BY NAME (DESCENDING) EVENTS:\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    printf("ID     NAME OF THE EVENT                CATEGORY             LOCATION                         DATE       TIME  DURATION\n");
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
    for(int i = numOfElements - 1; i >= 0; i--)
    {
        printf("%-5s %-32s %-20s %-32s %02d.%02d.%4d. %02d:%02d   %02d:%02d\n", arr[i].id, arr[i].name, arr[i].category, arr[i].location,
                                                                        arr[i].day, arr[i].month, arr[i].year,
                                                                        arr[i].hours, arr[i].minutes,
                                                                        arr[i].durationHours, arr[i].durationMinutes);
    }
    printf("===== ================================ ==================== ================================ =========== ===== =========\n");
}











void playQuiz()
{
    FILE *quizFile=NULL;
    int score=0,i=0,n=10,answer[n];
    char optionHelp[20];
    QUESTION *quiz=(QUESTION*)calloc(n,sizeof(QUESTION)),tmp;
    if((quizFile=fopen("Quiz.dat","rb"))!=NULL)
    {
        while(fread(&tmp,sizeof(QUESTION),1,quizFile))
            quiz[i++]=tmp;
        fclose(quizFile);
    }
    else
    {
        printf("\nError! Couldn't open 'Quiz.dat'. File moved or missing!\n");
        return;
    }
    printf("===============================================\n");
    for(i=0; i<n; i++)
    {
        printf("Question %d: %s\n",i+1,quiz[i].quizQuestion);
        printf("    1) %s\n",quiz[i].answer1);
        printf("    2) %s\n",quiz[i].answer2);
        printf("    3) %s\n",quiz[i].answer3);
        int wrongOption = 0;        //variable to use for help to print out Error if user types in wrong option
        do
        {
            if(wrongOption)
            {
                printf("That is not a valid answer! Try again! \n\n");
                gets(optionHelp);
            }
            printf(" Choose your answer:");
            scanf("%d",&answer[i]);
            wrongOption = 1;
        }
        while(answer[i]<1 || answer[i]>3);
        if(answer[i]==quiz[i].correctAnswer)
            score++;
    }
    printf("===============================================\n");
    if(score==n)
        printf("CONGRATULATIONS! ");
    printf("Your score is: %d/%d",score,n);
    free(quiz);
}

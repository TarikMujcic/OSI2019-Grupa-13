/*C file for some functions for printing out
something to the console in certain format*/

#include "gui.h"
#include "eventFunctions.h"

void printWelcomeScreen()
{
    printf("==========================================================\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||                WELCOME TO WHERE2 APP !               ||\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("==========================================================\n");
}

void printLoading()
{
    printf("\n");
    printf("                      LOADING...                   \n");
    printf("||=============");Sleep(1200);
                    printf("=========================");Sleep(1800);
                                             printf("================||\n");Sleep(750);
}

void welcomeScreenGui()
{
    printWelcomeScreen();
    printLoading();
    Sleep(500);
}

void printUserOptions()
{
    printf("==========================================================\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||                       USE APP AS:                    ||\n");
    printf("||           1) USER           -> Type in '1'           ||\n");
    printf("||           2) ADMINISTRATOR  -> Type in '2'           ||\n");
    printf("||                           OR:                        ||\n");
    printf("||           3) EXIT THE APP   -> Type in '3'           ||\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("==========================================================\n");
    printf("\n");
}

void printEventsInFormat()
{
    FILE *eventDatabaseFile;
    EVENT *eventTmp = (EVENT*)calloc(1,sizeof(EVENT));
    if((eventDatabaseFile = fopen("eventDatabase.dat", "rb")) != NULL)
    {
        printf("EVENTS:\n");
        printf("===== ================================ ==================== ================================ =========== =====\n");
        printf("ID     NAME OF THE EVENT                CATEGORY             LOCATION                         DATE        TIME \n");
        printf("===== ================================ ==================== ================================ =========== =====\n");
        while(fread(eventTmp, sizeof(EVENT), 1, eventDatabaseFile))
        {
            printf("%-5s %-32s %-20s %-32s %02d.%02d.%4d. %02d:%02d\n", eventTmp->id, eventTmp->name, eventTmp->category, eventTmp->location,
                                                                        eventTmp->day, eventTmp->month, eventTmp->year,
                                                                        eventTmp->hours, eventTmp->minutes);
            printf("      DESCRIPTION:\n      %s\n", eventTmp->description);
        printf("----- -------------------------------- -------------------- -------------------------------- ----------- -----\n");
        }
        fclose(eventDatabaseFile);
        printf("===== ================================ ==================== ================================ =========== =====\n");
    }
    else
        printf("ERROR! Can't open 'eventDatabase.dat' file!\n");
}


///For adminMain//////////////////////////////////////////////////////////

void printLogRegOptions()
{
    system("cls");
    printf("==========================================================\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||              CHOOSE AN OPTION:                       ||\n");
    printf("||  1) LOGIN(already have an account) -> Type in '1'    ||\n");
    printf("||  2)         REGISTER               -> Type in '2'    ||\n");
    printf("||  3)          CANCEL                -> Type in '3'    ||\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("==========================================================\n");
    printf("\n");
}

void printOptionsAdminPart()
{
    system("cls");
    printf("==========================================================\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||                CHOOSE AN OPTION:                     ||\n");
    printf("||        1) CREATE AN EVENT    -> Type in '1'          ||\n");
    printf("||        2) UPDATE AN EVENT    -> Type in '2'          ||\n");
    printf("||        3) DELETE AN EVENT    -> Type in '3'          ||\n");
    printf("||        4) ADD NEW CATEGORY   -> Type in '4'          ||\n");
    printf("||        5) DELETE A CATEGORY  -> Type in '5'          ||\n");
    printf("||        6) CONFIGURE A QUIZ   -> Type in '6'          ||\n");
    printf("||        7) EXIT               -> Type in '7'          ||\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("==========================================================\n");
    printf("\n");
}

void printRegLoading()
{
    printf("\n");
    printf("                 REGISTRATION IN PROCESS...               \n");
    printf("||=============");Sleep(1200);
                    printf("=========================");Sleep(1800);
                                             printf("================||\n");Sleep(750);
}


///For userMain////////////////////////////////////////////////////////////

void printOptionsUserPart()
{
    system("cls");
    printf("==========================================================\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||           CHOOSE AN OPTION:                          ||\n");
    printf("||           1) VIEW EVENTS       -> Type in '1'        ||\n");
    printf("||           2) PLAY QUIZ         -> Type in '2'        ||\n");
    printf("||           3) EXIT              -> Type in '3'        ||\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("==========================================================\n");
    printf("\n");
}


///For exitMain////////////////////////////////////////////////////////////
void printGoodbye()
{
    printf("           GOODBYE AND HAVE A NICE DAY !           \n");
    printf("||=============");Sleep(1200);
                    printf("=========================");Sleep(1800);
                                             printf("================||\n");Sleep(750);
}

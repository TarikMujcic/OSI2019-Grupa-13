/*C file for some functions for printing out
something to the console in certain format*/

#include "gui.h"

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
                    printf("======================");Sleep(1800);
                                         printf("============||\n");Sleep(1000);
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


///For adminMain//////////////////////////////////////////////////////////

void printLogRegOptions()
{
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
    printf("==========================================================\n");
    printf("||                                                      ||\n");
    printf("||                                                      ||\n");
    printf("||                CHOOSE AN OPTION:                     ||\n");
    printf("||        1) CREATE AN EVENT    -> Type in '1'          ||\n");
    printf("||        2) UPDATE AN EVENT    -> Type in '2'          ||\n");
    printf("||        3) DELETE AN EVENT    -> Type in '3'          ||\n");
    printf("||        4) ADD NEW CATEGORY   -> Type in '4'          ||\n");
    printf("||        5) DELETE A CATEGORY  -> Type in '5'          ||\n");
    printf("||        6) EXIT               -> Type in '6'          ||\n");
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
                    printf("======================");Sleep(1800);
                                         printf("============||\n");Sleep(1000);
    system("cls");
}

///For userMain////////////////////////////////////////////////////////////


///For exitMain////////////////////////////////////////////////////////////
void printGoodbye()
{
    printf("           GOODBYE AND HAVE A NICE DAY !           \n");
        printf("||=============");Sleep(1200);
                        printf("======================");Sleep(1800);
                                             printf("============||\n");Sleep(1000);
}

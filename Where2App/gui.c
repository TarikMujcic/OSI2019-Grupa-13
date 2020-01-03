/*C file for some functions for printing out
something to the consoli in certain format*/

#include "gui.h"

void printWelcomeScreen()
{
    printf("===================================================\n");
    printf("||                                               ||\n");
    printf("||                                               ||\n");
    printf("||                                               ||\n");
    printf("||            WELCOME TO WHERE2 APP !            ||\n");
    printf("||                                               ||\n");
    printf("||                                               ||\n");
    printf("||                                               ||\n");
    printf("===================================================\n");
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
    printf("===================================================\n");
    printf("||                                               ||\n");
    printf("||                                               ||\n");
    printf("||                   USE APP AS:                 ||\n");
    printf("||       1) USER           -> Type in '1'        ||\n");
    printf("||       2) ADMINISTRATOR  -> Type in '2'        ||\n");
    printf("||                       OR:                     ||\n");
    printf("||       3) EXIT THE APP   -> Type in '3'        ||\n");
    printf("||                                               ||\n");
    printf("||                                               ||\n");
    printf("===================================================\n");
    printf("\n");
}

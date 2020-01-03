#ifndef ADMINMAINFUNCTIONS_H_INCLUDED
#define ADMINMAINFUNCTIONS_H_INCLUDED
/*Header file for functions used in the
administrator part of the application*/

#include <stdio.h>
#include <windows.h>                 //for sleep function

typedef struct admin
{
    char username[21],
         password[21];
}ADMIN;

void maskPassword(char *password);   //help function for login() and registration() - to hide the password when typing
void printLogRegOptions();           //help function for logRegForm() - to print out options
void registration();                 //help function for logRegForm() - to make a new registration
void login();                        //help function for logRegForm() - to login into existing account
int logRegForm();

void printOptionsAdminPart();



#endif // ADMINMAINFUNCTIONS_H_INCLUDED

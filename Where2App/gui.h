#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
/*Header file for some functions for printing out
something to the consoli in certain format*/

#include <stdio.h>
#include <windows.h>            //for Sleep function

void printWelcome();            //help function for welcomeScreenGui()
void printLoading();            //help function for welcomeScreenGui()
void welcomeScreenGui();

void printUserOptions();        //function to print out options for which part of app will user use

///For adminMain

void printLogRegOptions();     //help function for logRegForm() (from adminMainFunctions) - to print out options
void printOptionsAdminPart();  //help function to print out options for admins
void printRegLoading();

///For userMain


///For exitMain
void printGoodbye();            //function to print out goodbye message on the screen



#endif // GUI_H_INCLUDED

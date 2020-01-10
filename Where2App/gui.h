#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
/*Header file for some functions for printing out
something to the console in certain format*/

#include <stdio.h>
#include <windows.h>            //for Sleep function

void printWelcome();            //help function for welcomeScreenGui()
void printLoading();            //help function for welcomeScreenGui()
void welcomeScreenGui();

void printUserOptions();        //function to print out options for which part of app will user use

void printEventsInFormat();     //function to print out events from file in format

///For adminMain

void printLogRegOptions();      //help function for logRegForm() (from adminMainFunctions) - to print out options
void printOptionsAdminPart();   //function to print out options for admins
void printRegLoading();

///For userMain

void printOptionsUserPart();    //function to print out options for regular users
void printEventOptions();       //function to print out options for events(sorting, filtering, commenting)
void printSortOptions();        //function to print out options for sorting
void printFilterOptions();      //function to print out options for filtering

///For exitMain
void printGoodbye();            //function to print out goodbye message on the screen



#endif // GUI_H_INCLUDED

#ifndef USERINPUTVALIDATION_H_INCLUDED
#define USERINPUTVALIDATION_H_INCLUDED
/*Header file for functions that check whether the information
provided by user is correct/available for use or not*/

int validAccountOption(char *userInput);    //function that checks data provided by user for account option
int availableUsername(char *username);      //function that checks if provided username is already taken or not

#endif // USERINPUTVALIDATION_H_INCLUDED

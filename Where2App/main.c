#include <stdio.h>
#include <stdlib.h>

#include "gui.h"


//Version 2.1.2020.  (1)
int main()
{
    int accountOption;          //variable to store the option that user chooses for which part of app he wants to use

    welcomeScreenGui();         //function for welcome screen and loading
    do                          //in the rest of the code i will be referring to this do...while loop as: FIRST(MAIN) DO...WHILE LOOP
    {
        system("cls");          // to clear the console
        int wrongOption = 0;    //variable to use for help to print out Error if user types in wrong option
        printUserOptions();

        do
        {
            if(wrongOption)
                printf("That is not a valid option !\n\n");
            printf("Your option is:");
            scanf("%d",&accountOption);
            wrongOption = 1;
        }
        while (accountOption < 1 || accountOption > 3);

        //===================================================== accountOption == USER =======================================================
        if(accountOption == 1)
        {

        }

        //===================================================== accountOption == ADMIN ======================================================
        else if(accountOption == 2)
        {
            adminMain();
        }

        //=====================================================  EXIT THE APP ===============================================================
        else if(accountOption == 3) // or just else
        {
            accountOption = exitMain();
        }
    }
    while(accountOption != -1);
    return 0;
}

/*NOTES:
1. Check how to center text in the console
2. In the adminMainFunctions.c we need to check in the registration() function whether the username is available or not (its marked with a comment)
3.We need to modify the logRegForm() function so it has an option #3 - to cencel loging or registrating if the user wants to cancel
    (its marked with a comment)
4.
*/

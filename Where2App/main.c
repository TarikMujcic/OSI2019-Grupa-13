#include <stdio.h>
#include <stdlib.h>

#include "gui.h"
#include "userInputValidation.h"
#include "adminMainFunctions.h"
#include "eventFunctions.h"

//Version 2.1.2020.  (1)
int main()
{
    int  accountOption;         //variable to store the option that user chooses for which part of app he wants to use

    welcomeScreenGui();         //function for welcome screen and loading
    do                          //in the rest of the code i will be referring to this do...while loop as: FIRST(MAIN) DO...WHILE LOOP
    {
        system("cls");          // to clear the console
        int wrongOption = 0;    //variable to use for help to print out Error if user types in wrong option
        printUserOptions();

        char accOptionHelp[10];     //variable to take leftovers from the input stream
        do
        {
            if(wrongOption)
            {
                printf("That is not a valid option! Try again!\n\n");
                gets(accOptionHelp);
            }
            printf("Your option is:"); scanf("%d", &accountOption);
            wrongOption = 1;

        }
        while (accountOption < 1 || accountOption > 3);

        //===================================================== accountOption == USER =======================================================
        if(accountOption == 1)
        {
            userMain();
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
1. Check how to center text in the console and how to open in full screen - THIS OPTION CAN BE ADDED LATER PROVIDED WE HAVE ENOUGH TIME
2. In the adminMainFunctions.c we need to check in the registration() function whether the username is available or not (its marked with a comment)  -DONE!
3. Make corrections inside the FIRST(MAIN) DO...WHILE LOOP so we avoid infinite loop     -DONE!
4. Make all gui.c "rectangles" equal in width (find the widest and make all of them equaly wide)  -DONE!

*/

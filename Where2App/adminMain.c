/*C file for #3 option in FIRST(MAIN) DO...WHILE LOOP
(for Administrator part of the app)*/

#include "adminMainFunctions.h"

void adminMain()
{
    printLogRegOptions();
    int successfulLogin = logRegForm();         //variable to check if the login was successful
    ///We need to modify the logRegForm() function so it has an option #3 - to cencel loging or registrating if the user wants to cancel
    if(successfulLogin == 1)
    {
        printOptionsAdminPart();
        int wrongOption = 0,            //variable to use for help to print out Error if user types in wrong option
        option;
        do
        {
            if(wrongOption)
                printf("That is not a valid option! Try again! \n\n");
            printf("Your choice: ");
            scanf("%d",&option);
            wrongOption = 1;
        }
        while(option < 1 || option > 6);
    }
    else
        return;
}

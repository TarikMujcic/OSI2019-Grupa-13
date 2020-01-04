/*C file for #3 option in FIRST(MAIN) DO...WHILE LOOP
(for Administrator part of the app)*/

#include "adminMainFunctions.h"

void adminMain()
{
    int successfulLogin = logRegForm();         //variable to check if the login was successful
    if(successfulLogin == 1)
    {
        int option;                         //variable to take the number for users option
        do
        {
            system("cls");
            printOptionsAdminPart();
            int wrongOption = 0;            //variable to use for help to print out Error if user types in wrong option
            do
            {
                if(wrongOption)
                    printf("That is not a valid option! Try again! \n\n");
                printf("Your choice: ");
                scanf("%d",&option);
                wrongOption = 1;
            }
            while(option < 1 || option > 6);

            ///////////---------------------------------------   C R E A T E    E V E N T  ------------------------------------------------------------
            if(option == 1)
            {

            }
            ///////////---------------------------------------   U P D A T E    E V E N T  ------------------------------------------------------------
            else if(option == 2)
            {

            }
            ///////////---------------------------------------   D E L E T E   E V E N T  -------------------------------------------------------------
            else if(option == 3)
            {

            }
            ///////////---------------------------------------  A D D    C A T E G O R Y  -------------------------------------------------------------
            if(option == 4)
            {

            }
            ///////////-----------------------------------  D E L E T E    C A T E G O R Y  -----------------------------------------------------------
            else if(option == 5)
            {

            }
            ///////////---------------------------------------------------   E X I T   ----------------------------------------------------------------
            else if(option == 6)
            {
                option = -1;
            }
        }
        while(option != -1)


    }
    else
        return;

}

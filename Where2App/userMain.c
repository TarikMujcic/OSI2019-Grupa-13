/*C file for #3 option in FIRST(MAIN) DO...WHILE LOOP
(for unregistered User part of the app)*/

#include "gui.h"
#include "eventFunctions.h"

void userMain()
{
    int option;                             //variable to take the number for users option
    char optionHelp[10];                    //variable to take leftovers from the input stream
    do
    {
        system("cls");
        printOptionsUserPart();
        int wrongOption = 0;                //variable to use for help to print out Error if user types in wrong option
        do
        {
            if(wrongOption)
            {
                printf("That is not a valid option! Try again! \n\n");
                gets(optionHelp);
            }
            printf("Your choice: "); scanf("%d",&option);
            wrongOption = 1;
        }
        while(option < 1 || option > 3);

        ///////////---------------------------------------   V I E W   E V E N T S ------------------------------------------------------------
        if(option == 1)
        {
            printEventsInFormat();
            system("pause");
        }
        ///////////---------------------------------------   P L A Y    Q U I Z     -----------------------------------------------------------
        else if(option == 2)
        {

        }
        ///////////--------------------------------------------    E X I T   ------------------------------------------------------------------
        else if(option == 3)
        {
            option = -1;
        }
    }
    while(option != -1);


}

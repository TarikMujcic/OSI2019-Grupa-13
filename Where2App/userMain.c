/*C file for #3 option in FIRST(MAIN) DO...WHILE LOOP
(for unregistered User part of the app)*/

#include "gui.h"
#include "eventFunctions.h"
#include "userMainFunctions.h"

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
            int optionView;                         //variable to take the number for users option in "VIEW EVENTS"
            char optionHelp[10];                    //variable to take leftovers from the input stream
            do
            {
                system("cls");
                printEventsInFormat();

                printEventOptions();
                int wrongOption = 0;                //variable to use for help to print out Error if user types in wrong option
                do
                {
                    if(wrongOption)
                    {
                        printf("That is not a valid option! Try again! \n\n");
                        gets(optionHelp);
                    }
                    printf("Your choice: "); scanf("%d",&optionView);
                    wrongOption = 1;
                }
                while(optionView < 1 || optionView > 4);

                ///IF optionView == 1 --> SEE EVENT DETAILS OR COMMENT----------------------------------------
                if (optionView == 1)
                {
                    char eventID[6];
                    int address;
                    printf("Enter ID of the event which description and comments you want to see:"); getchar(); gets(eventID);
                    if((address = eventIdSearch(eventID)) != -1)      //there is such event in the database
                    {
                        printEventDetails(eventID);
                    }
                    else
                        printf("\nERROR! Event with such ID does not exist! Make sure you have a correct ID and try again!\n");
                    system("pause");
                }
                ///IF optionView == 2 --> SORT EVENTS-----------------------------------------------------------
                else if(optionView == 2)
                {
                    printSortOptions();
                    int wrongOption = 0;                //variable to use for help to print out Error if user types in wrong option
                    int optionSort;
                    do
                    {
                        if(wrongOption)
                        {
                            printf("That is not a valid option! Try again! \n\n");
                            gets(optionHelp);
                        }
                        printf("Your choice: "); scanf("%d",&optionSort);
                        wrongOption = 1;
                    }
                    while(optionSort < 1 || optionSort > 4);
                    if(optionSort == 1)
                        sortNameAtoZ(getArrFromFile(), getNumOfEventsFromFile());
                    else if(optionSort == 2)
                        sortNameZtoA(getArrFromFile(), getNumOfEventsFromFile());
                    else if(optionSort == 3)
                        sortDateTimeDesc(getArrFromFile(), getNumOfEventsFromFile());
                    else if(optionSort == 4)
                        sortDateTimeAsc(getArrFromFile(), getNumOfEventsFromFile());


                }
                ///IF optionView == 3 --> FILTER EVENTS-----------------------------------------------------------------
                else if(optionView == 3)
                {

                }
                ///IF optionView == 4 --> EXIT-------------------------------------------------------------------------
                else if(optionView == 4)
                {
                    optionView = -1;
                }
                system("pause");
            }
            while(optionView != -1);

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

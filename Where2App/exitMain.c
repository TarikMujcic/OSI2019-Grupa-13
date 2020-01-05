/*C file for #3 option in FIRST(MAIN) DO...WHILE LOOP
(for exiting the app)*/

#include "gui.h"

int exitMain()               //int is because it needs to check if the user is sure to exit the app
{
    int  wrongOption = 0,    //variable to use for help to print out Error if user types in wrong option
         option = 0;         //variable to take the number for users option
    char optionHelp[10];     //variable to take leftovers from the input stream
    printf("\n  ARE YOU SURE THAT YOU WANT TO EXIT THE APP ???\n");
    printf("         1) YES           -> Type in '1'          \n");
    printf("         2) NO (CANCEL)   -> Type in '2'          \n");
    do
    {
        if(wrongOption)
        {
            printf("That is not a valid option !\n\n");
            gets(optionHelp);
        }
        printf("Your choice: "); scanf("%d",&option);
        wrongOption = 1;
    }
    while(option != 1 && option != 2);

    if(option == 1)
    {
        printf("\n");
        printGoodbye();
        return -1;      //TO EXIT THE APP

    }
    else if(option == 2)
    {
        return 0;
    }
}

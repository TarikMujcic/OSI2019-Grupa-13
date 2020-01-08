/*C file for #3 option in FIRST(MAIN) DO...WHILE LOOP
(for Administrator part of the app)*/

#include "adminMainFunctions.h"
#include "eventFunctions.h"

void adminMain()
{
    int successfulLogin = logRegForm();         //variable to check if the login was successful
    if(successfulLogin == 1)
    {
        int option;                             //variable to take the number for users option
        char optionHelp[10];                    //variable to take leftovers from the input stream
        do
        {
            printOptionsAdminPart();
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
            while(option < 1 || option > 6);

            ///////////---------------------------------------   C R E A T E    E V E N T  ------------------------------------------------------------
            if(option == 1)
            {
               createNewEvent();
            }
            ///////////---------------------------------------   U P D A T E    E V E N T  ------------------------------------------------------------
            else if(option == 2)
            {

            }
            ///////////---------------------------------------   D E L E T E   E V E N T  -------------------------------------------------------------
            else if(option == 3)
            {
                //add function which prints out events so the user can see event ID's
                int eventID;
                printf("Event ID: ");
                scanf("%d", &eventID);
                deleteEvent(eventID);
            }
            ///////////---------------------------------------  A D D    C A T E G O R Y  -------------------------------------------------------------
            if(option == 4)
            {
                char newCategory[21];
                FILE* categoriesFile;
                printf("\nName of category: "); getchar(); gets(newCategory);
                if (( categoriesFile = fopen("eventCategory.txt", "a+")) != NULL)
                {
                    if(searchCategFile(categoriesFile, newCategory) == 0)
                        placeCategory(categoriesFile, newCategory);
                    else
                        printf("A category with the same name already exists!\n");
                    system("pause");
                    fclose(categoriesFile);
                }
            }
            ///////////-----------------------------------  D E L E T E    C A T E G O R Y  -----------------------------------------------------------
            else if(option == 5)
            {
                char category[21];
                printCategories();
                printf("\nName of category: ");
                scanf("%s", category);
                deleteCategory(category);
            }
            ///////////---------------------------------------------------   E X I T   ----------------------------------------------------------------
            else if(option == 6)
            {
                option = -1;
            }
        }
        while(option != -1);


    }
    else
        return;

}

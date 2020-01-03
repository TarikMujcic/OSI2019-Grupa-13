/*C file for #3 option in FIRST(MAIN) DO...WHILE LOOP
(for exiting the app)*/

int exitMain()              //int is because it needs to check if the user is sure to exit the app
{
    int wrongOption = 0,    //variable to use for help to print out Error if user types in wrong option
        option = 0;
    printf("\n  ARE YOU SURE THAT YOU WANT TO EXIT THE APP ???\n");
    printf("         1) YES           -> Type in '1'          \n");
    printf("         2) NO (CANCEL)   -> Type in '2'          \n");
    do
    {
        if(wrongOption)
            printf("That is not a valid option !\n\n");
        printf("Your choice: ");
        scanf("%d",&option);
        wrongOption = 1;
    }
    while(option != 1 && option != 2);

    if(option == 1)
    {
        printf("\n");
        printf("           GOODBYE AND HAVE A NICE DAY !           \n");
        printf("||=============");Sleep(1200);
                        printf("======================");Sleep(1800);
                                             printf("============||\n");Sleep(1000);
        return -1;      //TO EXIT THE APP

    }
    else if(option == 2)
    {
        return 0;
    }
}

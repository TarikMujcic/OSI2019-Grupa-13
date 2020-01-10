/*C file for functions used in the
administrator part of the application*/

#include "adminMainFunctions.h"
#include "userInputValidation.h"

#include <conio.h>  //for getch() used in maskPassword


void openEventLookUp()
{
    FILE *fp;
    if((fp = fopen("eventLookUp.txt", "w")) != NULL)
        fclose(fp);
}

void maskPassword(char *password)
{
    char cHelp;
    int i = 0;
    while((cHelp = getch()) != '\r')
    {
        if(cHelp == 8 && i != 0)            //special case - when user tries to delete a letter in password
        {
            printf("\b \b");
            i--;
        }
        else
        {
            password[i] = cHelp;
            printf("*");
            i++;
        }
    }
    password[i] = '\0';
}


void registration()
{
    FILE *databaseAdminFile;
    ADMIN newRegAdmin;
    char repeatPassword[21];

    REGISTRATIONLABEL:

    printf("NEW REGISTRATION: \n");
    printf("USERNAME: ");               scanf("%s",newRegAdmin.username);
    if((databaseAdminFile = fopen("databaseAdmin.dat", "wb")) != NULL)         //to solve issues when trying to use admin part for the first time
        fclose(databaseAdminFile);
    if(availableUsername(newRegAdmin.username)==0)
    {
        printf("This username is already taken! Please choose another one!\n\n");
        goto REGISTRATIONLABEL;
    }
    printf("PASSWORD: ");               maskPassword(newRegAdmin.password);
    printf("\n");

    printf("REPEAT YOUR PASSWORD: ");   maskPassword(repeatPassword);
    printf("\n");

    if(strcmp(newRegAdmin.password,repeatPassword) == 0)        //if password is a match than place that user in data base
    {
        if((databaseAdminFile = fopen("databaseAdmin.dat","ab")) != NULL)
        {
            fwrite(&newRegAdmin, sizeof(ADMIN), 1, databaseAdminFile);
            fclose(databaseAdminFile);
            return;
        }
        else
        {
            printf("ERROR !!! CAN'T OPEN 'databaseAdmin.dat' FILE !!!\n");
            return;
        }
    }
    else
    {
        printf("Passwords are not the same! Try again! \n\n");
        goto REGISTRATIONLABEL;
    }
}


void login()
{
        FILE *databaseAdminFile;
        ADMIN loginAdminHelp,                    //help variable to place the username and password that user types in
              adminTmp;                          //help variable to place accounts from database and to compare it to the loginAdminHelp variable
        int matchingAccount = 0;                 //variable to use if we find or dont find a matching account in the database

        LOGINLABEL:

        printf("LOGIN: \n");
        printf("USERNAME: ");    scanf("%s",loginAdminHelp.username);
        printf("PASSWORD: ");    maskPassword(loginAdminHelp.password);
        printf("\n");

        if((databaseAdminFile = fopen("databaseAdmin.dat","rb")) != NULL)
        {
            printf("Checking Username and Password...\n");
            Sleep(1000);
            while(fread(&adminTmp, sizeof(ADMIN), 1, databaseAdminFile) && !matchingAccount)
                if(strcmp(loginAdminHelp.username,adminTmp.username) == 0 &&
                   strcmp(loginAdminHelp.password,adminTmp.password) == 0)
                        matchingAccount = 1;      //if there is a matching account end the loop

            if(matchingAccount == 0)
            {
                printf("Invalid username or password! Try again! \n\n");
                goto LOGINLABEL;
            }
            fclose(databaseAdminFile);
        }
        else
            printf("ERROR !!! CAN'T OPEN 'databaseAdmin.dat' FILE !!!\n");
}

int logRegForm()
{
    FILE *databaseAdminFile;

    if((databaseAdminFile = fopen("databaseAdmin.dat","rb")) == NULL)       //If there are no users in database(can't open) (binary file - to hide passwords)
    {
        printf("There are no registered users! You must register first!\n");
        registration();
    }
    else
        fclose(databaseAdminFile);  //if there is a file just close it because this is just a check if there are any registered admins

    printLogRegOptions();
    int  wrongOption = 0,           //variable to use for help to print out Error if user types in wrong option
         option;                    //variable to take the number for users option
    char optionHelp[10];                //variable to take leftovers from the input stream
    do
    {
        if(wrongOption)
        {
            printf("That is not a valid option! Try again! \n\n");
            gets(optionHelp);
        }
        printf("Your choice: ");
        scanf("%d",&option);
        wrongOption = 1;
    }
    while(option != 1 && option != 2 && option != 3);

    ///////////---------------------------------------------------- L O G I N  -----------------------------------------------------------------
    if(option == 1)
    {
        login();
        return 1;
    }
    /////////////////------------------------------------------ R E G I S T E R ----------------------------------------------------------------
    else if(option == 2)
    {
        registration();
        printRegLoading();
        printf("Your registration was successful!\nYou need to log into your account to proceed: \n");
        login();
        return 1;
    }
    ///////////--------------------------------------------------- C A N C E L  ----------------------------------------------------------------
    else if(option == 3)
        return 0;
    return 0;
}




void configureQuiz()
{
    FILE *quizFile=NULL;
    int n=10,i;
    char optionHelp[20];
    QUESTION *quiz=(QUESTION*)calloc(n,sizeof(QUESTION));
    for(i=0; i<n; i++)
    {
        printf("Enter question no. %d: ",i+1);  getchar(); gets(quiz[i].quizQuestion);
        printf(" Enter the first answer: ");  gets(quiz[i].answer1);
        printf(" Enter the second answer: "); gets(quiz[i].answer2);
        printf(" Enter the third answer: ");  gets(quiz[i].answer3);
        int wrongOption = 0;        //variable to use for help to print out Error if user types in wrong option
        do
        {
            if(wrongOption)
            {
                printf("That is not a valid answer! Try again! \n\n");
                gets(optionHelp);
            }
            printf(" WHICH ANSWER IS CORRECT:");
            scanf("%d",&quiz[i].correctAnswer);
            wrongOption = 1;
        }
        while(quiz[i].correctAnswer < 1 || quiz[i].correctAnswer > 3);
    }
    if((quizFile=fopen("Quiz.dat","wb"))!=NULL)
    {
        for(i=0; i<n; i++)
            fwrite(&quiz[i],sizeof(QUESTION),1,quizFile);
        fclose(quizFile);
    }
    else
    {
        printf("\nError! Couldn't open 'Quiz.dat'!\n");
        return;
    }
    free(quiz);
    printf("\n\nYOUR QUIZ WAS SUCCESSFULLY CREATED!\n");
}

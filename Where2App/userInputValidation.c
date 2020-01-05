/*C file for functions that check whether the information
provided by user is correct/available for use or not*/

#include "userInputValidation.h"
#include "adminMainFunctions.h"


int validAccountOption(char *userInput)
{
    int length=strlen(userInput);
    if(length!=2)                              //if it's longer than it should be, it's obviously not right
        return 0;
    else if(userInput[0]=='1' || userInput[0]=='2' || userInput[0]=='3')
    {
        int option=atoi(userInput);            //if the input is correct, convert it to integer and return
        return option;
    }
    else
        return 0;
}

int availableUsername(char *newUsername)
{
    int matchingUsername=0;
    FILE *databaseAdminFile;
    ADMIN tmpAdmin;
    if((databaseAdminFile=fopen("databaseAdmin.dat","rb"))!=NULL)
    {
        while(fread(&tmpAdmin,sizeof(ADMIN),1,databaseAdminFile) && !matchingUsername)
        {
            if(strcmp(tmpAdmin.username,newUsername)==0)
                matchingUsername=1;
        }
        fclose(databaseAdminFile);
    }
    else
        printf("ERROR !!! CAN'T OPEN 'databaseAdmin.dat' FILE !!!\n");
    if(matchingUsername==1)  //if matching username exist, return 0 - username is unavailable
        return 0;
    else
        return 1;           //username is available
}

#include "userMainFunctions.h"

void playQuiz()
{
    FILE *quizFile=NULL;
    int score=0,i=0,n=10,answer[n];
    char optionHelp[20];
    QUESTION *quiz=(QUESTION*)calloc(n,sizeof(QUESTION)),tmp;
    if((quizFile=fopen("Quiz.dat","rb"))!=NULL)
    {
        while(fread(&tmp,sizeof(QUESTION),1,quizFile))
            quiz[i++]=tmp;
        fclose(quizFile);
    }
    else
    {
        printf("\nError! Couldn't open 'Quiz.dat'. File moved or missing!\n");
        return;
    }
    printf("===============================================\n");
    for(i=0; i<n; i++)
    {
        printf("Question %d: %s\n",i+1,quiz[i].quizQuestion);
        printf("    1) %s\n",quiz[i].answer1);
        printf("    2) %s\n",quiz[i].answer2);
        printf("    3) %s\n",quiz[i].answer3);
        int wrongOption = 0;        //variable to use for help to print out Error if user types in wrong option
        do
        {
            if(wrongOption)
            {
                printf("That is not a valid answer! Try again! \n\n");
                gets(optionHelp);
            }
            printf(" Choose your answer:");
            scanf("%d",&answer[i]);
            wrongOption = 1;
        }
        while(answer[i]<1 || answer[i]>3);
        if(answer[i]==quiz[i].correctAnswer)
            score++;
    }
    printf("===============================================\n");
    if(score==n)
        printf("CONGRATULATIONS! ");
    printf("Your score is: %d/%d",score,n);
    free(quiz);
}

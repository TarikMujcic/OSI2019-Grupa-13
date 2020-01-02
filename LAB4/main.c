#include "foo.h"

//int ncc=0;

int main()
{
    FILE* fp;
    int dimension=0,i,j;
    char tmp[2];
    if((fp=fopen("Matrica.txt","r"))!=NULL)
    {
        while((tmp[0]=fgetc(fp))!='\n')
            dimension++;
        fclose(fp);
    }
    else
        return printf("Greska pri otvaranju datoteke.");
    int matrix[dimension][dimension];
    if((fp=fopen("Matrica.txt","r"))!=NULL)
    {
        //printf("Matrica susjednosti:\n");
        for(i=0;i<dimension;i++)
        {
            for(j=0;j<dimension;j++)
                {
                    tmp[0]=fgetc(fp);
                    matrix[i][j]=atoi(tmp);
                }
            tmp[0]=fgetc(fp);
        }
        //printanje matrice susjednosti
//        for(i=0;i<dimension;i++)
//        {
//            for(j=0;j<dimension;j++)
//                printf("%d ",matrix[i][j]);
//            printf("\n");
//        }
        fclose(fp);

    }
    else
        return printf("Greska pri otvaranju fajla sa matricom.");
    NODE vector[dimension];
    for(i=0;i<dimension;i++)
    {
        vector[i].info=i;
        vector[i].next=NULL;
    }
    for(i=0;i<dimension;i++)
        for(j=0;j<dimension;j++)
    {
        if(matrix[i][j]==1)
        {
            addNeighbour(&vector[i],&vector[j]);
        }
    }
    //printanje liste susjednosti
    for(i=0;i<dimension;i++)
    {
        printf("%d. cvor je %d\n    Lista njegovih susjeda: ",i+1,vector[i].info);
        NODE* temp=vector[i].next;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }




    GRAPH g;
    g.n = dimension;
    for(i=0;i<dimension;i++)
        g.nodes[i]=&vector[i];
    printf("BFS:\n");
    bfs(g,0);
    //bfsB(vector,0);

    //POMOC ZA MS
    GRAF graf;
    graf.n=g.n;
    for(i=0;i<graf.n;i++)
        for(j=0;j<graf.n;j++)
            graf.ms[i][j]=matrix[i][j];
    for(i=0;i<graf.n;i++)
        graf.nodes[i]=i;


    //Za dfs vratimo visited na nule
    int visited[dimension];
    for(i=0;i<dimension;i++)
        visited[i]=0;

    DFS(&graf);printf("\n\n");

    printf("DFS PRINT:\n");
    DFSprint(&graf);
    printf("\n\n");



    for(i=0;i<graf.n;i++)
    {
        for(j=0;j<graf.n;j++)
            printf("%d ",graf.ms[i][j]);
        printf("\n");
    }
    //connComp(graf);
    //printf("Broj povezanih komponenti je: %d",ncc);


    return 0;
}




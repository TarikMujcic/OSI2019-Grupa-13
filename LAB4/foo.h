#ifndef FOO_H_INCLUDED
#define FOO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define queMax 10
#define MAX 50

typedef int type;

typedef struct node
{
    type info;
    struct node* next;

}NODE;

typedef struct G { int n; int nodes[MAX]; int ms[MAX][MAX]; } GRAF;

typedef struct queue
{
    int array[MAX];
    int front, rear;
}QUEUE;



typedef struct graph
{
    int n;
    NODE* nodes[MAX];
}GRAPH;

void addNeighbour(NODE*,NODE*);
void DFS(GRAF*);
void DFSforCC(GRAF*,int,int*);
void connComp(GRAF);
void bfs(GRAPH,int);
int deletequeue(QUEUE*,int*);
int addqueue(QUEUE*,int);
void bfs2(GRAPH,int);
void bfsB(NODE*,int);
int isFull(QUEUE*);
int isEmpty(QUEUE*);
int addQue(QUEUE*,int);
int removeQue(QUEUE*,int*);
void watchqueue(QUEUE);



#endif // FOO_H_INCLUDED

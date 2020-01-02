#include "foo.h"



void addNeighbour(NODE* node, NODE* neighbour)
{
    while(node->next!=NULL)
        node=node->next;
    NODE* newOne=(NODE*)malloc(sizeof(NODE));
    newOne->info=neighbour->info;
    newOne->next=NULL;
    node->next=newOne;

}

void bfs(GRAPH g,int start)
{
    QUEUE que;
    int output[g.n];
    int waiting[g.n];
    int counter =0,qcounter=1,i;
    que.front=-1;
    que.rear=0;
    int v;
    char visit[50]={0};
    visit[start]=1;
    addQue(&que,start);
    output[counter++]=start;
    while(removeQue(&que,&v))
    {
        if(qcounter!=0)
        {
            printf("\nOutput:");
            for(i=0;i<counter;i++)
                printf("%d ",output[i]);
            qcounter=0;
            printf("\nVisited:");
            for(i=0;i<g.n;i++)
                printf("%d ",visit[i]);
        }
        NODE* tmp=g.nodes[v];
        while(tmp)
        {
            int u=tmp->info;
            if(!visit[u])
            {
                output[counter++]=u;
                waiting[qcounter++]=u;
                visit[u]=1;
                addQue(&que,u);
            }
            tmp=tmp->next;
        }

        if(qcounter!=0)
        {
            printf("\nQue:");
            for(i=0;i<qcounter;i++)
                printf("%d ",waiting[i]);
            printf("\n");
        }

    }
}

int isFull(QUEUE* que)
{
    return que->rear==MAX;
}

int isEmpty(QUEUE* que)
{
    return que->front==-1||que->front==que->rear;
}

int addQue(QUEUE* que, int data)
{
    if(isFull(que))
        return 0;
    if(que->front==-1)
        que->front=0;
    que->array[que->rear++]=data;
    return 1;
}

int removeQue(QUEUE* que, int* data)
{
    if(isEmpty(que))
        return 0;
    *data=que->array[que->front++];
    return 1;
}

void bfs2(GRAPH g,int start)
{
    QUEUE que;
    int output[g.n];
    int waiting[g.n];
    int counter =0,qcounter=1,i;
    que.front=-1;
    que.rear=0;
    int v;
    char visit[50]={0};
    visit[start]=1;
    addQue(&que,start);
    output[counter++]=start;
    while(removeQue(&que,&v))
    {
       for(i=0;i<counter;i++)
        printf("%d ",output[i]);
       printf("\n");
        NODE* tmp=g.nodes[v];
        while(tmp)
        {
            int u=tmp->info;
            if(!visit[u])
            {
                output[counter++]=u;
                visit[u]=1;
                addQue(&que,u);
            }
            tmp=tmp->next;
        }


    }
}


int addqueue(QUEUE* queue,int info)
{
    if(isFull(queue)) return 0;
    if(queue->front==-1) queue->front=0;
    queue->array[queue->rear++]=info;
    return 1;
}

int deletequeue(QUEUE* queue,int* info)
{
    if(isEmpty(queue)) return 0;
    *info=queue->array[queue->front++];
    return 1;
}

void watchqueue(QUEUE queue)
{
    while(queue.front!=queue.rear)
        printf("%d ",queue.array[queue.front++]);
}


int nextNotVisited(NODE *node, int visit[])
{

}
int gl = 0;

void DFS(GRAF *g)
{
    printf("\n\nDFS: ");
    int visit[MAX]={};
    void dfs_visit(int u)
    {
       int v;

       printf("%d ",g->nodes[u]);
       visit[u]=1;
       for (v=0; v<g->n; v++)
          if (g->ms[u][v] && !visit[v])
          {
              dfs_visit(v);
          }

    }
    dfs_visit(0);
}


int globVisit[MAX] = {0};

int glglCurr = 0;

void DFSprint(GRAF *g)
{
    int visit[MAX]={};
    void dfs_visit(int u)
    {
       int v;
       int glCurr = g->nodes[u];
       printf("%d -",glCurr);

       //nadji slobodni:
       int help;
       int br = 0;
       int j;
       for(int i = glCurr, j = 0 ; j < g->n; j++)
            if(g->ms[i][j] == 1 && !visit[j])
            {
                int help = glCurr;
                glCurr = j;
                printf(" *%d*\n", glCurr);

            }
      for(int i = glCurr, j = 0 ; j < g->n; j++)
            if(g->ms[i][j] == 1 && !visit[j])
                help = 2;
            if(help == 2)
                    printf("%d -----",glCurr);



       visit[u]=1;
       for (v=0; v<g->n; v++)
          if (g->ms[u][v] && !visit[v])
          {
              dfs_visit(v);
          }

    }
    dfs_visit(0);
}


//void DFSprint(GRAF *g)
//{
//
//    int visit[MAX]={};
//    void dfs_visit(int u)
//    {
//       int v;
//
//       if(gl++ == 0)
//            printf("%d ",g->nodes[u]);
//       else
//            printf(" - %d\n%d ", g->nodes[u],g->nodes[u]);
//       visit[u]=1;
//       for (v=0; v<g->n; v++)
//          if (g->ms[u][v] && !visit[v])
//          {
//              dfs_visit(v);
//          }
//
//    }
//    dfs_visit(0);
//}

//void DFSforCC(GRAF *g,int i,int* visit)
//{
//    void dfs_visit(int u)
//    {
//       int v;
//       //printf("%d ",g->nodes[u]);
//       visit[u]=1;
//       for (v=0; v<g->n; v++)
//          if (g->ms[u][v] && !visit[v]) dfs_visit(v);
//    }
//    dfs_visit(i);
//}



//void connComp(GRAF g)
//{
//    int i;
//    int visit[g.n];
//    for(i=0;i<g.n;i++)
//        visit[i]=0;
//    for(i=0;i<g.n;i++)
//        if(!(visit[i]))
//    {
//        ncc=ncc+1;
//        DFSforCC(&g,i,visit);
//    }
//}






















//void bfsB(NODE* graph,int start)
//{
//    QUEUE queue,bfsqueue;
//    queue.front=-1;queue.rear=0;bfsqueue.front=-1;bfsqueue.rear=0;
//    int v,i;
//    int visited[MAX]={0};
//    visited[start]=1;
//    addqueue(&queue,start);
//    while(deletequeue(&queue,&v))
//    {
//        addqueue(&bfsqueue,v);
//        NODE* neighbor=graph[v].next;
//        while(neighbor)
//        {
//            int u=neighbor->info;
//            if(!visited[u])
//            {
//                visited[u]=1;
//                addqueue(&queue,u);
//            }
//            neighbor=neighbor->next;
//        }
//          printf("\nOutput:");
//          watchqueue(bfsqueue);
//          printf("\nQue:");
//          watchqueue(queue);
//          printf("\n");
//    }
//}


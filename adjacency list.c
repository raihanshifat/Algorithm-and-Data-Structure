#include<stdio.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node* next;
};
struct Graph
{
    int numVertices;
    struct node** adjLists;
};
struct node* createNode(int v)
{
 struct node* newNode=malloc(sizeof(struct node));
 newNode->vertex=v;
 newNode->next=NULL;
 return newNode;
}
struct Graph* createGraph(int V)
{
    struct Graph* graph=malloc(sizeof(struct Graph));
    graph->numVertices=V;
    graph->adjLists=malloc(V*sizeof(struct node*));
    for(int i=0;i<V;i++)
    {
        graph->adjLists[V]=NULL;
    }
    return graph;
}
void addEdge(struct Graph* graph,int src,int des)
{
    struct node* newNode=createNode(des);
    newNode->next=graph->adjLists[src];
    graph->adjLists[src]=newNode;
    newNode=createNode(src);
    newNode->next=graph->adjLists[des];
    graph->adjLists[des]=newNode;
}
void printGraph(struct Graph* graph)
{
    int V=graph->numVertices;
    for(int i=0;i<V;i++)
    {
        struct node* temp=graph->adjLists[i];
        printf("\n Adjacency list of vertex %d\n ", i);
        while(temp)
        {
            printf("%d->",temp->vertex);
            temp=temp->next;
        }
    }
}
int main()
{
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 1);
    addEdge(graph, 5, 6);

    printGraph(graph);

    return 0;
}

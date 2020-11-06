#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int s;
    int d;
    int w;
};
struct Graph
{
    int V;
    int E;
    struct Edge* edge;
};
void printgraph(int dist[],int n)
{
    printf("Vertex   Distance from Source\n");
    for(int i=0;i<n;i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
struct Graph* creategraph(int V,int E)
{
    struct Graph* graph=new Graph;
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[E];
    return graph;
}
void BellmanFord(struct Graph* graph,int src)
{
    int a=graph->V;
    int b=graph->E;
    int dist[a];
    for(int i=0;i<a;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=0;i<a-1;i++)
    {
        for(int j=0;j<b;j++)
        {
            int u=graph->edge[j].s;
            int v=graph->edge[j].d;
            int weight=graph->edge[j].w;
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
            }

        }
    }
    for(int j=0;j<b;j++)
    {
        int u=graph->edge[j].s;
        int v=graph->edge[j].d;
        int weight=graph->edge[j].w;
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
            }

    }
    printgraph(dist,a);
}
int main()
{
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = creategraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].s = 0;
    graph->edge[0].d = 1;
    graph->edge[0].w = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].s= 0;
    graph->edge[1].d = 2;
    graph->edge[1].w = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].s = 1;
    graph->edge[2].d = 2;
    graph->edge[2].w = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].s = 1;
    graph->edge[3].d = 3;
    graph->edge[3].w = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].s = 1;
    graph->edge[4].d = 4;
    graph->edge[4].w = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].s = 3;
    graph->edge[5].d = 2;
    graph->edge[5].w = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].s = 3;
    graph->edge[6].d = 1;
    graph->edge[6].w = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].s = 4;
    graph->edge[7].d = 3;
    graph->edge[7].w = -3;

    BellmanFord(graph, 0);

    return 0;
}

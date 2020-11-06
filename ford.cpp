#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
#define V 6
bool isPath(int graph[V][V],int s,int e,int parent[])
{
    bool visited[V];
    memset(visited,0,sizeof(visited));

    queue<int>q;
    q.push(s);
    parent[s]=-1;
    visited[s]=true;
    while(!q.empty())
    {
      int u=q.front();
      q.pop();
      for(int v=0;v<V;v++)
      {
          if(visited[v]==false && graph[u][v]>0)
          {
              q.push(v);
              parent[v]=u;
              visited[v]=true;
          }
      }
    }
    return (visited[e]==true);
}
int ford(int graph[V][V],int s,int e)
{
    int rgraph[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            rgraph[i][j]=graph[i][j];
        }
    }
    int parent[V];
    int u,v;
    int MAX_FLOW=0;
    while(isPath(rgraph,s,e,parent))
    {
        int min_flow=INT_MAX;
        for(v=e;v!=s;v=parent[v])
        {
            u=parent[v];
            min_flow=min(min_flow,rgraph[u][v]);

        }
        for(v=e;v!=s;v=parent[v])
        {
            u=parent[v];
            rgraph[u][v]=rgraph[u][v]-min_flow;
            rgraph[v][u]=rgraph[v][u]+min_flow;

        }
        MAX_FLOW=MAX_FLOW+min_flow;

    }
    return MAX_FLOW;
}
 int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout << "The maximum possible flow is " << ford(graph, 0, 5);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define V 5

bool isSafe(int path[],bool graph[V][V],int v,int pos)
{
    if(graph[path[pos-1]][v]==0)
    {
        return false;
    }
    for(int i=0;i<pos;i++)
    {
        if(path[i]==v)
        {
            return false;
        }
    }
    return true;


}
bool hamilton(bool graph[V][V],int path[],int pos)
{
    if(pos==V)
    {
        if(graph[path[pos-1]][path[0]]==false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    for(int v=1;v<V;v++)
    {

        if(isSafe(path,graph,v,pos))
        {
         path[pos]=v;
         if(hamilton(graph,path,pos+1))
            return true;
         path[pos]=-1;

        }
    }
    return false;
}
void printh(bool graph[V][V])
{
    int *p=new int[V];
    for(int i=0;i<V;i++)
    {
        p[i]=-1;
    }
    p[0]=0;
    if(hamilton(graph,p,1)==false)
    {
        cout<<"there is no hamiltonian path"<<endl;

    }
    else if((hamilton(graph,p,1)==true))
    {
        for(int i=0;i<V;i++)
        {
            cout<<p[i]<<endl;
        }
        cout<<p[0]<<endl;
    }

}
int main()
{

    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};

    // Print the solution
    printh(graph1);

    /* Let us create the following graph
    (0)--(1)--(2)
    | / \ |
    | / \ |
    | / \ |
    (3) (4) */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};

    // Print the solution
    printh(graph2);

    return 0;
}

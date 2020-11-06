#include<bits/stdc++.h>
using namespace std;
class Hash
{
private:
    int Bucket;
    list<int>*table;
public:
    Hash(int v);
    void insertitem(int x);
    void deleteitem(int x);
    void display();
    int hashfunc(int key)
    {
        return(key%Bucket);
    }
};
Hash::Hash(int V)
{
    this->Bucket=V;
    table=new list<int>[Bucket];
}
void Hash::insertitem(int x)
{
    int i=hashfunc(x);
    table[i].push_back(x);
}
void Hash::deleteitem(int x)
{
    int j=hashfunc(x);
    list<int>::iterator i;
    for(i=table[j].begin();i!=table[j].end();i++)
    {
        if(*i==x)
        {
            break;
        }
    }
    if(i!=table[j].end())
    {
        table[j].erase(i);
    }
}
void Hash::display()
{
    for(int i=0;i<Bucket;i++)
    {
        cout<<i;
        for(auto x:table[i])
        {
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
}
int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);

  // insert the keys into the hash table
  Hash h(7);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++)
    h.insertitem(a[i]);

  // delete 12 from hash table
  h.deleteitem(12);

  // display the Hash table
  h.display();

  return 0;
}

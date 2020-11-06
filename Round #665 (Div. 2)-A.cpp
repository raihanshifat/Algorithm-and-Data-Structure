#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int result;
        vector<int> arr(2);
        for(int i=0;i<2;i++)
        {
            int j;
            cin>>j;
            arr[i]=j;
        }


        if(arr[0]<arr[1])
        {

            result=arr[1]-arr[0];
        }
        else if(arr[0]%2==arr[1]%2 && arr[0]>arr[1])
            {
                result=0;

            }


        else
        {
            result=1;
        }
        cout<<result;



    }
}

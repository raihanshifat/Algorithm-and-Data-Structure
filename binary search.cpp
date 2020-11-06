#include<bits/stdc++.h>
using namespace std;

int binary(int arr[],int l,int h,int x)
{
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(x==arr[mid])
        {
            return mid;
        }
        else if(x<arr[mid])
        {
          return binary(arr,l,mid-1,x);
        }
        else
        {
             return binary(arr,mid+1,h,x);
        }
    }
    return -1;
}
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}

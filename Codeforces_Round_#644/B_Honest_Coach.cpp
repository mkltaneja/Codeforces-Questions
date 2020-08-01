#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int mini = 1001;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                mini = min(mini,(abs(arr[j]-arr[i])));
        cout<<mini<<endl;   
    }
}
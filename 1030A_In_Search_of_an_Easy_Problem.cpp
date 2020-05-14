#include<iostream>
using namespace std;

bool isEasy(int n, int* arr)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bool easy = isEasy(n,arr);
    if(easy)
        cout<<"EASY";
    else 
        cout<<"HARD";     
}
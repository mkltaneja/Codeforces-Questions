#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    if(ar[0] == 0)
    {
        cout<<0<<endl;
        return 0;
    }
    int j = k-1, i = k-1;
    while(ar[j++] == ar[k-1])
    {}
    while(ar[i--] == 0)
    {}
    if(i != k-2)
        cout<<(i+2);
    else 
        cout<<j-1;
    cout<<endl;

    return 0;
}
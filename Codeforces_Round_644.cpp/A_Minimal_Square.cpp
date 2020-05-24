#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(2*min(a,b) >= max(a,b))
            cout<<(2*(min(a,b)))*(2*(min(a,b)))<<endl;
        else 
            cout<<((max(a,b))*(max(a,b)))<<endl;
    }
}
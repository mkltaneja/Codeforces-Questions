#include<iostream>
using namespace std;

void feelings(int n)
{
    for(int i=1;i<=n;i++)
    {
        string feel; 
        if(i % 2 == 0)
            feel = "love";
        else
            feel = "hate";
        cout<<"I "<<feel;
        if(i != n)
        cout<<" that ";
    }
    cout<<" it";
}

int main()
{
    int n;
    cin>>n;
    feelings(n);
}
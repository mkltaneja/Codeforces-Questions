#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x, y, z;
        cin>>x>>y>>z;
        if(x != y && y != z && z != x)
        {
            cout<<"NO\n";
            continue;
        }
        if(x == y && y == z)
        {
            cout<<"YES\n";
            cout<<x<<" "<<y<<" "<<z<<endl;
            continue;
        }
        if(z == max(x,y))
        {
            cout<<"YES\n";
            cout<<x<<" "<<y<<" "<<1<<endl;
        }
        else if(y == max(x,z))
        {
            cout<<"YES\n";
            cout<<x<<" "<<z<<" "<<1<<endl;
        }
        else if(x == max(z,y))
        {
            cout<<"YES\n";
            cout<<z<<" "<<y<<" "<<1<<endl;
        }
        else 
            cout<<"NO\n";
    }
}
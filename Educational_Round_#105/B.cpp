#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        if(u>0 && r>0)
            u--, r--;
        if(d>0 && l>0)
            d--, l--;
        if(r>0 && d>0)
            r--, d--;
        if(l>0 && u>0)
            l--, u--;
        
        if(u <= n-2 && r <= n-2 && d <= n-2 && l <= n-2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--)
    {
        long int l,r;
        cin>>l>>r;
        if(l * 2 <= r)
        {
            cout<<l<<" "<<long(l*2)<<endl;
        }
        else 
        {
            cout<<-1<<" "<<-1<<endl;
        }
    }
}
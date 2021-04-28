#include<iostream>
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
        long int a,b;
        cin>>a>>b;
        if(a == b)
        {
            if(a % 3 == 2)
                cout<<(a/3)*2+1<<endl;
            else 
                cout<<(a/3)*2<<endl;
            continue;
        }
        if(a == 0 || b == 0)
        {
            cout<<0<<endl;
            continue;
        }
        int maxi = max(a,b);
        int mini = min(a,b);
        if((maxi-mini) >= mini)
        {
            cout<<mini<<endl;
            continue;
        }
        int eq = maxi - mini;
        if((mini - eq) % 3 == 2)
            cout<<eq+((mini-eq)/3)*2+1<<endl;
        else
            cout<<eq+((mini-eq)/3)*2<<endl;
    }
}
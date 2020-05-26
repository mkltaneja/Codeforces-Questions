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
        int n,m;
        cin>>n>>m;
        if(!(n&1))
        {
            cout<<(m * (n/2))<<endl;
            continue;
        }
        if(!(m&1))
        {
            cout<<(n * (m/2))<<endl;
            continue;
        }
        cout<<((n*(m/2))+(n/2)+1)<<endl;
    }
    return 0;
}
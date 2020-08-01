#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        if(m <= (n/k))
        {
            cout<<m<<endl;
            continue;
        }
        else 
        {
            int rj = m-(n/k);
            int rp = k-1;
            // cout<<((n/k)-((rj/rp)*(rj%rp)));
        }
    }
}
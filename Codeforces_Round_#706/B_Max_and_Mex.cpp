#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        set<ll> ar;
        ll a=0, b = INT_MIN;
        for(ll i = 0; i < n; i++)
        {
            ll x;
            cin>>x;
            ar.insert(x);
            b = max(b, x);
        }
        if(k == 0)
        {
            cout<<n<<endl;
            continue;
        }
        // b = *ar.end();
        for(ll x : ar)
        {
            if(x == a)
                a++;
            else 
                break;
        }
        // cout<<a<<" "<<b<<" -> ";
        ll ans;
        if(a < b)
        {
            ll x = ceil(1.0*(a+b)/2);
            if(ar.find(x) == ar.end())
                ans = n+1;
            else 
                ans = n;
            // cout<<x<<endl;
        }
        else 
            ans = n+k;
        cout<<ans<<endl;
    }
    return 0;
}
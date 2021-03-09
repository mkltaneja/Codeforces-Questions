#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int

unordered_set<ll> cubes;
void findcubes(ll n)
{
    for (ll i = 1; i * i * i <= n; i++)
        cubes.insert(i * i * i);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        findcubes(n);
        bool f = false;
        for (ll i = 1; i * i * i <= n; i++)
        {
            ll x = (n - i * i * i);
            if (cubes.count(x))
            {
                // cout<<i*i*i<<" "<<x<<endl;
                f = true;
                break;
            }
        }
        if (f)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}
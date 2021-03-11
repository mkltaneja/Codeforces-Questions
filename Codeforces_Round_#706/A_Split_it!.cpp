#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin >> s;
        if(k == 0)
        {
            cout<<"YES\n";
            continue;
        }
        int sim = 0;
        for(int i = 0; i < n/2; i++)
        {
            if(s[i] == s[n-i-1])
                sim++;
            else
                break;
        }
        // cout<<sim<<endl;
        if(sim >= k && ((sim-k) + ((n+1)/2-k) > 0))
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<bool> vis(26, false);
        bool f = true;
        int i = 0;
        for(int i = 0; i < n;)
        {
            if(vis[s[i]-'A'])
            {
                f = false;
                break;
            }
            int j = i;
            vis[s[i]-'A'] = true;
            while(j < n && s[j] == s[i]) j++;
            i = j;
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

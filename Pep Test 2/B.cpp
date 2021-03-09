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
        string s;
        cin>>s;
        int u=0, d=0, r=0, l=0;
        int maxi = s.size();
        for(char c : s)
        {
            if(c == 'D')
                d++;
            else if(c == 'U')
                u++;
            else if(c == 'R')
                r++;
            else if(c == 'L')
                l++;
        }
        int mini = min(l, r), minj = min(u, d);
        if(mini == 0 && minj != 0)
            minj = 1;
        else if(minj == 0 && mini != 0)
            mini = 1;
        l = mini, r = mini;
        u = minj, d = minj;
        string ans =  "";
        while(l--)
            ans += "L";
        while(d--)
            ans += "D";
        while(r--)
            ans += "R";
        while(u--)
            ans += "U";
        
        cout<<ans.size()<<endl<<ans<<endl;
    }
    return 0;
}
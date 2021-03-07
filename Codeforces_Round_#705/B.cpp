#include<bits/stdc++.h>
using namespace std;

bool isvalid(int h, int m, string s, vector<int> &t)
{
    for(char c : s)
    {
        if(c != ':' && t[c-'0'] == -1)
            return false;
    }
    int hh, mm;
    hh = t[s[4]-'0']*10 + t[s[3]-'0'];
    mm = t[s[1]-'0']*10 + t[s[0]-'0'];
    // int ha = stoi(hh);
    // int ma = stoi(mm);
    // cout<<hh<<" "<<mm<<endl;
    if(hh >= h || mm >= m)
        return false;
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h, m;
        cin>>h>>m;
        string s;
        cin>>s;

        vector<int> t = {0,1,5,-1,-1,2,-1,-1,8,-1};
        while(true)
        {
            if(isvalid(h, m, s, t))
            {
                cout<<s<<endl;
                break;
            }
            int hh = (s[0]-'0')*10 + (s[1]-'0');
            int mm = (s[3]-'0')*10 + (s[4]-'0');
            bool f = false;
            mm = (mm+1)%m;
            if(mm == 0)
                f = true;
            s[4] = mm%10 + '0';
            mm /= 10;
            s[3] = mm%10 +'0';

            if(f)
            {
                hh = (hh+1)%h;
                s[1] = hh%10 + '0';
                hh /= 10;
                s[0] = hh%10 + '0';
            }
            // cout<<s<<endl;
        }
    }
}
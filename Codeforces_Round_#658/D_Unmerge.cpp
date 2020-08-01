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
        int n;
        cin>>n;
        int a[2*n];
        for(int i=0;i<2*n;i++)
            cin>>a[i];

        int s1 = 0, s2 = 0;
        queue<int> q1, q2;
        q1.push(a[0]);
        s1 = 1;
        bool f = true;
        for(int i=1;i<2*n;i++)
        {
            if(s1 > n || s2 > n)
            {
                f = false;
                break;
            }
            if(!q1.empty())
            {
                if(a[i] < q1.front())
                {
                    q1.push(a[i]);
                    s1++;
                }
                else 
                {
                    q2.push(a[i]);
                    s2++;
                }
                q1.pop();
            }
            else if(!q2.empty())
            {
                if(a[i] < q2.front())
                {
                    q2.push(a[i]);
                    s2++;
                }
                else
                { 
                    q1.push(a[i]);
                    s1++;
                }
            }
        }
        if(!f || ((s1 != n) || (s2 != n)))
            cout<<"NO\n";
        else 
            cout<<"YES\n";
    }
}
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
        int n,m;
        cin>>n>>m;
        unordered_set<int> a;
        unordered_set<int> b;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            a.insert(ele);
        }
        for(int i=0;i<m;i++)
        {
            int ele;
            cin>>ele;
            b.insert(ele);
        }
        int ans;
        bool ff = false;
        for(int ele : a)
            if(b.find(ele) != b.end())
            {
                ff = true;
                ans = ele;
            }

        if(ff)
            cout<<"YES\n"<<1<<" "<<ans<<endl;
        else 
            cout<<"NO\n";
    }
}
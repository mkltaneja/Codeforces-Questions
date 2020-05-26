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
        vector<int> a(n,0);
        for(int i=0;i<n;i++)
            cin>>a[i];
        // for(int i=0;i<n;i++)
        //     cout<<a[i];

        sort(a.begin(),a.end());

        // for(int i=0;i<n;i++)
        //     cout<<a[i];
           
        int gsize = 1;  
        int pending = 1;
        int i = 0;
        for(int ele : a)
        {
            if(gsize+pending-1 >= ele)
            {
                // cout<<i<<" "<<gsize<<endl;
                gsize += pending;
                pending = 1;
            }
            else 
            {
                pending++;
            }
            i++;
        }
        cout<<gsize<<endl;
    }
}
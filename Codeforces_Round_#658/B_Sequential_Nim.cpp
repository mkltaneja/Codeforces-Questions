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
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        int count1 = 0;
        int i = 0;
        while(i < n && a[i] == 1)
        {
            i++;
            count1++;
        }
        if(i == n)
            count1++;
        // cout<<count1<<endl<<endl;
        if(count1 % 2 == 0)
            cout<<"First\n";
        else
            cout<<"Second\n";
    }
}
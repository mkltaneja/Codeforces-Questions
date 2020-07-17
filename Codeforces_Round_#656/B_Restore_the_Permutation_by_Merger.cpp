#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(2*n,0);
        for(int i=0;i<2*n;i++)
            cin>>arr[i];
        set<int> s;
        for(int i : arr)
        {
            if(s.find(i) == s.end())
                cout<<i<<" ";
            s.insert(i);
        }
        cout<<endl;
    }
}
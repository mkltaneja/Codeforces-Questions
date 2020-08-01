#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(3, 0)); //vector<inex,<need,grpsize>>
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr[i] = {a,a-1,1,};
        }
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<arr[i].size();j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;    
        }
        sort(arr.begin(), arr.end());
        cout<<endl;
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<arr[i].size();j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;    
        }
    }
}
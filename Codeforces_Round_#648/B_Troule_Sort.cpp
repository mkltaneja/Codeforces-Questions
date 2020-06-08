#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n,0);
        vector<int> b(n,0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        
        if(n == 1)
        {
            cout<<"Yes\n";
            continue;
        }
        bool f0 = false;
        bool f1 = false;
        for(int i=0;i<n;i++)
            if(b[i] == 0)
                f0 = true;
            else 
                f1 = true;
        if(f0 && f1)
        {
            cout<<"Yes\n";
            continue;
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1]<a[i])
            {
                cout<<"No\n";
                break;
            }
            if(i == n-2)
                cout<<"Yes\n";
        }
    }
}
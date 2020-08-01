#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        set<int> s;
        int maxi = 0;
        bool z = false;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            s.insert(arr[i]);
            maxi = max(maxi,arr[i]);
            z = true;
        }
        int x = 0;
        for (int i = 0; i < n; i++)
            x ^= arr[i];
        
        bool f = true;

        if (x != 0)
        {
            int itr = 0;
            for (int i : s)
            {
                // cout<<(i^x)<<endl;
                if (s.find(i ^ x) == s.end())
                {
                    f = false;
                    break;
                }
                itr++;
                if(itr == n)
                {
                    break;
                }
            }
            if(!f)
            {
                cout << -1 << endl;
                continue;
            }
            else 
            {
                cout<<x<<endl;
                continue;
            }
        }
        else 
        {
            int x = 1;
            for(;x<2*maxi;x++)
            {
                if(!z && s.find(x) != s.end())
                    continue;
                int itr = 0;
                for (auto i : s)
                {
                    if (s.find(i ^ x) == s.end())
                    {
                        break;
                    }
                    itr++;
                    if(itr == n)
                    {
                        f = false;
                        break;
                    }
                }
                if(!f)
                {
                    cout<<x<<endl;
                    break;
                }
            }
            if(f)
                cout<<-1<<endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        set<int> s;
        s.insert(0);
        int cnt = 0;
        vector<int> ans;
        for(int x = 1; x <= n; x++)
        {
            bool f = true;
            int n = s.size();
            for(auto i = s.begin(); n > 0; i++)
            {
                // cout<<x<<" "<<n<<endl;
                if(*i + x == k)
                    f = false;
                s.insert(*i+x);
                // cout<<x<<" "<<n<<" "<<" "<<*i<<endl;
                // cout<<*i+x<<" ";
                n--;
            }
            // cout<<endl;
            if(f)
            {
                ans.push_back(x);
                cnt++;
            }
        }
        // int count = s.size()-1;
        cout<<cnt<<endl;
        // s.erase(0);
        for(int x : ans)
            cout<<x<<" ";
        cout<<endl;
        // count += (k < n) ? n-k : 0;
    }
}

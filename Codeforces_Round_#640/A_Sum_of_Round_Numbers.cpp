#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int num = n;
        int count = 0;
        while(num)
        {
            num /= 10;
            count++;
        }
        vector<int> rounds;
        int i = 1;
        int ans = 0;
        // cout<<count<<" ";
        while(count--)
        {
            if(n%10 != 0)
            {
                rounds.push_back((n%10)*i);
                ans++;
            }
            // cout<<(n%10)*i<<" ";
            i *= 10;
            n /= 10;
        }

        cout<<ans<<endl;
        for(int i=rounds.size()-1;i>=0;i--)
            cout<<rounds[i]<<" ";
    }
}
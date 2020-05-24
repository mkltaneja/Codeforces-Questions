#include<iostream>
#include<cmath>
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
        int n,k;
        cin>>n>>k;
        if(k >= n)
        {
            cout<<1<<endl;
            continue;
        }
        if(n&1)
        {
            int i;
            if(k >= sqrt(n))
                i = sqrt(n);
            else 
                i = k;
            // cout<<i<<endl;
            if(!(i&1))
                i--;
            for(;i>=1;i-=2)
            {
                if(n % i == 0)
                {
                    cout<<(n/i)<<endl;
                    break;
                }
            }
        }
        else
        {
            if(k >= n/2)
            {
                cout<<2<<endl;
                continue;
            }
            for(int i=k;i>=1;i--)
            {
                if(n % i == 0)
                {
                    cout<<(n/i)<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
#include<iostream>
using namespace std;
#define lli long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n>>k;
        while(k---1)
        {
            bool flag = false;
            long long int mindig = 9;
            long long int maxdig = 0;
            long long int num = n;
            while(num)
            {
                mindig = min(mindig,num%10);
                maxdig = max(maxdig,num%10);
                num /= 10;
                if(mindig == 0)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            n += mindig*maxdig;
            // cout<<mindig<<" "<<maxdig<<endl;
        }
            cout<<n<<endl;
    }
}
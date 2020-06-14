#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int l = -1, r;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a % x)
            {
                if(l == -1)
                    l = i;
                r = i;
            }
            sum += a;
        }
        if(sum % x)
        {
            cout<<n<<endl;
            continue;
        }
        if(l == -1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<n-min(l+1,n-r)<<endl;
    }
}   
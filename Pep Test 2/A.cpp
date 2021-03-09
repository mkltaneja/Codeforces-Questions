#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int

int main()
{
    int a, b, n, m, k;
    cin>>a>>b>>n>>m>>k;

    int maxi = 0, mini=a+b, kk = k;
    if(m < n)
    {
        maxi = min(kk/m, b);
        kk -= maxi*m;
        if(kk > 0)
            maxi += min(kk/n, a);
    }
    else
    {
        maxi = min(kk/n, a);
        kk -= maxi*n;
        if(kk > 0)
            maxi += min(kk/m, b);
    }
    
    k -= (a*(n-1) + b*(m-1));
    if(k <= 0)
        mini = 0;
    else 
        mini = min(k, a+b);

    cout<<mini<<" "<<maxi<<endl;

    return 0;
}
#include<iostream>
using namespace std;

long int f(long int n)
{
    for(int i=3;i*i<=n;i+=2)
    {
        if(n % i == 0)
            return i;
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;
    int t;
    cin>>t;
    while(t--)
    {
        long int n,k;
        cin>>n>>k;
        if(n % 2 != 0)
        {
            n += f(n);
            n += 2*(k-1);
        }
        
        else
            n += 2*k;
        
        cout<<n<<endl;
    }
}
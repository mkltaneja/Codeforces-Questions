#include<iostream>
#include<algorithm>
using namespace std;

int isPrime(int n)
{
    for(int i=3;i*i<=n;i+=2)
    {
        if(n % i == 0)
            return i;
        else if(n % (n/i) == 0)
            return n/i;
    }
    return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        if(!(n&1))
        {
            cout<<n/2<<" "<<n/2<<endl;
            continue;
        }
        else 
        {
            int a = isPrime(n);
            if(a == 1)
                cout<<a<<" "<<n-a<<endl;
            else 
                cout<<n/a<<" "<<n-(n/a)<<endl;
        }
    }
}
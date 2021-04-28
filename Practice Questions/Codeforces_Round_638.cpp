#include<iostream>
using namespace std;

int pow(int n)   // element a nth pos
{
    int a = 1;
    while(n--)
        a *= 2;
    return a;
}


int equalizer(int a, int b, int n, int count)
{
    if(n == 0 || b == a || count == 0)
    {
        int diff = b - a;
        return diff;
    }
    int ele = pow(n);
    if(b-a >= 2*ele)
        return equalizer(a+ele,b-ele,n-1,count-1);
    else 
        return equalizer(a,b,n-1,count);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x = n;
        int sum = 0;
        while(x > 0)
        {
            sum += pow(x);
            x--;
        }
        cout<<equalizer(0,sum,n,n/2)<<endl;
    }
    return 0;
}
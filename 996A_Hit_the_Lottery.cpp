#include<iostream>
using namespace std;

int min_transactions(int n)
{
    int count = 0;
    while(n)
    {
        if(n-100 >= 0)
            n -= 100;
        else if(n-20 >= 0)
            n -= 20;
        else if(n-10 >= 0)
            n -= 10;
        else if(n-5 >= 0)
            n -= 5;
        else if(n-1 >= 0)
            n -= 1;
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;

    cout<<min_transactions(n);
}
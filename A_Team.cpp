#include<iostream>
using namespace std;
int main()
{
    int n, i, count = 0, ones = 0;
    cin>>n;
    while(n--)
    {
        for(int k=0;k<3;k++)
        {
            cin>>i;
            if(i == 1)
                ones++;
        }
        if(ones >= 2)
            count++;
        ones = 0;
    }
    cout<<count<<endl;
}


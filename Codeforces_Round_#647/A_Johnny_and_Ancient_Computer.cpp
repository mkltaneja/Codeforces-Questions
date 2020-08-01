#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b;
        cin>>a>>b;
        if(a == b)
        {
            cout<<0<<endl;
            continue;
        }
        long long int ans = 0;
        if(a > b)
        {
            if(a % b)
            {
                cout<<-1<<endl;
                continue;
            }
            while(a > b)
            {
                if(a % 8 == 0 && a/8 >= b)
                    a /= 8;

                else if(a % 4 == 0 && a/4 >= b)
                    a /= 4;

                else if(a % 2 == 0 && a/2 >= b)
                    a /= 2;
                else 
                    break;
                ans++;
            }
            if(a == b)
                cout<<ans<<endl;
            else 
                cout<<-1<<endl;
        }
        else if(a < b)
        {
            
            if(b % a)
            {
                cout<<-1<<endl;
                continue;
            }
            while(a < b)
            {
                if(a * 8 <= b)
                    a *= 8;
                else if(a * 4 <= b)
                    a *= 4;
                else if(a * 2 <= b)
                    a *= 2;
                else 
                    break;
                ans++;
                // cout<<a<<" ";
            }
            if(a == b)
                cout<<ans<<endl;
            else 
                cout<<-1<<endl;
        }
    }
}

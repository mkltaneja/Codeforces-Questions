// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     long int t;
//     cin>>t;
//     while(t--)
//     {
//         long int n,k;
//         cin>>n>>k;

//         long int count = k;
//         long int i=1;
//         for(;count != 0;i++)
//         {
//             if(i % n != 0)
//                 count--;
//         }
//         cout<<i-1<<endl;
//     }
// }
//THE ABOVE CODE WILL GIVE TLE in some cases

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int prev = 0;
        int gaps = k/n - prev/n;
        
        while(gaps != 0)
        {
            prev = k;
            k += gaps;
            gaps = k/n - prev/n;
        }
        cout<<k<<endl;
    }
    return 0;
}
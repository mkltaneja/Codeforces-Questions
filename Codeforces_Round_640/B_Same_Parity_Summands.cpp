// #include<iostream>
// #include<vector>
// using namespace std;

// bool check_odd(long long int n, int k, long long int idx, vector<long long int> &odd, long long int size, string ans)
// {
//     if(k == 0 && n == 0)
//     {
//         cout<<"YES"<<endl;
//         cout<<ans<<endl;
//         return true;
//     }
//     else if(k == 0)
//         return false;

//     bool res = false;

//     for(long long int i=0;i<size;i++)
//         if(n - odd[i] >= 0)
//             res = res || check_odd(n-odd[i],k-1,i,odd,size,ans+to_string(odd[i])+" ");
//     return res;
// }

// bool check_even(long long int n, int k, long long int idx, vector<long long int> &even, long long int size, string ans)
// {
//     if(k == 0 && n == 0)
//     {
//         cout<<"YES"<<endl;
//         cout<<ans<<endl;
//         return true;
//     }
//     else if(k == 0)
//         return false;

//     bool res = false;

//     for(long long int i=0;i<size;i++)
//         if(n - even[i] >= 0)
//             res = res || check_odd(n-even[i],k-1,i,even,size,ans+to_string(even[i])+" ");
//     return res;
// }

// int main()
// {
//     long long int t;
//     cin>>t;
//     while(t--)
//     {
//         long long int n;
//         int k;
//         cin>>n>>k;
//         if(k > n)
//         {
//             cout<<"NO"<<endl;
//             continue;
//         }
//         if(k == n)
//         {
//             while(k--)
//                 cout<<1<<" ";
//             cout<<endl;
//             continue;
//         }

//         vector<long long int> odd((n+1)/2,0);
//         for(long long int i=0;i<odd.size();i++)
//             odd[i] = 2*i + 1;

//         vector<long long int> even(n/2,0);

//         for(long long int i=0;i<even.size();i++)
//             even[i] = 2*i + 2;

//         // for(int i=0;i<odd.size();i++)
//         //     cout<<odd[i]<<" ";

//         // cout<<endl;
//         // for(int i=0;i<even.size();i++)
//         //     cout<<even[i]<<" ";

//         if(check_odd(n,k,0,odd,odd.size()-1,""))
//             continue;

//         if(check_even(n,k,0,even,even.size()-1,""))
//             continue;

//         else
//             cout<<"NO"<<endl;
//     }
// }

// THE ABOVE CODE WILL GIVE RTE in some cases

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (k > n)
        {
            cout << "NO\n";
            continue;
        }
        if (k == n)
        {
            cout<<"YES\n";
            while (k--)
                cout << 1 << " ";
            cout << endl;
            continue;
        }
        int i = k;
        int num = n;
        while (i-- - 1)
            num -= 1;

        if (num % 2 == 1)
        {
            cout << "YES\n";
            while (k-- - 1)
                cout << 1 << " ";
            cout << num << endl;
            continue;
        }

        i = k;
        num = n;
        bool f = true;
        while (i---1)
        {
            if (num <= 0)
            {
                f = false;
                break;
            }
            num -= 2;
        }
        if (num == 0 || !f)
        {
            cout << "NO\n";
            continue;
        }

        if (num % 2 == 0)
        {
            cout << "YES\n";
            while (k---1)
                cout << 2 << " ";
            cout << num << endl;
        }

        else
            cout << "NO\n";
    }
}
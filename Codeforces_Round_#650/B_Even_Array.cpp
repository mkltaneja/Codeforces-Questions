// #include<iostream>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
    
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         int arr[n];
//         int even = 0;
//         int odd = 0;
//         for(int i=0;i<n;i++)
//         {
//             cin>>arr[i];
//             if(i % 2 == 0 && arr[i] % 2 == 1)
//                 even++;
//             else if(i % 2 == 1 && arr[i] % 2 == 0)
//                 odd++;
//         }
//         if(odd != even)
//             cout<<-1<<endl;
//         else 
//             cout<<odd<<endl;
//     }
//     return 0;
// }

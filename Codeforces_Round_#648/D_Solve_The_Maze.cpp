#include<iostream>
// #include<vector>
using namespace std;

// bool HasPath(int i, int j, vector<vector<char>> &arr, int n, int m)
// {
//     if(i == n && j == m)
//         return true;

//     if((i == n && j != m) || (j == m && i != n) || arr[i][j] == '.' || arr[i][j] == '#')
//         return false;
    
//     bool res = false;
//     res |= HasPath(i+1,j,arr,n,m);    
//     res |= HasPath(i+1,j+1,arr,n,m); 

//     return res;   
// }

int count_(string s)

int main()
{
    string s;
    s = "(((((())";
    cout<<count_(s);
    cout<<count<<endl;
}
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,m;
//         cin>>n>>m;
//         vector<vector<char>> arr(n,vector<char>(m));
//         for(int i=0;i<n;i++)
//             for(int j=0;j<m;j++)
//                 cin>>arr[i][j];

//         bool f = true;
//         int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(arr[i][j] == 'B')
//                 {
//                     for(int d=0;d<4;d++)
//                     {
//                         int r = i + dir[d][0];
//                         int c = j + dir[d][1];
//                         if(r < 0 || c < 0 || r == n || c == m)
//                             continue;
//                         if(arr[r][c] == 'G')
//                         {
//                             f = false;
//                             break;
//                         }
//                         if(arr[r][c] == '.')
//                             arr[r][c] = '#';
//                     }
//                 }
//                 if(!f)
//                     break;
//             }
//             if(!f)
//                 break;
//         }
//         if(!f)
//         {
//             cout<<"No\n";
//             continue;
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(arr[i][j] == 'G')
//                 {
//                     if(!HasPath(i,j,arr,n,m))
//                     {
//                         f = false;
//                         break;
//                     }
//                 }
//             }
//             if(!f)
//                 break;
//         }
//         if(!f)
//             cout<<"No\n";
//         else 
//             cout<<"Yes\n";
//     }
// }


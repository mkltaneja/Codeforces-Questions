
// APPROACH 1 (Brute Force)

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin>>s;
//     int f = 1;
//     while(true)
//     {
//         string temp = "";
//         int i = 0;
//         bool ff = false;
//         // cout<<s<<endl;
//         int n = s.size();
//         while(i < n)
//         {
//             if(s[i] != s[i+1])
//                 temp += s[i];
//             else if(i != n-1)
//             {
//                 ff = true;
//                 i++;
//                 f ^= 1;
//             }
//             i++;
//         }
//         s = temp;
//         if(!ff)
//         {
//             if(f)
//                 cout<<"No\n";
//             else
//                 cout<<"Yes\n";
//             break;
//         }
//     }
// }

// APPROACH 2 (Using Stack)
// AC

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int f = 1;
    stack<char> st;
    for(char c : s)
    {
        if(st.empty() || st.top() != c)
            st.push(c);
        else 
        {
            st.pop();
            f ^= 1;
        }
    }
    if(f)
        cout<<"No";
    else 
        cout<<"Yes";

    return 0;
}
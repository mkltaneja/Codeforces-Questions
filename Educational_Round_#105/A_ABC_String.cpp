#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// APPROACH 1 (Recursion an Backtracking) --> O(2*n)
bool ans(int i, string &s, vector<char> st, vector<char> v)
{
    if(i == s.size())
        return st.empty();
    // cout<<st.size()<<endl;
    char c = s[i];
    bool res = false;
    if(!v[c-'A'])
    {
        if(st.empty())
        {
            v[c-'A'] = '(';
            // cout<<i<<" - "<<v[c-'A']<<endl;
            st.push_back('(');
            return ans(i+1, s, st, v);
        }
        else 
        {
            v[c-'A'] = ')';
            st.pop_back();
            // cout<<st.size()<<endl;
            // cout<<i<<" - "<<v[c-'A']<<endl;
            res |= ans(i+1, s, st, v);
            // cout<<st.size()<<endl;
            if(res)
                return true;
            v[c-'A'] = '(';
            // cout<<i<<" - "<<v[c-'A']<<endl;
            st.push_back('(');
            st.push_back('(');
            res |= ans(i+1, s, st, v);
        }
    }
    else 
    {
        if(v[c-'A'] == '(')
            st.push_back('(');
        else 
        {
            if(st.empty())
                return false;
            st.pop_back();
        }
        return ans(i+1, s, st, v);
    }
    return res;
}

// APPROACH 2 (Brute Force) --> O(n)

bool ans2(string &s)
{
    vector<int> v(3);
    int n = s.size();
    int x = s[0]-'A', y = s[n-1]-'A';
    if(x == y)
        return false;
    v[x] = 1;               // '(' = +1 , ')' = -1
    v[y] = -1;

    if(count(s.begin(), s.end(), x+'A') == n/2)
        v[3^x^y] = -1;
    else 
        v[3^x^y] = 1;
    int bal = 0;
    for(char c : s)
    {
        bal += v[c-'A'];
        if(bal < 0)
            return false;
    }
    return bal == 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<char> st;
        vector<char> v(3);

        // bool f = ans(0, s, st, v);
        bool f = ans2(s);
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
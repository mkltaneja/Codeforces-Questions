#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<int>> a(n,vector<int>(m,0));

int pallindrome(string &s)
{
    int op = 0;
    for(int i=0;i<s.size();i++)
        if(s[i] != s[s.size()-i-1])
        {
            op++;
            s[i] = s[s.size()-i-1];
            a[i]
        }
    return op;
}

int dfs(int i, int j, string s)
{
    if(i == n-1 && j == m-1)
    {
        s += to_string(a[i][j]);
        cout<<s;
        cout<<"-->";
        int op = pallindrome(s);
        cout<<s<<endl;
        return op;
    }
    
    if(i < 0 || j < 0 || i >= n || j >= m)
        return 0;

    int count = 0;
    count += dfs(i+1,j,s+to_string(a[i][j]));
    count += dfs(i,j+1,s+to_string(a[i][j]));
    return count;
}   

//////UNSOLVED////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        
        int ans = dfs(0,0,"");
        cout<<ans<<endl;
    }
}
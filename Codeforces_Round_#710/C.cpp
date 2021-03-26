#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define pib pair<int,bool>
#define pbi pair<bool,int>
#define pbb pair<bool,bool>
#define pic pair<int,char>
#define pci pair<char,int>
#define pcc pair<char,char>
#define pis pair<int,string>
#define psi pair<string,int>
#define pss pair<string,string>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define vull vector<ull>
#define vvull vector<vull>
#define vb vector<bool>
#define vvb vector<vb>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define vvs vector<vs>
#define vpii vector<pii>
#define vpbi vector<pbi>
#define vpib vector<pib>
#define vpbb vector<pbb>
#define vpci vector<pci>
#define vpic vector<pic>
#define vpcc vector<pcc>
#define vpsi vector<psi>
#define vpis vector<pis>
#define vpss vector<pss>
#define um unordered_map
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define umic unordered_map<int,char>
#define umsi unordered_map<string,int>
#define umis unordered_map<int,string>
#define omii map<int,int>
#define omci map<char,int>
#define omic map<int,char>
#define omsi map<string,int>
#define omis map<int,string>
#define lp(i, a, b) for(int i = a; i < b; i++)
#define lpr(i, b, a) for(int i = b; i > a; i--)
#define lpl(i, a, b) for(ll  i = a; i < b; i++)
#define lplr(i, b, a) for(ll i = b; i > a; i--)
#define all(a) (a.begin(), a.end())
#define rall(a) (a.rbegin(), a.rend())
#define fastio() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;

        int n = a.size(), m = b.size();

        unordered_map<string, pair<int,int>> m1;
        
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                m1[a.substr(i, j-i+1)] = {i,j};

        int len = 0;
        int ii = 0, jj = 0;
        string ans = "";
        for(int i=0; i < m; i++)
        {
            for(int j = i; j < m; j++)
            {
                string x = b.substr(i, j-i+1);
                if(m1.count(x))
                {
                    if(j-i+1 > len)
                    {
                        ans = x;
                        ii = i, jj = j;
                        len = j-i+1;
                    }
                }
            }
        }
        
        int i = m1[ans].f, j = m1[ans].s;

        // cout<<ans<<endl;
        // cout<<i<<" "<<j<<",  "<<ii<<" "<<jj<<endl;
        if(ans.empty()) cout<<n+m<<endl;
        else cout<<(i + (n-j-1)) + (ii + (m-jj-1))<<endl;
    }
    return 0;
}


// OR==========================================================


int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;

        int n = a.size(), m = b.size();

        vvi dp(n+1, vi(m+1, 0));
        int maxlen = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                maxlen = max(maxlen, dp[i][j] = (a[i-1] == b[j-1]) ? (dp[i-1][j-1] + 1) : 0);
        cout<<n+m-2*maxlen<<endl;
    }
} 
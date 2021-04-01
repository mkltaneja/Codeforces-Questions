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
        int n, k;
        cin>>n>>k;
        vi a(n);
        lp(i, 0, n)
            cin>>a[i];
        omii m;
        for(int x : a)
            m[x%k]++;
        
        int ans = 0;
        if(m.count(0))
            ans++;

        // int p = ans;
        for(int i = 1; i <= k/2; i++)
        {
            // cout<<i<<" "<<k-i<<endl;
            // cout<<m[i]<<" "<<m[k-i]<<endl;
            if(m.count(i) && m.count(k-i))
            {
                int x = m[i], y = m[k-i];
                // cout<<x<<" "<<y<<endl;
                if(x == y)
                    ans++;
                else if(x < y)
                    ans += (y - (x+1)) + 1;
                else
                    ans += (x - (y+1)) + 1;
                // p = ans - p;
                // cout<<p<<endl;
            }
            else if(m.count(i))
            {
                if(!(k&1) && i == k/2)
                    ans++;
                else
                    ans += m[i];
                // p = ans - p;
                // cout<<p<<endl;
            }
            else if(m.count(k-i))
            {
                if(!(k&1) && (k-i) == k/2)
                    ans++;
                else
                    ans += m[k-i];
                // p = ans - p;
                // cout<<p<<endl;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
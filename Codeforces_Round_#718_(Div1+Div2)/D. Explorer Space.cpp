#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pib pair<int, bool>
#define pbi pair<bool, int>
#define pbb pair<bool, bool>
#define pic pair<int, char>
#define pci pair<char, int>
#define pcc pair<char, char>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
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
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define umic unordered_map<int, char>
#define umsi unordered_map<string, int>
#define umis unordered_map<int, string>
#define omii map<int, int>
#define omci map<char, int>
#define omic map<int, char>
#define omsi map<string, int>
#define omis map<int, string>
#define lp(i, a, b) for (int i = a; i < b; i++)
#define lpr(i, b, a) for (int i = b; i > a; i--)
#define lpl(i, a, b) for (ll i = a; i < b; i++)
#define lplr(i, b, a) for (ll i = b; i > a; i--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);}
#define mod 1000000007

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll binpowmod(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

bool ispal(string &a)
{
    for (int i = 0; i < a.size() / 2; i++)
        if (a[i] != a[a.size() - i - 1])
            return false;
    return true;
}

void display(int n, vi &a)
{
    for(int x : a) cout<<x<<" ";
    cout<<"\n";
}
void display(int n, int m, vvi &a)
{
    lp(i, 0, n)
    {
        lp(j, 0, m)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

void solve(int n, int m, int k, vvi &h, vvi &v)
{
    vvi ans(n, vi(m, INT_MAX));
    if(k&1)
        ans.assign(n, vi(m, -1));
    else 
    {
        vvi pans(n, vi(m,0));
        lp(kk, 0, k/2)
        {
            lp(i, 0, n)
            {
                lp(j, 0, m)
                {
                    ans[i][j] = INT_MAX;
                    if(i > 0)
                        ans[i][j] = min(ans[i][j], pans[i-1][j] + 2*v[i-1][j]);
                    if(j > 0)
                        ans[i][j] = min(ans[i][j], pans[i][j-1] + 2*h[i][j-1]);
                    if(i < n-1)
                        ans[i][j] = min(ans[i][j], pans[i+1][j] + 2*v[i][j]);
                    if(j < m-1)
                        ans[i][j] = min(ans[i][j], pans[i][j+1] + 2*h[i][j]);
                }
            }
            pans = ans;
        }
    }

    display(n, m, ans);
}

int main()
{
    fastio();
    int n, m, k;
    cin>>n>>m>>k;
    vvi h(n, vi(m-1));
    vvi v(n-1, vi(m));
    lp(i, 0, n)
        lp(j, 0, m-1)
            cin>>h[i][j];
    lp(i, 0, n-1)
        lp(j, 0, m)
            cin>>v[i][j];
    // display(n, m-1, h);
    // display(n-1, m, v);
    solve(n, m, k, h, v);
    return 0;
}
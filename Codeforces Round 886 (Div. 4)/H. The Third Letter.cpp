// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <math.h>
#include <numeric>
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
#define us unordered_set
#define usi us<int>
#define usll us<ll>
#define uss us<string>
#define umii unordered_map<int, int>
#define umil unordered_map<int, ll>
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
#define fastio()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define p_b push_back

int mod = 1000000007;
int MX = 1e5 + 5;

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
    for (int x : a)
        cout << x << " ";
    cout << "\n";
}
void display(int n, int m, vvi &a)
{
    lp(i, 0, n)
    {
        lp(j, 0, m)
                cout
            << a[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int gcd(ll a, ll b)
{
    return b < a ? gcd(b, a) : (b % a == 0 ? a : gcd(b % a, a));
}

class ftree
{
public:
    vector<ll> ft;
    int sz;
    ftree(int sz)
    {
        this->sz = sz;
        this->ft.assign(sz, 0);
    }

    void add(int x)
    {
        while (x < sz)
        {
            ft[x]++;
            x += x & -x;
        }
    }

    ll get(int x)
    {
        ll ans = 0;
        while (x)
        {
            ans += ft[x];
            x -= x & -x;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

bool dfs(ll x, int u, vector<vvi> &gp, umil &pos, vi &vis)
{
    pos[u] = x;
    vis[u] = 1;
    for(auto v : gp[u])
    {
        if(pos.count(v[0]))
        {
            // cout<<u<<" :: "<<v[0]<<", "<<v[1]<<" -> "<<x<<", "<<pos[v[0]]<<endl;
            if(pos[v[0]] - x != v[1])
                return false;
            continue;
        }
        // cout<<u<<", "<<v[0]<<" -> "<<x + v[1]<<endl;
        if(!dfs(x + v[1], v[0], gp, pos, vis))
            return false;
    }
    return true;
}

bool solve(int n, int m, vvi &a)
{
    vi vis(n+1, 0);
    vector<vvi> gp(n+1);
    lp(i, 0, m)
    {
        gp[a[i][0]].p_b({a[i][1], a[i][2]});
        gp[a[i][1]].p_b({a[i][0], -a[i][2]});
    }
    lp(u, 1, n+1)
    {
        umil pos;
        if(!vis[u])
        {
            // cout<<u<<", ";
            if(!dfs(0, u, gp, pos, vis))
                return false;
        }
    }
    // cout<<endl;
    return true;
}

int main()
{
    fastio();
    int t;
    // cout<<"Hello World!!\n";
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vvi a(m, vi(3));
        lp(i, 0, m)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            // cout<<a[i][0]<<", "<<a[i][1]<<", "<<a[i][2]<<endl;
        }

        bool ans = solve(n, m, a);
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

// g++ A.cpp -o out -std=c++11
// -std=c++11

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

void display(int n, vll &a)
{
    for (ll x : a)
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

int upperBound(int st, int end, ll x, ll y, vll &a)
{
    int ans = end + 1;
    while(st <= end)
    {
        int mid = (st + end) / 2;
        if(a[mid] - y > x)
        {
            ans = mid;
            end = mid - 1;
        }
        else st = mid + 1;
    }
    return ans;
}

void solve1(int n, vll &a, vll &dp, bool rev)
{
    vll ps(n, 0), val(n, n);

    lp(i, 0, n)
        ps[i] = a[i] + (i? ps[i-1] : 0);
    int i = n-1;

    while(i >= 0)
    {
        int j = i;
        while(j >= 0 && a[j] == a[i]) j--;
        int k = i + 1;
        if(i+2 < n && a[i+1] == a[i+2] && a[i] >= a[i+1])
            val[i] = val[i+1], j = i-1;
        else j = i;
        while(j >= 0 && a[j] == a[i])
            val[j--] = k;
        i = j;
    }
    
    lp(i, 0, n)
    {
        int vp = val[i];
        int ub = upperBound(vp, n-1, a[i], ps[i], ps);
        if(ub != n)
        {
            if(rev)
                dp[n-i-1] = min(dp[n-i-1], (ll)ub - i);
            else
                dp[i] = min(dp[i], (ll)ub - i);            
        }
    }
}

void solve(int n, vll &a)
{
    vll dp(n, INT_MAX);
    solve1(n, a, dp, 0);
    reverse(all(a));
    solve1(n, a, dp, 1);

    lp(i, 0, n)
        if(dp[i] == INT_MAX)
            dp[i] = -1;
    display(n, dp);
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vll a(n);
        lp(i, 0, n)
            cin>>a[i];

        solve(n, a);
    }
    return 0;
}

// g++ A.cpp -o out -std=c++11
// -std=c++11
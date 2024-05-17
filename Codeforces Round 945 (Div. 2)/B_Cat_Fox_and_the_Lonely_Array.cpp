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

void addNum(ll x, int j, vi &cnt)
{
    while(x)
    {
        if(x & 1)
            cnt[j]++;
        x >>= 1;
        j++;
    }
}
void remNum(ll x, int j, vi &cnt)
{
    while(x)
    {
        if(x & 1)
            cnt[j]--;
        x >>= 1;
        j++;
    }
}

int solve(int n, vll &a)
{
    int st = -2, i = 0;
    int set = 0;
    ll orr = 0, p = 0;
    vi cnt(30);
    for(ll x : a)
    {
        orr |= x;
        if(orr == p)
        {
            if(!set)
                st = i-1;
            set = 1;
        }
        else set = 0;
        i++;
        p = orr;
        // cout<<orr<<", "<<p<<" -> "<<i<<";   ";
    }
    // cout<<endl;
    
    // cout<<st<<", "<<orr<<endl;

    if(set == 0)
        return n;
    if(st == -1)
        return 1;
    
    int ans = st + 1;
    lp(i, 0, st+1)
        addNum(a[i], 0, cnt);
    
    // display(5, cnt);
    p = 0;
    vi cnt2 = cnt;
    lp(i, st+1, n)
    {
        remNum(a[p], 0, cnt2);
        addNum(a[i], 0, cnt2);


        // cout<<"tmp:\n";
        // display(5, cnt2);

        bool fl = true;
        lp(k, 0, 30)
        {
            if((cnt[k] && !cnt2[k]) || (cnt2[k] && !cnt[k]))
            {
                fl = false;
                break;
            }
        }
        if(!fl)
        {
            // cout<<"no, ";
            ans++;
            // cout<<"added\n";
            addNum(a[p], 0, cnt2);
            // cout<<"tmp:\n";
            // display(5, cnt2);
        }
        else 
        {
            // cout<<"yes, ";
            p++;
        }
    }
    // cout<<endl;

    return ans;
}

int main()
{
    fastio();
    int t;
    // cout<<"Hello World!!\n";
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vll a(n);
        lp(i, 0, n)
            cin>>a[i];

        int ans = solve(n, a);
        cout<<ans<<endl;
    }
    return 0;
}

// g++ A.cpp -o out -std=c++11
// -std=c++11
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

int gcd(ll a, ll b)
{
    return b < a? gcd(b, a) : (b % a == 0? a : gcd(b%a, a));
}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

bool solve(int n, vi &in)
{
    unordered_set<int> sa, sb;
    vi a(n, -1), b(n, -1);
    lp(i, 0, n)
    {
        if(sa.count(in[i]) && sb.count(in[i]))
            return false;
        if(!sa.count(in[i]))
        {
            sa.insert(in[i]);
            a[i] = in[i];
        }
        else if(!sb.count(in[i]))
        {
            sb.insert(in[i]);
            b[i] = in[i];
        }
    }

    set<int> ra, rb;
    lpr(x, n, 0)
        if(!sa.count(x))
            ra.insert(-x);
    lpr(x, n, 0)
        if(!sb.count(x))
            rb.insert(-x);

    lp(i, 0, n)
    {
        if(a[i] == -1)
        {
            auto ub = ra.lower_bound(-in[i]);
            if(ub == ra.end()) return false;
            a[i] = -1*(*ub);
            ra.erase(ub);
        }
    }
    lp(i, 0, n)
    {
        if(b[i] == -1)
        {
            auto ub = rb.lower_bound(-in[i]);
            if(ub == rb.end()) return false;
            b[i] = -1*(*ub);
            rb.erase(ub);
        }
    }

    cout<<"YES\n";
    display(n, a);
    display(n, b);

    return true;
}

int main()
{
    fastio();
    int t;
    // cout<<"Hello World!!\n";
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        // cout<<n<<": \n";
        vi a(n);
        lp(i, 0, n)
            cin >> a[i];

        bool ans = solve(n, a);
        if(!ans) cout<<"NO\n";
    }
    return 0;
}
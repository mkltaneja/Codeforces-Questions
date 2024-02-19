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

bool isSquare(int n, vvi a)
{
    bool found = false;
    lp(i, 0, n)
    {
        lp(j, 0, n)
        {
            if(a[i][j] == 0) continue;
            if(found) return false;
            found = true;

            int k = j, kk = i;
            while(k < n && a[i][k] == 1) k++;
            while(kk < n && a[kk][j] == 1) kk++;
            if(k - j != kk - i) return false;

            int pcnt = k - j;
            lp(ii, i, kk)
            {
                int cnt = 0;
                lp(jj, j, k)
                {
                    if(!a[ii][jj]) break;
                    a[ii][jj] = 0;
                    cnt++;
                }
                if(cnt && pcnt != cnt) return false;
                pcnt = cnt;
            }
        }
    }
    return found;
}

bool isTriangle(int n, vvi a)
{
    bool found = false;
    lp(i, 0, n)
    {
        lp(j, 0, n)
        {
            if(a[i][j] == 0) continue;
            if(found) return false;
            found = true;

            int k = j, p = j;
            while(k < n && a[i][k] == 1) k++;
            if(k - j > 1) return false;


            int pcnt = -1, st = p;
            lp(ii, i, n)
            {
                if(st == -1) break;
                int cnt = 0;
                lp(jj, st, n)
                {
                    if(!a[ii][jj]) break;
                    a[ii][jj] = 0;
                    cnt++;
                }
                if(cnt && cnt != pcnt + 2) return false;
                pcnt = cnt;
                st--;
            }
        }
    }
    return found;
}


bool isTriangleRev(int n, vvi a)
{
    bool found = false;
    lpr(i, n-1, -1)
    {
        lp(j, 0, n)
        {
            if(a[i][j] == 0) continue;
            if(found) return false;
            found = true;

            int k = j, p = j;
            while(k < n && a[i][k] == 1) k++;
            if(k - j > 1) return false;

            int pcnt = -1, st = p;
            lpr(ii, i, -1)
            {
                if(st == -1) break;
                int cnt = 0;
                lp(jj, st, n)
                {
                    if(!a[ii][jj]) break;
                    a[ii][jj] = 0;
                    cnt++;
                }
                if(cnt && cnt != pcnt + 2) return false;
                pcnt = cnt;
                st--;
            }
        }
    }
    return found;
}

void solve(int n, vvi &a)
{
    if(isSquare(n, a))
        cout<<"SQUARE\n";
    else if(isTriangle(n, a))
        cout<<"TRIANGLE\n";
    else if(isTriangleRev(n, a))
        cout<<"TRIANGLE\n";
    else cout<<"Nothing\n";
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
        vvi a(n, vi(n));
        lp(i, 0, n)
        {
            string st;
            cin>>st;
            lp(j, 0, n)
                a[i][j] = st[j]-'0';
        }

        solve(n, a);
    }
    return 0;
}

// g++ A.cpp -o out -std=c++11
// -std=c++11

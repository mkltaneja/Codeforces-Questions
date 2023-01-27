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

// int findMiss(int n, vi &a)
// {
//     int miss = 0, sum = 0;
//     for(int x : a)
//         sum += x;
    
//     miss = (n*(n+1)/2) - sum;

//     return miss;
// }

// void solve(int n, vvi &a)
// {
//     vi ans;
//     int x = n-1;
//     int m1 = findMiss(n, a[0]);
//     int m2 = findMiss(n, a[1]), i2 = -1;
//     for(int i = 0; i < n-1; i++)
//     {
//         if(a[0][i] == m2)
//         {
//             i2 = i;
//             break;
//         }
//     }
//     vi tmp = a[0];
//     tmp.erase(tmp.begin()+i2);
//     lp(i, 0, n-1)
//     {
//         tmp.insert(tmp.begin()+i, m1);
//         if(tmp == a[1])
//         {
//             bool fl = false;
//             lp(k, 0, n-1)
//             {
//                 if(a[2][k] == m2) fl = true;
//                 else if(a[2][k] == m1)
//                 {
//                     i2 += !fl;
//                     break;
//                 }
//             }
//             tmp.insert(tmp.begin()+i2, m2);
//             display(n, tmp);
//             break;
//         }
//         tmp.erase(tmp.begin()+i);
//     }

//     display(n, ans);
// }

void solve(int n, vvi &a)
{
    vi ans(n, 1);
    vi wt(n, 0);
    iota(all(ans), 0);
    lp(i, 0, n)
        lp(j, 0, n-1)
            wt[a[i][j]-1] += j;
    sort(all(ans), [&wt](int x, int y){
        return wt[x] < wt[y];
    });

    for(int &x : ans)
        cout<<x+1<<" ";
    cout<<endl;
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
        vvi a(n, vi(n-1));
        lp(i, 0, n)
            lp(j, 0, n-1)
                cin >> a[i][j];

        // solve(n, a);
        // OR
        solve(n, a);
    }
    return 0;
}
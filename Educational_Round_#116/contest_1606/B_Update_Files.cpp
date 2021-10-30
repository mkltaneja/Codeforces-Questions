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

void solve(ull n, ull k)
{
    ull ans = 0;
    ull tot = 1;
    while(tot <= k && tot < n)
    {
        tot <<= 1;
        ans++;
        // cout<<tot<<", ";
    }
    // cout<<":  "<<ans<<endl;

    if(tot < n)
    {
        // ans += ceil(1.0*(n-tot)/k);
        ans += (n - tot + k - 1)/k;
        // else ans++;
    }
    cout<<ans<<endl;
    // cout<<endl;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        ull n, k;
        cin>>n>>k;
        solve(n, k);
    }
    return 0;
}

// #pragma GCC optimize("Ofast")
// //#pragma GCC target("avx2")

// #include <bits/stdc++.h>
// #define int long long
// #define ull unsigned long long
// #define ld long double
// #define pb push_back
// #define S second
// #define F first
// #define endl '\n'
// #define pii pair<int, int>
// #define pld pair<ld, ld>

// using namespace std;
// // mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // freopen("input.txt", "r", stdin);
//     // freopen("output1.txt", "w", stdout);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         int sum = 1, kol = 1, K = 0;
//         while (kol < k && sum < n)
//         {
//             sum += kol;
//             kol *= 2;
//             K++;
//         }
//         if (sum >= n)
//         {
//             cout << K << endl;
//             continue;
//         }
//         K += (n - sum + k - 1) / k;
//         cout << K << endl;
//     }
//     return 0;
// }
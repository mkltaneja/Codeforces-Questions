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

// void solve(int n, vi &a)
// {
//     bool fl = true;
//     int i = 0;
//     int si = 1, ei = 1;
//     int cnt = 0;
//     while(i < n)
//     {
//         bool fl1 = false;
//         if(i+1 < n && a[i+1] < a[i]) si = i+1, fl1 = true;
//         while(i+1 < n && a[i+1] < a[i]) i++;
//         if(fl1) ei = i+1, cnt++;
//         if(cnt > 1)
//         {
//             fl = false;
//             break;
//         }
//         i++;
//     }
//     reverse(a.begin()+si-1, a.begin()+ei);
//     vi b = a;
//     sort(all(b));
//     if(b != a) fl = false;
//     if(fl) 
//     {
//         cout<<"yes\n";
//         cout<<si<<" "<<ei<<"\n";
//     }
//     else cout<<"no\n";
// }

void solve(int n, vi &a)
{
    vi b = a;
    sort(all(b));
    umii m;
    for(int i = 0; i < n; i++) m[b[i]] = i;
    for(int i = 0; i < n; i++) a[i] = m[a[i]];
    int si = 1, ei = 1;
    lp(i, 0, n) 
    {
        if(a[i] != i) 
        {
            si = i+1;
            break;
        }
    }
    lpr(i, n-1, -1)
    {
        if(a[i] != i) 
        {
            ei = i+1;
            break;
        }
    }
    reverse(a.begin()+si-1, a.begin()+ei);
    bool fl = true;
    lp(i, 0, n) 
    {
        if(a[i] != i)
        {
            fl = false;
            break;
        }
    }
    if(!fl) cout<<"no\n";
    else cout<<"yes\n"<<si<<" "<<ei<<"\n";
}

int main()
{
    fastio();
    int n;
    cin>>n;
    vi a(n);
    lp(i, 0, n)
        cin >> a[i];

    // solve(n, a);
    // OR
    solve(n, a);
    return 0;
}
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

void solve(ll hc, ll dc, ll hm, ll dm, ll k, ll w, ll a)
{
    ll y = ceil(1.0*hc/dm);
    ll x = ceil(1.0*hm/dc);

    // cout<<x<<", "<<y<<endl;
    if(x <= y) cout<<"YES\n";
    else 
    {
        bool fl = false;
        for(int i = 0; i <= k && !fl; i++)
        {
            int j = k-i;
            ll nh = hc + i*a;
            ll nd = dc + j*w;
            ll ny = ceil(1.0*nh/dm);
            ll nx = ceil(1.0*hm/nd);
            // cout<<nh<<", "<<nd<<" -> "<<nx<<", "<<ny<<endl;
            if(nx <= ny) fl = true;
        }

        // ll d = x-(y+1);
        // cout<<"a:\n";
        // bool fl = false;
        // ll si = 1, ei = k+1;
        // while(si < ei && !fl)
        // {
        //     ll m = si + ((ei - si)>>1);
        //     ll nh = hc + m*a;
        //     cout<<nh<<", ";
        //     int ny = ceil(1.0*nh/dm);
        //     if(x <= ny) fl = true;
        //     si = m+1;
        // }
        // cout<<endl;

        // cout<<"w:\n";
        // si = 1, ei = k+1;
        // while(si < ei && !fl)
        // {
        //     ll m = si + ((ei - si)>>1);
        //     ll nd = dc + m*w;
        //     int nx = ceil(1.0*hm/nd);
        //     if(nx <= y) fl = true;
        //     si = m+1;
        // }
        // cout<<endl;
        if(fl) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    while(t--)
    {
        ll hc, dc, hm, dm, k, w, a;
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;

        solve(hc, dc, hm, dm, k, w, a);
    }
    return 0;
}
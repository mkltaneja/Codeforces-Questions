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
#define rall(a) (a.rbegin(), a.rend())
#define fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);}
#define mod 10000000007

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

ull sum(ull n)
{
    ull x = 0;
    while (n)
    {
        x += n % 10;
        n /= 10;
    }
    return x;
}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

int main()
{
    fastio();
    int n;
    cin >> n;
    vi a(n);
    umii m;
    lp(i, 0, n)
    {
        cin>>a[i];
        m[a[i]]++;
    }

    sort(all(a));
    // for(int x : a) cout<<x<<" \n";

    vi ans(n);
    int mini = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        int j = i-1, k = i+1;
        int mx = a[i], mn = a[i];
        int d = 0;
        vi temp(n);
        int x = 0;
        temp[x++] = a[i];
        while(j >= 0 || k < n)
        {
            if(j >= 0 && k < n)
            {
                if(m[a[j]] > 1 || m[a[k]] > 1)
                {
                    if(m[a[j]] > m[a[k]])
                        mn = a[j--], temp[x++] = mn;
                    else
                        mx = a[k++], temp[x++] = mx;
                }
                else if((mx-a[j]) < (a[k]-mn))
                    mn = a[j--], temp[x++] = mn;
                else
                    mx = a[k++], temp[x++] = mx;
            }
            else if(j >= 0) 
                mn = a[j--], temp[x++] = mn;
            else if(k < n)
                mx = a[k++], temp[x++] = mx;
            d += (mx - mn);
            // cout<<mx<<" "<<mn<<endl;
            // cout<<a[i]<<":  "<<a[j]<<" "<<a[k]<<endl;
        }
        cout<<d<<": ";
        cout<<endl;
        if(d < mini)
        {
            mini = d;
            cout<<"mind = "<<mini<<"\n";
            ans = temp;
        }
    }

    cout<<mini<<"\n";
    // for(int x : ans) cout<<x<<" ";
    // cout<<"\n";

    return 0;
}
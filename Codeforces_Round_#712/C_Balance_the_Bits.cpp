#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define pib pair<int,bool>
#define pbi pair<bool,int>
#define pbb pair<bool,bool>
#define pic pair<int,char>
#define pci pair<char,int>
#define pcc pair<char,char>
#define pis pair<int,string>
#define psi pair<string,int>
#define pss pair<string,string>
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
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define umic unordered_map<int,char>
#define umsi unordered_map<string,int>
#define umis unordered_map<int,string>
#define omii map<int,int>
#define omci map<char,int>
#define omic map<int,char>
#define omsi map<string,int>
#define omis map<int,string>
#define lp(i, a, b) for(int i = a; i < b; i++)
#define lpr(i, b, a) for(int i = b; i > a; i--)
#define lpl(i, a, b) for(ll  i = a; i < b; i++)
#define lplr(i, b, a) for(ll i = b; i > a; i--)
#define all(a) (a.begin(), a.end())
#define rall(a) (a.rbegin(), a.rend())
#define fastio() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mod 10000000007

ll pow(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll powmod(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

bool ispal(string &a)
{
    for(int i = 0; i < a.size()/2; i++)
        if(a[i] != a[a.size()-i-1])
            return false;
    return true;
}

ull sum(ull n)
{
    ull x = 0;
    while(n)
    {
        x += n%10;
        n /= 10;
    }
    return x;
}

int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string ss;
        cin>>ss;
        if((n&1) || ss[0] == '0' || ss[n-1] == '0')
        {
            cout<<"NO\n";
            continue;
        }
        int x = 0;
        for(char c : ss)
            if(c == '0')
                x++;
        if(x&1)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        string a="", b="";
        int f0 = 1, f1 = 1;
        a += "(";
        b += "(";
        for(int i = 1; i < n-1; i++)
        {
            char c = ss[i];
            if(c == '0')
            {
                if(f0)
                {
                    a += "(";
                    b += ")";
                }
                else 
                {
                    a += ")";
                    b += "(";
                }
                f0 ^= 1;
            }
            else 
            {
                if(f1) 
                {
                    a += "(";
                    b += "(";
                }
                else 
                {
                    a += ")";
                    b += ")";
                }
                f1 ^= 1;
            }
        }
        a += ")";
        b += ")";
        cout<<a<<"\n"<<b<<"\n";
    }
    return 0;
}
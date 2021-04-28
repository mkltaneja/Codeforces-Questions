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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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

bool ispal(string &a)
{
    for(int i = 0; i < a.size()/2; i++)
        if(a[i] != a[a.size()-i-1])
            return false;
    return true;
}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

int req(int x, int k)
{
    return (k - x%k) % k;
}

int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string a;
        cin>>a;
        
        if(n%k)
        {
            cout<<"-1\n";
            continue;
        }

        vi cnt(26,0);
        for(char c : a) cnt[c-'a']++;

        int sum = 0;
        lp(i, 0, 26) sum += req(cnt[i], k);   // Sum is number of times the particular character is required to make its count divisible by k.

        if(sum == 0)
        {
            cout<<a<<"\n";
            continue;
        }

        bool fl = false;
        string ans = "";
        for(int i = n-1; i >= 0 && !fl; i--)
        {
            char c = a[i];
            sum -= req(cnt[c-'a']--, k);
            sum += req(cnt[c-'a'], k);
            for(int x = (c-'a')+1; x < 26; x++)
            {
                int psum = sum;
                sum -= req(cnt[x]++, k);
                sum += req(cnt[x], k);
                if(sum <= (n-i-1))  // (n-i-1) -> Suffix size
                {
                    fl = true;
                    ans = a.substr(0,i);
                    ans += (char)(x+'a');
                    string suff = "";
                    for(int j = 0; j < 26; j++)
                    {
                        int tot = req(cnt[j], k);
                        while(tot--)
                            suff += (char)(j+'a');
                    }
                    while(suff.size() < (n-i-1)) suff += "a";
                    sort(all(suff));
                    ans += suff;
                    cout<<ans<<endl;
                    break;
                }
                cnt[x]--;
                sum = psum;
            }
        }
    }
    return 0;
}
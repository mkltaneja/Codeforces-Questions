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

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

int main()
{
    fastio();
    int n;
    cin >> n;
    vi a(n);
    lp(i, 0, n)
        cin>>a[i];

    vpii less(n,{0,0});
    lp(i, 1, n)
        if(a[i-1] < a[i])
            less[i].f += less[i-1].f + 1;
    lpr(i, n-2, -1)
        if(a[i+1] < a[i])
            less[i].s += less[i+1].s + 1;
    
    int maxp = 0, count = 0, ip = -1;
    lp(i, 0, n)
    {
        // cout<<less[i].f<<" "<<less[i].s<<endl;
        if(less[i].f > maxp)
        {
            maxp = less[i].f;
            count = 1;
            ip = i;
        }
        else if(less[i].f == maxp)
            count++;
        if(less[i].s > maxp)
        {
            maxp = less[i].s;
            count = 1;
            ip = i;
        }
        else if(less[i].s == maxp)
            count++;
    }
    int ans = 0;
    if(count == 2 && less[ip].f == less[ip].s && !(less[ip].f&1))
        ans = 1;
    cout<<ans<<"\n";

    return 0;
}
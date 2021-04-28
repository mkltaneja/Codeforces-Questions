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
#define for(i, a, b) for(int i = a; i < b; i++)
#define forr(i, b, a) for(int i = b; i > a; i--)
#define forl(i, a, b) for(ll  i = a; i < b; i++)
#define forlr(i, b, a) for(ll i = b; i > a; i--)
#define sorti(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.rbegin(), a.rend())
#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vull a(n), b(n);
        int i = 0, j = 0;
        for(k, 0, 2*n)
        {
            ll x, y;
            cin>>x>>y;
            if(x == 0)
                a[i++] = y*y;
            else 
                b[j++] = x*x;
        }
        sorti(a);
        sorti(b);
        // for(i, n)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        // for(i, n)
        //     cout<<b[i]<<" ";

        double ans = 0;
        for(i, 0, n)
        {
            ans += sqrt(a[i]+b[i]);
        }
        cout<<fixed<<setprecision(17)<<ans<<endl;
    }
}
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
#define for(i, n) for(long i = 0; i < n; i++)
#define for_(i, n, x) for(long i = 0; i < n; i+=x)
#define sorti(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.rbegin(), a.rend())

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long n;
        cin>>n;
        vull a(n), b(n);
        long i = 0, j = 0;
        for(k, 2*n)
        {
            ll x, y;
            cin>>x>>y;
            if(x == 0)
                a[i++] = abs(y);
            else 
                b[j++] = abs(x);
        }
        sorti(a);
        sorti(b);
        // for(i, n)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        // for(i, n)
        //     cout<<b[i]<<" ";

        double ans = 0;
        for(i, n)
        {
            ans += 1.0*sqrt(a[i]*a[i] + b[i]*b[i]);
        }
        cout<<fixed<<setprecision(15)<<ans<<endl;
    }
}
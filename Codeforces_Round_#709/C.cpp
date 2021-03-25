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
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        umii mp;
        vvi d(m);
        for(int i = 0; i < m; i++)
        {
            int k;
            cin>>k;
            d[i].assign(k+1,0);
            d[i][0] = i;
            for(int j = 1; j <= k; j++)
            {
                cin>>d[i][j];
                mp[d[i][j]]++;
            }
        }
        int ans = 0;
        int maxi = (m+1)/2;
        vpii tmp;
        for(auto &p : mp)
        {
            int x = min(maxi, p.s);
            ans += x;
            p.s = x;
            tmp.push_back(p);
        }

        if(ans < m)
        {
            cout<<"NO\n";
            continue;
        }

        // sort(tmp.begin(), tmp.end(), [](const auto &p1, const auto &p2){
        //     return (p1.s < p2.s);
        // });
        sort(d.begin(), d.end(), [](const auto &v1, const auto &v2){
            return v1.size() < v2.size();
        });

        // mp.clear();

        vi res(m);
        for(int i = 0; i < m; i++)
        {
            int mini = INT_MAX, x = d[i][1];
            for(int j = 1; j < d[i].size(); j++)
            {
                if(mp[d[i][j]] > 0 && mp[d[i][j]] < mini)
                {
                    mini = mp[d[i][j]];
                    x = d[i][j];
                }
            }
            mp[x]--;
            res[d[i][0]] = x;
        }
        cout<<"YES\n";
        for(int x : res)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
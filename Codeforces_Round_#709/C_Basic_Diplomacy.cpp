#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define piv pair<int,vi>
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
#define vpiv vector<piv>
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
        vi ans(m,0);
        int x = 0;
        for(int i = 0; i < m; i++)
        {
            int k;
            cin>>k;
            d[i].assign(k,0);
            for(int j = 0; j < k; j++)
            {
                cin>>d[i][j];
                mp[d[i][j]]++;
            }
        }

        // int tot = 0;
        // for(auto p : mp)
        // {
        //     // cout<<p.f<<" "<<p.s<<endl;
        //     tot += min(p.s, (m+1)/2);
        // }
        
        // if(tot < m)
        // {
        //     cout<<"NO\n";
        //     continue;
        // }

        lp(i, 0, m)
        {
            lp(j, 0, d[i].size())
            {
                if(mp[d[i][j]] <= (m+1)/2)
                {
                    ans[i] = d[i][j];
                    break;
                }
            }
        }

        umii mp1;
        lp(i, 0, m)
        {
            if(ans[i]) continue;
            ans[i] = d[i][0];
            mp1[ans[i]]++;
        }

        lp(i, 0, m)
        {
            if(mp1[ans[i]] <= (m+1)/2)
                continue;
            // cout<<ans[i]<<" ";
            for(int j = 0; j < d[i].size(); j++)
            {
                if(mp1[d[i][j]] < (m+1)/2)
                {
                    ans[i] = d[i][j];
                    mp1[d[i][j]]++;
                    mp1[x]--;
                    break;
                }
            }
        }
        int mx = 0;
        lp(i, 0, m)
            mx = max(mx, mp1[ans[i]]);
        if(mx > (m+1)/2)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int x : ans)
                cout<<x<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
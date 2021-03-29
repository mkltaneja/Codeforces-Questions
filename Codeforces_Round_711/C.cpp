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

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vi a(n);
        lp(i, 0, n)
            cin>>a[i];

        int nn = n, sz = 0;
        while(nn)
        {
            sz++;
            nn >>= 1;
        }
        vi pt(sz, 0);
        for(int i = 0; i < n; i++)
        {
            int pos = -1;
            int nn = a[i];
            while(nn)
            {
                pos++;
                nn >>= 1;
            }
            pt[pos]++;
        }

        // sort(rall(pt));
        int ans = 0;

        int w = k;
        int rem = n;
        while(rem > 0)
        {
            int si = 0, ei = sz-1, idx = si;
            while(si <= ei)
            {
                int mid = (si+ei)>>1;
                if(w >= (1<<mid))
                {
                    si = mid+1;
                    idx = mid;
                }
                else ei = mid-1;
            }
            if(idx == -1)
            {
                ans++;
                w = k;
                continue;
            }

            int x = ceil(1.0*(pt[idx]*(1<<idx))/w);
            int y = min(pt[idx], x);
            pt[idx] -= y;
            rem -= y;
            w -= pt[idx]*y;
            if(w == 0)
            {
                ans++;
                w = k;
            }
        }
        cout<<ans<<endl;
    }    
    return 0;
}
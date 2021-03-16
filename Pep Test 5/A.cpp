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

psi srep(string &a, int n)
{
    int i = 0, cnt = 1, li = 0;
    string sa = "";
    for(int i = 0; i <= n/2; i++)
    {
        string tmp = a.substr(0,i+1);
        int j = i+1;
        bool fl = true;
        int c = 1;
        while(j < n)
        {
            if(a.substr(j,i+1) != tmp)
            {
                fl = false;
                break;
            }
            c++;
            j += i+1;
        }
        if(fl)
        {
            sa = tmp;
            cnt = c;
            break;
        }
    }

    if(sa == "")
        sa = a;
    return {sa, cnt};



    // while(i < n)
    // {
    //     int j = 0, ci = i;
    //     while(ci < n && j <= li && a[ci] == a[j])
    //         j++, ci++;
    //     if(j != li+1 || sa == "")
    //     {
    //         sa = a.substr(0,i+1);
    //         li = i;
    //         cnt = 1;
    //         i++;
    //         cout<<sa<<" -> "<<cnt<<"\n";
    //     }
    //     else 
    //     {
    //         cnt++, i = ci;
    //         cout<<sa<<" -> "<<cnt<<"\n";
    //     }
    // }
    // return {sa, cnt};
}

int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;

        string ans = "";
        psi sa = srep(a, a.size());
        // cout<<endl;
        psi sb = srep(b, b.size());
        // cout<<sa.f<<" "<<sa.s<<", "<<sb.f<<" "<<sb.s<<endl;
        if(sa.f != sb.f)
        {
            cout<<"-1\n";
            continue;
        }
        int lcm = (sa.s*sb.s)/__gcd(sa.s, sb.s);
        while(lcm--)
            ans += sa.f;
        cout<<ans<<"\n";
    }
    return 0;
}
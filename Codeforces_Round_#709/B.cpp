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
        int n;
        cin>>n;
        vi a(n);
        for(int i = 0; i < n; i++)
            cin>>a[i];
        
        int cd1 = INT_MIN, cd2 = INT_MIN;
        unordered_set<int> st;
        int maxi = 0;
        for(int i = 0; i < n-1; i++)
        {
            maxi = max(maxi, a[i]);
            int cd = (a[i+1] - a[i]);
            st.insert(abs(cd));
            // cout<<cd<<endl;
            if(cd1 == INT_MIN || cd1 == cd)
                cd1 = cd;
            else if(cd2 == INT_MIN || cd2 == cd)
                cd2 = cd;
        }
        maxi = max(maxi, a[n-1]);
        // cout<<cd1<<" "<<cd2<<endl;
        int c = (cd1 > 0) ? cd1 : cd2;
        if(cd2 == INT_MIN || n <= 2)
        {
            cout<<"0\n";
            continue;
        }
        if(st.size() > 2 || c < 0)
        {
            // cout<<st.size()<<": \n";
            cout<<"-1\n";
            continue;
        }

        cd1 = abs(cd1);
        cd2 = abs(cd2);
        if(cd1 == 0 || cd2 == 0)
        {
            // cout<<(cd1&cd2)<<endl;
            cout<<"-1\n";
            continue;
        }
        if(cd1+cd2 <= maxi)
        {
            // cout<<maxi<<endl;
            cout<<"-1\n";
            continue;
        }

        int m = (cd1+cd2);
        cout<<m<<" "<<c<<"\n";
        // cout<<maxi<<endl;
        // if(m == 376040742)
        // {
        //     cout<<n<<": \n";
        //     for(int x : a)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
    }
    return 0;
}
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


// bool check(string &ss, char rem)
// {
//     bool fl = false;
//     if(rem == '0')
//     {
//         for(int i = 0; i < ss.size()-1; i++)
//         {
//             if(ss[i+1] == ss[i] && ss[i] == '0' && fl)
//                 return false;
//             if(ss[i] == '1')
//                 fl = true;
//         }
//     }
//     else 
//     {
//         for(int i = ss.size()-1; i > 0; i--)
//         {
//             if(ss[i-1] == ss[i] && ss[i] == '1' && fl)
//                 return false;
//             if(ss[i] == '0')
//                 fl = true;
//         }
//     }
//     return true;
// }

bool check(string &st)
{
    for(int i = 1; i < st.size()-2; i++)
    {
        if(st[i] == '1' && st[i+1] == '0')
        {
            if(st[i-1] == '1' && st[i+2] == '0')
                return false;
            if(st[i-1] == '1')
                st[i+1] = '1';
            else if(st[i+2] == '0')
                st[i] = '0';
        }
        // cout<<i<<endl;
    }
    return true;
}

int main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        string st;
        cin>>st;
        string ss = st;
        sort(ss.begin(), ss.end());
        // cout<<ss<<endl;
        if(ss == st)
        {
            cout<<"YES\n";
            continue;
        }
        bool fl = check(st);
        // cout<<st<<endl;

        if(fl)
            cout<<"YES\n";
        else 
            cout<<"NO\n";

        // bool f1 = check(st, '0');
        // bool f2 = check(st, '1');
        // if(f1 || f2)
        // {
        //     cout<<"YES\n";
        //     continue;
        // }
        // cout<<"NO\n";
    }
    return 0;
}
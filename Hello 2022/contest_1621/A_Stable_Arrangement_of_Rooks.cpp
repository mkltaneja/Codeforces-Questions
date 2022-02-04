#include <bits/stdc++.h>
using namespace std;

// int solve1(int n, vector<int> &a, vector<int> &b)
// {
//     int ans = 0;
//     for(int i = 0; i < n; i++)
//         ans += (a[i] == b[i]);
//     return (ans + 1)/2;
// }

int solve2(int x, int n, vector<int> &a)
{
    vector<int> cnt(32,0);
    int lb = 0;
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cnt[i] += (a[j] & (1 << i)) > 0;
            lb = cnt[i]? i : lb;
            // cout<<cnt[i]<<", ";
        }
        // cout<<endl;
    }
    int ans = 0;
    long long avail = 0, y = lb;
    for(int i = 31; i >= 0; i--)
    {
        avail = avail*2 + cnt[i];
        // cout<<i<<" -> "<<cnt[i]<<", "<<avail<<endl;
    
        if(x & (1 << i))
        {
            if(lb < i || !avail) 
            {
                // cout<<i<<" -> "<<"lb = "<<lb<<endl;
                return -1;
            }
            // cout<<y<<endl;
            ans += !cnt[i]? y-i : 0;
            // avail--;
            if(avail) y = i;
        }
    }
    // cout<<endl;

    return ans;
}


// int solve2(int x, int n, vector<int> &a)
// {
//     int ans = 0;
//     while(x)
//     {
//         x >>= 1;
//         ans++;
//     }
//     return ans;
// }

int main()
{
    int x,n;
    cin>>x>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];

    // cout<<solve1(n, a, b);
    cout<<solve2(x, n, a);
}

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++)
//         cin>>a[i];
//     vector<int> b(n);
//     for(int i = 0; i < n; i++)
//         cin>>b[i];

//     // cout<<solve1(n, a, b);
//     cout<<solve2(n, a, b);
// }


// #define f first
// #define s second
// #define ll long long int
// #define ull unsigned long long int
// #define pii pair<int, int>
// #define pib pair<int, bool>
// #define pbi pair<bool, int>
// #define pbb pair<bool, bool>
// #define pic pair<int, char>
// #define pci pair<char, int>
// #define pcc pair<char, char>
// #define pis pair<int, string>
// #define psi pair<string, int>
// #define pss pair<string, string>
// #define vi vector<int>
// #define vvi vector<vi>
// #define vd vector<double>
// #define vvd vector<vd>
// #define vll vector<ll>
// #define vvll vector<vll>
// #define vull vector<ull>
// #define vvull vector<vull>
// #define vb vector<bool>
// #define vvb vector<vb>
// #define vc vector<char>
// #define vvc vector<vc>
// #define vs vector<string>
// #define vvs vector<vs>
// #define vpii vector<pii>
// #define vpbi vector<pbi>
// #define vpib vector<pib>
// #define vpbb vector<pbb>
// #define vpci vector<pci>
// #define vpic vector<pic>
// #define vpcc vector<pcc>
// #define vpsi vector<psi>
// #define vpis vector<pis>
// #define vpss vector<pss>
// #define um unordered_map
// #define umii unordered_map<int, int>
// #define umci unordered_map<char, int>
// #define umic unordered_map<int, char>
// #define umsi unordered_map<string, int>
// #define umis unordered_map<int, string>
// #define omii map<int, int>
// #define omci map<char, int>
// #define omic map<int, char>
// #define omsi map<string, int>
// #define omis map<int, string>
// #define lp(i, a, b) for (int i = a; i < b; i++)
// #define lpr(i, b, a) for (int i = b; i > a; i--)
// #define lpl(i, a, b) for (ll i = a; i < b; i++)
// #define lplr(i, b, a) for (ll i = b; i > a; i--)
// #define all(a) a.begin(), a.end()
// #define rall(a) a.rbegin(), a.rend()
// #define fastio()                          \
//     {                                     \
//         ios_base::sync_with_stdio(false); \
//         cin.tie(NULL);                    \
//         cout.tie(NULL);                   \
//     }
// #define mod 1000000007

// ll binpow(ll a, ll b)
// {
//     ll ans = 1;
//     while (b)
//     {
//         if (b & 1)
//             ans *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return ans;
// }
// ll binpowmod(ll a, ll b)
// {
//     ll ans = 1;
//     while (b)
//     {
//         if (b & 1)
//             ans = (ans * a) % mod;
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return ans;
// }

// bool ispal(string &a)
// {
//     for (int i = 0; i < a.size() / 2; i++)
//         if (a[i] != a[a.size() - i - 1])
//             return false;
//     return true;
// }

// void display(int n, vi &a)
// {
//     for (int x : a)
//         cout << x << " ";
//     cout << "\n";
// }
// void display(int n, int m, vvi &a)
// {
//     lp(i, 0, n)
//     {
//         lp(j, 0, m)
//                 cout
//             << a[i][j] << " ";
//         cout << "\n";
//     }
//     cout << "\n";
// }

// //////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

// void solve(int n, int k)
// {
//     if (k > (n + 1) / 2)
//     {
//         cout << "-1\n";
//         return;
//     }
//     int x = 0, y = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == x && j == y && k)
//             {
//                 k--;
//                 cout << "R";
//                 x += 2;
//                 y += 2;
//             }
//             else
//                 cout << ".";
//         }
//         cout << endl;
//     }
//     // cout<<endl;
// }

// int main()
// {
//     fastio();
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         solve(n, k);
//     }
//     return 0;
// }

// class Pair
// {
// public:
//     int cgl, csl, cgr, csr;
//     Pair()
//     {
//         this->cgl = 0;
//         this->csl = 0;
//         this->cgr = 0;
//         this->csr = 0;
//     }
// };

// void fill_cgl_cgr(int n, vector<int> &A, vector<Pair> &conf)
// {
//     stack<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         while (!st.empty() && A[i] >= A[st.top()])
//         {
//             conf[st.top()].cgr = i - st.top();
//             st.pop();
//         }
//         if (!st.empty())
//             conf[i].cgl = i - st.top();
//         st.push(i);
//     }
// }

// void fill_csl_csr(int n, vector<int> &A, vector<Pair> &conf)
// {
//     stack<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         while (!st.empty() && A[i] <= A[st.top()])
//         {
//             conf[st.top()].csr = i - st.top();
//             st.pop();
//         }
//         if (!st.empty())
//             conf[i].csl = i - st.top();
//         st.push(i);
//     }
// }

// long long ValueOfA(int n, vector<int> &A)
// {
//     long long ans = 0;

//     vector<Pair> conf(n);

//     for (int i = 0; i < n; i++)
//     {
//         conf[i].cgl = i + 1;
//         conf[i].csl = i + 1;
//         conf[i].cgr = n - i;
//         conf[i].csr = n - i;
//     }

//     fill_cgl_cgr(n, A, conf);
//     fill_csl_csr(n, A, conf);

//     for (int i = 0; i < n; i++)
//         ans += A[i] * (((long long)conf[i].cgl * conf[i].cgr) - ((long long)conf[i].csl * conf[i].csr));

//     return ans;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for (int i = 0; i < n; i++)
//         cin >> A[i];
//     cout << ValueOfA(n, A);
// }


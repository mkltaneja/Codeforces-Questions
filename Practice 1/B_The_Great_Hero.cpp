#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A, B, n;
        cin>>A>>B>>n;
        vector<int> a(n), b(n);
        for(int i = 0 ; i < n; i++)
            cin>>a[i];
        for(int i = 0 ; i < n; i++)
            cin>>b[i];

        vector<pair<int,int>> p(n);
        for(int i = 0 ; i < n; i++)
            p[i] = {a[i], b[i]};
        sort(p.begin(), p.end());

        bool f = true;
        for(int i = 0; i < n; i++)
        {
            if(B <= 0)
            {
                f = false;
                break;
            }
            int x = ceil(1.0*(p[i].s)/A);
            int y = ceil(1.0*B/p[i].f);
            B -= p[i].f * min(x,y);
            p[i].s -= A * min(x,y);
            if(p[i].s > 0)
            {
                f = false;
                break;
            }
        }
        if(f)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
}

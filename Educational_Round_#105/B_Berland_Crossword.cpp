#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        bool ok = false;

        for(int mask = 0; mask < 16; mask++)
        {
            int uu = u, rr = r, dd = d, ll = l;
            for(int c = 0; c < 4; c++)
            {
                if(mask & (1<<c))
                {
                    if(c == 0)
                        uu--, rr--;
                    else if(c == 1)
                        rr--, dd--;
                    else if(c == 2)
                        dd--, ll--;
                    else if(c == 3)
                        ll--, uu--;
                }
            }
            if(uu<0 || rr<0 || dd<0 || ll<0)
                continue;
            if(uu>(n-2) || rr>(n-2) || dd>(n-2) || ll>(n-2))
                continue;
            ok = true;
            break;
        }
        if(ok)
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }
    return 0;
}
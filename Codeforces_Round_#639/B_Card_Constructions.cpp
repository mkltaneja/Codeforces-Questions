#include<iostream>
#include<vector>
using namespace std;
using lli = long long int;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        if(n == 1)
        {
            cout<<0<<endl;
            continue;
        }
        vector<lli> cardheight;
        for(lli i=0;i<n;i++)
        {
            lli numcards = ((i+1)*(i+2))+((i)*(i+1)/2);
            if(numcards <= n)
                cardheight.push_back(numcards);
            else 
                break;
        }
        // cout<<cardheight.size()<<" ";
        // for(int i=0;i<cardheight.size();i++)
        //     cout<<cardheight[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<cardheight.size()-1;i++)
        //     cout<<" "<<cardheight[i+1] - cardheight[i];
        lli ans = 1;
        lli x = n - cardheight[cardheight.size()-1];
        // cout<<x;
        // if(x <= 1)
        // {
        //     cout<<0;
        //     continue;
        // }
        while(x > 1)
        {
            lli nc = cardheight[0];
            for(int i=1;i<cardheight.size();i++)
            {
                if(cardheight[i] > x)
                    break;
                nc = cardheight[i];
            }
            ans++;
            x -= nc;
        }
        cout<<ans<<endl;
    }
}
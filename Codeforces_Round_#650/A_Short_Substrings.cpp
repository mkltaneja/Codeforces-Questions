#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s.size() == 2)
        {
            cout<<s<<endl;
            continue;
        }
        string st = "";
        st += s[0];
        for(int i=1;i<s.size();i+=2)
            st += s[i];
        cout<<st<<endl;
    }
}
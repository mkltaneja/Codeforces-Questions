#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int odd = 0, even = 0;
        for(int ele : arr)
        {
            if(ele&1)
                odd++;
            else 
                even++;
        }
        if(!(odd&1) && !(even&1))
        {
            cout<<"YES\n";
            continue;
        }
        else 
        {
            bool flag = false;
            for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(abs(arr[j]-arr[i]) == 1)
                    {
                        cout<<"YES\n";
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(!flag)
                cout<<"NO\n";
        }
    }
    return 0;
}
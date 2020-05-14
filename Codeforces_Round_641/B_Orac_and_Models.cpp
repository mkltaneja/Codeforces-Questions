#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        long int arr[n+1];
        for(int i=1;i<=n;i++)
            cin>>arr[i];

        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }

        int maxsize = 1; 
        for(int i=1;i<n/2;i++)
        {
            int size = 1;
            if(maxsize > n/i)
                break;
            for(int j=i+i;j<=n;j+=i)
            {
                if(arr[j] > arr[i])
                    size++;
            }
            maxsize = max(size,maxsize);
        }
        cout<<maxsize<<endl;

        int lis[n+1];
        lis[1] = 1;
        for(int i=2;i<=n;i++)
        {
            lis[i] = 1;
            for(int j=1;j<=i/2;j++)
                if(arr[i] > arr[j] && i % j == 0 && lis[j] + 1 > lis[i])
                    lis[i] = lis[j] + 1;
        }
        int maxi = 0;
        for(int i=1;i<=n;i++)
            maxi = max(maxi,lis[i]);
        cout<<maxi<<endl;
    }
}
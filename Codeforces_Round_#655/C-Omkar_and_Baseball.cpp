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
        bool fs = true;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i] != i+1)
                fs = false;
        }
        int i = 0;
        int discont = 0;
        while(i < n)
        {
            if(arr[i] != i+1)
            {
                discont++;
                while(i < n && arr[i] != i+1)
                    i++;
            }
            i++;
        }

        if(fs)    // whole array is sorted
        {
            cout<<0<<endl;
            continue;
        }
        if(discont == 1)    // there is only one unsorted cluster or subarray in the whole array
        {
            cout<<1<<endl;
            continue;
        }
        cout<<2<<endl;    // more than 1 clusters of unsortingness, so we will make the whole array sorted in one move and then sort in other move
    }
}
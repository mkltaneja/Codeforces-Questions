#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool fi = true;
        bool fd = true;
        for (int i = 0; i < n-1 ; i++)
        {
            if (arr[i + 1] < arr[i])
                fi = false;
            if (arr[i + 1] > arr[i])
                fd = false;
        }
        if (fi || fd)
        {
            cout << 0 << endl;
            continue;
        }
        if(n < 3)
        {
            cout<<0<<endl;
            continue;
        }

        char c;
        if(arr[n-2] < arr[n-1])
            c = 'd';
        else 
            c = 'u';

        int i = n-1;
        for(; i > 0; i--)
        {
            if(c == 'd' && arr[i-1] > arr[i])
                break;
            else if(c == 'u' && arr[i-1] < arr[i])
                c = 'd';
        }
        cout << i << endl;
    }
}
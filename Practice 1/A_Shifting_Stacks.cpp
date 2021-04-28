#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        ll sum = 0, need = 0;
        bool f = true;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            need += i;
            if(need > sum)
            {
                f = false;
                break;
            }
        }
        if (!f)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
    return 0;
}

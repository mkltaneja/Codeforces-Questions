#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int

int main()
{
    int a, b, n, m, k;
    cin >> a >> b >> n >> m >> k;

    int maxi = 0, mini = a + b, kk = k;
    if (m < n)
    {
        maxi = min(kk / m, b);
        kk -= maxi * m;
        if (kk > 0)
            maxi += min(kk / n, a);
    }
    else
    {
        maxi = min(kk / n, a);
        kk -= maxi * n;
        if (kk > 0)
            maxi += min(kk / m, b);
    }

    // if (kk >= m * b)
    // {
    //     kk -= m * b;
    //     maxi += b;
    // }
    // else
    // {
    //     maxi += kk / m;
    //     kk = 0;
    // }
    // maxi += kk / n;

    // k -= (a * (n - 1) + b * (m - 1));
    // if (k <= 0)
    //     mini = 0;
    // else
    //     mini = min(k, a + b);

    int min = (n - 1) * a + (m - 1) * b;
    int ans1 = 0, ans2 = 0;
    //min
    if (min <= k)
    {
        ans1 = 0;
    }
    else
    {
        ans1 = k - min;
    }

    cout << mini << " " << maxi << endl;

    return 0;
}
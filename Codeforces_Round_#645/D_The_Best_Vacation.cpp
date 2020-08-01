#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    int d[n];
    int ans = 0;
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        if (d[i] >= x)
        {
            ans = max(ans, d[i]);
            f = true;
        }
    }
    if (f)
    {
        cout << (((ans * (ans + 1)) / 2) - (((ans-x)*(ans-x+1))/2));
        return 0;
    }
    vector<int> ds;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= d[i]; j++)
            ds.emplace_back(j);

    // for(int i=0;i<ds.size();i++)
    //     cout<<ds[i]<<" ";

    int hugs = 0;
    int maxhugs = 0;
    int year = false;
    for (int i = 0; year && (i-x-1) == 0; i = ((i + 1) % n))
    {
        cout<<i<<endl;
        if (i >= x)
            hugs -= ds[i - x];
        hugs += ds[i];
        maxhugs = max(hugs, maxhugs);
        if(i == n-1)
            year = true;
    }
    cout << maxhugs << endl;
}
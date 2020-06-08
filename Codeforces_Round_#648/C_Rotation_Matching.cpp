#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    map<int, int> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        m[b[i]] = i;
    }

    vector<int> ra(n, 0);

    for (int i = 0; i < n; i++)
    {
        int opa;
        int j = m[a[i]];
        if (j < i)
            opa = (n - i) + j;
        else
            opa = j - i;
        ra[opa]++;
    }
    int maxi = 0;
    
    // for (int i = 0; i < n; i++)
    //     cout<<ra[i]<<" "<<endl;
    for (int i = 0; i < n; i++)
        maxi = max(maxi,ra[i]);
    cout << maxi;
}

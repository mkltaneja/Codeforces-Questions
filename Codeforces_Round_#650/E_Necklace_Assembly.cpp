#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char, int> m;
        for (char c : s)
        {
            m[c]++;
        }
        if (k >= n)
        {
            while (k % n != 0)
                n--;
            cout << n << endl;
            continue;
        }
        int n1 = n;
        bool f = false;
        while (n1 - k)
        {
            if ((n1 % k != 0) || (n1 % (n1-k) != 0))
            {
                if (m[s[0]] == n1)
                {
                    cout << n1 << endl;
                    f = true;
                    break;
                }
            }

            else
            {
                int k1 = k;
                map<char, int> m1 = m;
                for(const auto &itr : m)
                {
                    k1 -= (itr.second / k);
                    if(k1 <= 0)
                    {
                        cout<<n1<<endl;
                        f = true;
                        break;
                    }
                }
            }
            if (f)
                continue;
            n1--;
        }
    }
}
#include <iostream>
#include <vector>
using namespace std;

/*
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        int a = 0;
        int b = 1;
        int c = 2;
        vector<int> minlenarr;
        int maxsum = 0;
        minlenarr.push_back(p[a]);
        
        for (; c < n; a++, b++, c++)
        {
            if ((p[b] > p[a] && p[b] > p[c]) || (p[b] < p[a] && p[b] < p[c]))
            {
                minlenarr.push_back(p[b]);
                maxsum += abs(p[b] - p[a]) + abs(p[b] - p[c]);
            }
            else if ((p[b] >= p[a] && p[b] <= p[c]) || (p[b] <= p[a] && p[b] >= p[c]))
            {
                maxsum += abs(p[a] - p[c]);
            }
        }
        
        minlenarr.push_back(p[c-1]);
        cout<<minlenarr.size()<<endl;
        for(int i : minlenarr)
            cout<<i<<" ";
        cout<<endl;
    }
}
*/
/////////////////OR/////////////////////

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<int> minlenarr;
        for(int i=0;i<n;i++)
            if(i == 0 || i == n-1 || p[i] > p[i-1] == p[i] > p[i+1])
                minlenarr.push_back(p[i]);
        
        cout<<minlenarr.size()<<endl;
        for(int i : minlenarr)
            cout<<i<<" ";
        cout<<endl;
    }
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int num = n;
        int count = 0;
        while(num)
        {
            int n1 = num;
            while(n1)
            {
                n1 &= (n1-1);
                count++;
            }
            num >>= 1;
        }
        cout<<count<<endl;
    }

}
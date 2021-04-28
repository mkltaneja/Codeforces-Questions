#include <iostream>
using namespace std;
int main()
{
    int n, m, c, count = 0;
    cin >> n;
    while (n--)
    {
        cin >> m >> c;
        if(m > c)
            count++;
        else if(m < c)
            count--;
    }
    if(count > 0)
        cout<<"Mishka";
    else if(count < 0)
        cout<<"Chris";
    else
        cout<<"Friendship is magic!^^";
}
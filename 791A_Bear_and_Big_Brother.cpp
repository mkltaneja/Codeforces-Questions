#include <iostream>
using namespace std;

int total_years(int a, int b)
{
    if(a > b)
        return 0;
    return total_years(a*3,b*2) + 1;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<total_years(a,b);
}
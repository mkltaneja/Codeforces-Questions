#include<iostream>
using namespace std;

int winner(int n, string str)
{
    int count = 0;
    for(int s=0;s<n;s++)
    {
        if(str[s] == 'A')
            count++;
        else
            count--;
    }
    return count;
}

int main()
{
    int n;
    string str;
    cin>>n>>str;

    int win = winner(n,str);
    if(win > 0)
        cout<<"Anton";
    else if(win < 0)
        cout<<"Danik";
    else 
        cout<<"Friendship";
}
#include <iostream>
using namespace std;

int min_moves(int matrix[6][6])
{
    int r = 0, c = 0;
    bool flag = false;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (matrix[i][j] == 1)
            {
                r = i;
                c = j;
                break;
                flag = true;
            }
        }
        if(flag)
            break;
    }
    return abs(r-3)+abs(c-3);
}

int main()
{
    int matrix[6][6];
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            cin >> matrix[i][j];

    cout << min_moves(matrix);
}
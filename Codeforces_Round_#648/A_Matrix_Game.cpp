#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        vector<bool> row(n, false);
        vector<bool> col(m, false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 1)
                {
                    row[i] = true;
                    col[j] = true;
                }

        int count = 0;
        for (int i = 0; i < n * m; i++)
        {
            int r = i / m;
            int c = i % m;

            if (!row[r] && !col[c] && !arr[r][c])
            {
                row[r] = true;
                col[c] = true;
                arr[r][c] = 1;
                count++;
            }
        }
        if (count % 2)
            cout << "Ashish\n";
        else
            cout << "Vivek\n";
    }
}
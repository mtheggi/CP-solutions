#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, max, row1, row2;
    cin >> n >> k;
    if (n % 2 == 1)
    {
        row1 = n / 2 + 1;
        row2 = n - row1;
        max = row1 * row1 + row2 * row2;
    }
    else
    {
        row1 = n / 2;
        max = row1 * n;
    }

    vector<vector<char>> v(n, vector<char>(n, 'S'));
    bool flage;
    if (k > max)
    {
        cout << "NO" << endl;
        flage = false;
    }
    else
    {
        cout << "YES" << endl;
        flage = true;
        for (int i = 0; i < n; ++i)
        {
            if (k == 0)
                break;
            for (int j = 0; j < n; ++j)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 == 0)
                    {
                        v[i][j] = 'L';
                        k--;
                    }
                }
                else
                {
                    if (j % 2 == 1)
                    {
                        v[i][j] = 'L';
                        k--;
                    }
                }
                if (k == 0)
                    break;
                
            }
        }
    }
    if (flage)
    {
        for (auto i : v)
        {
            for (auto j : i)
            {
                cout << j;
            }
            cout << endl;
        }
    }

    return 0;
}

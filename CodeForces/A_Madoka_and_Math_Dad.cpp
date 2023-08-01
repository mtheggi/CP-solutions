#include <bits/stdc++.h>
// mohamed
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;
    int n;
    int z;
    vector<int> v;
    while (t--)
    {
        cin >> n;
        z = n % 3;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << 2 << endl;
            continue;
        }
        if (z == 1)
        {
            while (true)
            {
                if (n - 1 < 0)
                {
                    break;
                }
                cout << 1;
                n -= 1;
                if (n - 2 < 0)
                {
                    break;
                }
                cout << 2;
                n -= 2;
            }
        }
        else if (z == 2)
        {
            while (true)
            {

                if (n - 2 < 0)
                {
                    break;
                }
                cout << 2;
                n -= 2;
                if (n - 1 < 0)
                {
                    break;
                }
                cout << 1;
                n -= 1;
            }
        }
        else if (z == 0)
        {
           for (size_t i = 0; i < n/3; i++)
           {
               cout << 21;
           }
           
        }

        cout << endl;
    }
    return 0;
    // 8 = >> 21212
    // 8 = > 121212
}
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    set<char> z;
    set<char> y;
    

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            if (i == j || i + j == n - 1)
                z.insert(s[j]);
            else
                y.insert(s[j]);
    }

    if (z.size() == 1 && y.size() == 1 && *z.begin() != *y.begin())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
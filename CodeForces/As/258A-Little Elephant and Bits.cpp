#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int main()
{
    fastio;
    string s;
    cin >> s;
    int z = s.length();
    for (int i = 0; i < z; i++)
    {
        if (s[i] == '0')
        {
            s.erase(s.begin() + i);
            break;
        }
    }
    if (z == s.length())
    {
        s.erase(s.begin());
    }
    cout << s << el;

    return 0;
}

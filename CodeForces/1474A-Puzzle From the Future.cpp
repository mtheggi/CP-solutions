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
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        string s;
        cin >> s;
        string z = "1";
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] + '1' == (s[i - 1] + z[i - 1]))
            {
                z.push_back('0');
            }
            else
            {
                z.push_back('1');
            }
        }

        cout << z << endl;
    }
    return 0;
}

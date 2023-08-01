#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<char> dq;
    int n, m;
    string s;
    cin >> n;
    cin >> s;
    string e = "";
    int i = 0;
    m = n;
    while (m)
    {
        if (m % 2 == 0)
        {
            dq.push_front(s[i]);
        }
        else
        {
            dq.push_back(s[i]);
        }

        m--;
        i++;
    }

    for (int i = 0; i < n; ++i)
    {
        e.push_back(dq.front());
        dq.pop_front();
    }
    cout << e << endl;
}

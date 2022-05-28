#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
#define ll long long
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        vector<int> v2;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int seg = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            if (sum % 2 == 1)
            {

                if (v2.size() < k - 1)
                {
                    sum = 0;
                    v2.push_back(i + 1);
                }
                else if (v2.size() == k - 1 && i + 1 == n)
                {
                    v2.push_back(i + 1);
                }
            }
        }

        if (v2.size() == k)
        {
            cout << "YES" << endl;
            for (int i = 0; i < v2.size(); i++)
            {
                cout << v2[i];
                cout << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

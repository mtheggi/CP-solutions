#include <iostream>
#include <vector>
using namespace std; //
int main()
{
    int k;
    cin >> k;
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int j = 0; j < k; j++)
    {
        int mn;
        int mx;

        if (j == 0)
        {
            mn = abs(v[0] - v[1]);
            mx = abs(v[0] - v.back());
        }
        else if (j == k - 1)
        {

            mn = abs(v[k - 1] - v[k - 2]);
            mx = abs(v[k - 1] - v[0]);
        }

        else
        {
            mn = min(abs(v[j] - v[j - 1]), abs(v[j] - v[j + 1]));
            mx = max(abs(v[j] - v[k - 1]), abs(v[j] - v[0]));
        }
        cout << mn << " " << mx << endl;
    }
}
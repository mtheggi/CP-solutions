#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    int n;
    double k;
    cin >> n >> k;
    vector<int> x(n);
    vector<int> y(n);

    for (int j = 0; j < n; j++)
    {
        double x1, y1;
        cin >> x1 >> y1;
        x[j] = x1;
        y[j] = y1;
     
    }

   long double sumx = 0.0;
    for (int i = 0; i < x.size() - 1; i++)
    {

        sumx = sumx + sqrt(pow((x[i] - x[i + 1]), 2) + pow((y[i] - y[i + 1]), 2));
    }
     
    cout << setprecision(10)<<  ((sumx) / 50.0) * k;
    // cout << 10 / 50.000;
    return 0;
}

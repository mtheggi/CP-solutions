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
    int count =0 ;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    vector<int> x;
    vector<int> ans;
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int t;
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {   count++;
            x.push_back(v[i]);
            x.push_back(v[i + 1]);
        }
    }
    if (count == 0)
    {
        cout << -1;
    }
    else
    {
        for(int j = 0; j < x.size(); j=j+2){
            ans.push_back((x[j+1]-x[j])/2);
        }
        sort(ans.begin(),ans.end());
        cout << *ans.begin() << endl; //
    }

    return 0;
}

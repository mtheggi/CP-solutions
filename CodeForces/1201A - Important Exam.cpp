#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int const N = 2e9 +1  ;
int n ,k ;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m ;
    vector<string> s(n) ;
    vector<int> v(m);
    vector<int>vempty(m);
    for (int i = 0; i <n ; ++i) {
        cin >>s[i];
    }
    for (int i = 0; i <m ; ++i) {
        cin >>v[i] ;
    }

    for (int i = 0; i < m; ++i) {
        vector<int> ans(5 ,0);
        for (int j = 0; j <n ; ++j) {
            if (s[j][i] == 'A')
                ans[0]++;
            if (s[j][i] == 'B')
                ans[1]++;
            if (s[j][i] == 'C')
                ans[2]++;
            if (s[j][i] == 'D')
                ans[3]++;
            if (s[j][i] == 'E')
                ans[4]++;
        }
        sort(ans.begin(), ans.end());
        vempty[i] = ans[4];

    }

    int sum =0 ;
    for (int i = 0; i <m ; ++i) {
        sum += (vempty[i] * v[i]);
    }
    cout << sum <<endl;
    return 0 ;
}

#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif

	int y ;cin >> y; 
    while (y--){
		int n ,k;
		cin >> n >>k;
		vector<ll> v(n) ;

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i] ;
		}

		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			while(v[i] > 0 && j<k){
				v[i]--;
				v[n-1]++;
				j++;

			}
		}
		for (auto i : v)
		{
			cout << i <<" "; 
		}
		cout <<el;


    }


	return 0;

}
	



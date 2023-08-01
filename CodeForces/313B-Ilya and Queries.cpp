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
    string s;
    cin >>s;
    vector<int > v(s.length()+2,0);
    for (int i = 1; i < s.length()+1; i++)
    {
        if(s[i-1] == s[i]){
            v[i]= 1;
        }else{
            v[i]= 0;
        }
    }
    vector<int > preS(s.length()+2,0); // prefix sum vector 
    for (int i = 1; i < s.length()+1; i++)
    {
        preS[i] = preS[i-1]+ v[i];
    }  

	int y ;cin >> y; 
    // for(auto i : v ){
    //     cout << i << " ";
    // }
    // cout <<el;
    // for(auto i : prev ){
    //     cout << i << " ";
    // }
    cout << el;
    while (y--){
		int n ,k;
		cin >> n >>k;
		cout << preS[k-1] - preS[n-1] <<endl;
    }


	return 0;

}
	



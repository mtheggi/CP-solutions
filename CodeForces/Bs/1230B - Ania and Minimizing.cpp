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


	ll n ;cin >> n;
	ll k; cin >> k; 
	string s ;
	cin >>s ;
    if(k== 0){
        cout << s <<endl;
        return 0;
    }
	if(s == "1" || s.length() == 1 ){
		cout << 0 <<endl; 
		return 0 ;
	}
	ll count = 0 ;
	ll i = 0 ;
	while(count != k && i <s.length())
	{
		
		if(i == 0){
			if(s[i] != '1'){
				s[i] = '1';
				count++;
			}
		}else{
			if(s[i] !='0'){
				s[i] = '0' ;
				count++;
			}
		}
		i++;
	}		 
	cout << s <<endl;

    return 0;
}

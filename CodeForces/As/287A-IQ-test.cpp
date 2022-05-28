#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std; 
int main() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input","rt",stdin); 
    #endif
	string arr[4];
	for (int i=0; i<4; i++) {
        cin >> arr[i];
        }
	bool ANSWER = false;
	
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			int count = (arr[i][j] == '.') + (arr[i+1][j] == '.') + (arr[i][j+1] == '.') + (arr[i+1][j+1] == '.');
			if (count != 2) ANSWER = true;
		}
	}
	
	if (ANSWER) cout << "YES";
	else cout << "NO";
}
 
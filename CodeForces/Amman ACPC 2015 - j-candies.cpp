#include <bits/stdc++.h>

#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
using namespace std;
#define ll long long
#define ld long double
int main() {
    fastio;
    int t; cin >> t ;
    while(t--){
        int n , m;  cin >> n >> m ;
        vector<int> s(n), p(m);
        map<int ,int > ages, sizes;
        for(int i =0 ; i < n ; i++){
            cin >> s[i] ;
            ages[s[i]]++;
        }
        for (int i = 0; i <m ; ++i) {
            cin >> p[i] ;
            sizes[p[i]]++;
        }
        bool f =1 ;
        if(sizes.size() < ages.size() ){
            f=0 ;
        }
        int all=0 ;
        if(f){
            map<int ,int>:: iterator j = ages.begin();
            for(auto i : sizes ){
                if((*j).second<=i.second){
                    all+=((*j).second);
                    j++;
                    if(j == ages.end()){
                        break;
                    }
                }
            }
            if( all != s.size() ){
                f =0;
            }
        }
        if(f)
            cout << "YES" <<el;
        else
            cout << "NO" <<el;

    }
    return 0;
}

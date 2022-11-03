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

    auto checkBit = [](int x, int i){
        return x & (1 << i);
    };
    int t; cin >> t ;
    while(t--) {
        int n , s ; cin >> n >>s;
        vector<int> a(n);
        for (int i = 0; i <n ; ++i) {
            cin >> a[i];
        }
        int limit = (1 << (n+1)) - 1;
        int res = INT_MIN;
        for(int msk = 0; msk <= limit; msk++){
                int sum =0;
                int size =0;
                vector<int> penn ;
            for(int i = 0; i < n; i++){
                if(checkBit(msk, i)){
                           sum+=a[i];
                           penn.push_back(a[i]);
                }
            }
            if(sum >= s){
                sort(penn.begin() , penn.end() );
                sum-=penn[0];
                if(sum>=s ){
                    continue;
                }else{
                    res = max(res, (int)penn.size());
                }
            }

        }


        cout << res <<el;
    }
    return 0;
}

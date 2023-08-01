#include<bits/stdc++.h>

using namespace std;
#define el '\n'
#define ll long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

double EPS = 1e-9;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    bool f1 =0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] % 5 == 0 ){
            f1=1;
            v[i] = v[i] + v[i]%10;
        }
    }
    if(f1){
        cout <<(( *min_element(all(v)) == *max_element(all(v)))?"YES":"NO") << el;
    }else {
        for (int i = 0; i <n ; ++i) {
            if(v[i]%2 != 2 ){
                while(v[i]%10 != 2 ){
                    v[i] = v[i] + v[i]%10; // maximum 3 cylces
                }
            }
        }
        int ref = *max_element(all(v));
        bool f2=1 ;
        for (int i = 0; i <n && f2  ; ++i) {
            if( (ref - v[i])%20 != 0 ){
                f2 =0;
            }
        }
        cout << (f2?"YES":"NO" ) << el;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    cerr << "TIME TAKEN: " << (float) clock() / CLOCKS_PER_SEC << setprecision(6) << " Secs" << endl;
    return 0;
}
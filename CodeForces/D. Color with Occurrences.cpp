#include<bits/stdc++.h>

using namespace std;
#define el '\n'
#define ll long long
#define f first
#define s second
#define len(s) (int)s.size()
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < int(n); i++)
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
bool check(int start  , int last , string& s  , vector<string> & strs, vector<pair<int ,int>> & AnsPairs ){
    int idx = -1 , pos = -1 , finalpos = 0 ;
    for (int i = start ; i <=last ; ++i) {
        for (int j = 0; j <len(strs) ; ++j) {
            string z = strs[j];
            if(z == s.substr(i, len(z)) && (i+len(z))>finalpos ){
                pos =i ;
                idx= j ;
                finalpos=i + len(z);
            }
        }
    }

    if(idx == -1){
        return false ;
    }else{
        AnsPairs.push_back({idx +1 , pos+1});
        if(finalpos == len(s)){
            return true;
        }else{
            return (check(pos+1 ,finalpos,s, strs , AnsPairs ));
        }
    }
}

void solve() {
    string s; cin >> s;
    int t; cin >> t;
    vector<string> strs ;
    vector<pair<int, int >>AnsPairs ;
    forn(i,t ){
        string z ;cin>> z ;
        strs.push_back(z);
    }

    bool valid = check(0, 0 ,s ,strs, AnsPairs );
    if(!valid ){
        cout << -1 << el;
    }else{
        cout << len(AnsPairs) << el;
        for(auto i : AnsPairs){
            cout << i.f << " " << i.s << el;
        }
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
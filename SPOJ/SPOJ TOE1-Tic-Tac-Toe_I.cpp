// Just Keep it up, long way to go.
#include<bits/stdc++.h>
using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long long double
#define el endl
#define re return
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define f first
#define s second
#define len(z) (int)z.size()
#define pb push_back
#define eb emplace_back
#define popcnt(a) __builtin_popcount(a)
#define all(a) a.begin(),a.end()
// Debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " :" << x << endl;
#define debugv(v) cerr << #v << endl;  for(auto & i : v ) cerr << i << " " ; cerr << endl;
#define ShowTime cerr << "Code Takes  : " << (float) clock() / CLOCKS_PER_SEC << setprecision(7) <<  fixed << " Secs to run." << endl;
#else
#define debug(x)
#define debugv(v)
#define ShowTime
#endif
// constants
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int N = 1e6 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }

bool check_win( string s){
    // ...   0 1 2
    // ...  3 4 5
    // ...  6 7 8
    // rows -- columns -- diagonals
     // rows
     if(s[0]  != '.' &&(s[0] == s[1] && s[1] == s[2])
     || s[3]  != '.' &&(s[3] == s[4] && s[4] == s[5])
     || s[6]  != '.' &&(s[6] == s[7] && s[7] == s[8]))
         return true ;
     // columns;
    if(s[0]  != '.' &&(s[0] == s[3] && s[3] == s[6])
       || s[1]  != '.' &&(s[1] == s[4] && s[4] == s[7])
       || s[2]  != '.' &&(s[2] == s[5] && s[5] == s[8]))
        return true;
     // diagonals
    if(s[0]  != '.' &&(s[0] == s[4] && s[4] == s[8])
       || s[2]  != '.' &&(s[2] == s[4] && s[4] == s[6]))
        return true ;
    return false ;
}
string BFS(string start , string board ){
    string ans = "no";
    queue<pair<string , bool > > q;
    q.push({start , 1 });
    while(!q.empty()) {
        bool cur_player = q.front().s ;
        string cur_board =  q.front().f;
        q.pop();
        if(cur_board == board ){ans = "yes"; break; }
        if(check_win(cur_board)){
            continue;
        }
        for (int i = 0; i <9 ; ++i) {
            if(cur_board[i] == '.'){
                cur_board[i] = cur_player ? 'X':'O';
                if(cur_board[i] == board[i]){
                    q.push({cur_board, !cur_player}) ;
                }
                cur_board[i] = '.';
            }
        }
    }
    return ans;
}
void EZ(){
    string board  = "";
    for(int i =0 ; i <3  ; i++){
            string z ; cin>> z;
            board+=z;
    }
    string start = "........." ;
    cout<< BFS(start, board) << el;
}


int main() {

    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("Error", "w", stderr);
#endif

    int tc =1 ;
     cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}



// Just Keep it up, long way to go.
#include<bits/stdc++.h>
using namespace std;
// Macros
#define RunIt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long double
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
#define allr(a) a.rbegin(),a.rend()
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
const int N = 5e2 + 4 ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
int n, m  ,k  , rem   =0 , sx ,sy ;
char matrix[N][N];
bool vis[N][N];
int dx[] = {0 , 0, 1 ,-1 };
int dy[] = {1 , -1, 0 ,0 };
bool valid(int x , int y ) {
    re(x>0 && y >0 && y<=m && x<=n && !vis[x][y] && matrix[x][y] == '.');
}
void bfs() {
    queue<pair<int ,int >> q;
    q.push({sx , sy });
    rem--;
    while(q.size()){
        int x = q.front().f , y =q.front().s ;
        vis[x][y] =1;
        q.pop();
        for(int i =0 ;i < 4 ;i++) {
            int nx = x + dx[i] , ny = y + dy[i];
            if(valid(nx ,ny) and rem ){
                rem--;
                vis[nx][ny] = 1;
                q.push({nx , ny });
            }
        }
    }
}
void EZ(){
    cin >> n >> m >> k ;
    for(int i = 1 ; i<=n ; i++) {
        for(int j =1 ;j <= m ;j++){
            cin >> matrix[i][j] ;
            if(matrix[i][j] == '.') sx =i , sy= j, rem++;
        }
    }
    rem-=k;
    bfs();
    for(int i =1 ;i <=n ; i++) {
        for(int j =1 ; j <=m ;j++){
            if(!vis[i][j] && matrix[i][j] == '.'){
                matrix[i][j] = 'X';
            }
        }
    }
    for(int i =1 ;i <=n ; i++) {
        for(int j =1 ; j <=m ;j++){
            cout << matrix[i][j] ;
        }
        cout << endl;
    }
}


int main() {

    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error", "w", stderr);
#endif

    int tc =1 ;
    //cin >> tc;
    while(tc--){
        EZ();
    }

    ShowTime
    return 0 ;
}



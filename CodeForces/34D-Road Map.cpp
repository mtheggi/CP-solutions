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
//const int MOD = 1e9+7;
const double EPS = 1e-9;
const int N = 1e5  ;
// used Funcions
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
vector<int> graph[N];
vector<int> ans(N);
bool vis[N];
void dfs(int  start ) {
 
     vis[start] =1 ;
    for(auto i : graph[start])
        if(!vis[i]){
            cerr << i << endl;
            ans[i] = start ;
            dfs(i);
        }
 
    return ;
}
void EZ(){
    int n , r1 ,r2 ;
    cin >> n >> r1 >> r2 ;
    for(int i =1 ; i <= n  ;i++){
        if(i == r1) continue;
        int a; cin >> a;
        graph[i].pb(a);
        graph[a].pb(i);
 
    }
    //vis[r2] =1 ;
    dfs(r2);
    for(int i = 1; i <=n ;i++ )
    {
        if(i == r2 ) continue;
        cout <<  ans[i] << " " ;
    }
}
int main() {
    RunIt;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    // freopen("Error","w",stderr);
#endif
    int tc =1 ;
    // cin >> tc;
    for(int i =1 ; i <=tc ; i++) EZ();
    ShowTime
    return 0 ;
}
 
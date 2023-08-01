#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define ld long double
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 3e5+10 , M = 5050, inf = 1e9, mod = 998244353;

int sp[N][25], lvl[N];
vector < int > g[N];
// sp[i][0] = a[i]
void dfs( int node, int par)
{
    lvl[node] = lvl[par] + 1;
    sp[node][0] = par;

    for ( int j = 1 ; j < 20 ; j++)
        sp[node][j] = sp[sp[node][j-1]][j-1];

    for(auto ch : g[node])
    {
        if(ch == par)
            continue;
        dfs(ch,node);
    }
}


// O(log)
// return Kth ancestor of the node u
// binary lifting
int getKthAnscetor( int u , int k )
{
    for ( int i = 20 ; i >= 0 ; i--)
    {
        if((1<<i) <= k)
        {
            u = sp[u][i];
            k -= (1<<i);
        }
    }
    return u;
}

// return the lowest common ancestor between node u and v
int getLCA( int u , int v)
{
    if(lvl[u] < lvl[v])
        swap(u,v);
    int diff = lvl[u] - lvl[v];
    u = getKthAnscetor(u,diff);
    if ( u == v)
        return u;
    for ( int i = 20 ; i >= 0;  i--)
    {
        // respond F
        if(sp[u][i] != sp[v][i])
        {
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    // move one step
    assert(sp[v][0] == sp[u][0]);
    return sp[v][0];
}
int n;
void testCase() {
    cin >> n;
    for ( int i = 1 ; i < n;  i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(lvl[a] < lvl[b])
            cout << "NO\n";
        else
            cout << "YES " << getLCA(a,b) << '\n';
    }
}

int32_t main()
{
    Tsetso
    int tc = 1;
//    cin >> tc;
    while(tc--)
        testCase();
}

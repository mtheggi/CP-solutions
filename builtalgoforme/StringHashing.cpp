#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define ld long double
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 4e6+10, mod = 1e9+7, inf = 2e9, sqr = 640, base = 31;

// returns hash value of string str

int pw[N], inv[N];

int add( int a , int b)
{
    return (0ll + a + mod + b) %mod;
}

int mul ( int a , int b)
{
    return 1LL * a * b %mod;
}

int fastpow( int b , int p)
{
    if(!p)
        return 1;
    int temp = fastpow(b , p >> 1);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}

void pre()
{
    pw[0] = 1, inv[0] = 1;
    for ( int i = 1 ; i < N ; i++)
    {
        pw[i] = mul(base,pw[i-1]);
        inv[i] = fastpow(pw[i],mod-2);
    }
}

int pref[N];
void generateHash( string &str)
{
    for ( int i = 0 ; i < str.size() ; i++)
    {
        int idx = str[i] - 'a' + 1;
        pref[i] = mul(idx , pw[i]);
        if(i)
            pref[i] = add(pref[i],pref[i-1]);
    }
}
int getHash( int l , int r)
{
    int ret = pref[r];
    if(l)
        ret = add(ret , - pref[l-1]);
    ret = mul(ret, inv[l]);
    return ret;
}
void testCase() {


}

int32_t main()
{
    pre();
    Tsetso
    int tc = 1;
//    cin >> tc;
    while(tc--)
        testCase();
}

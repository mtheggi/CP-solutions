#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)  

using namespace std;
#define ll  long long
void GCDs(set<ll> & st , ll g){
    for (ll i = 1; i*i <= g; ++i)
    {
        if(g %i ==0 ){
            st.insert(i);
            st.insert(g/i); 
        }
    }
}
int main()
{
    fastio;
    int a, b ;
    cin >>a >> b;
    ll g = gcd(a,b);
    set<ll> GCD;  
    GCDs(GCD , g);
    int t ; 
    cin >> t ;
    while(t--){
        int l,r;  
        cin >> l >> r; 
        ll ans= 0; 
        for(auto it :GCD){
            if(it <=r && it >= l )  
                ans = it ;
        }
        ans = ans==0? -1 : ans ; 
        cout << ans << endl; 
        
    }
    return 0 ; 
}

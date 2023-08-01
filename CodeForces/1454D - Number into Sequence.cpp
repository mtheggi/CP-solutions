#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
const int N = 3e4;
int main()
{
    int t ;
    cin >> t ; 
    while(t--){
        ll n; 
        cin >> n ; 
        ll s = n ; 
        vector<ll> v ;
        for (ll i = 2; i*i <=n ; ++i)
        {
            if(n%i==0){
                vector<ll> temp ;
                while(n%i == 0 ){
                    n/=i;
                    temp.push_back(i) ;
                }
                if(v.size() < temp.size() ){
                    v =temp ;
                }
            }

        }
        if(v.empty() ){
            cout << 1 << el  << s <<el; 
        }else{
            cout << v.size() <<el; 
            for (ll i = 0; i < v.size()-1; ++i)
            {
                cout << v[i]  << " ";
                s/=v[i];
            }
            cout << s <<endl; 
           

        }


    }    
    return 0;
}

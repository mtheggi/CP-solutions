#include <bits/stdc++.h>
#define el "\n"

#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif

    priority_queue<ll, vector<ll>, greater<ll>>pq  ;
    ll n  ;
    cin >> n;
    ll sum =  0; // 
    ll count = 0;  
    for (int i = 0; i < n; i++)
    {
        int x ;
        cin >>x ;
        sum+= x;
        count++ ; 
        pq.push(x);
        while(sum<0){
            sum = sum - pq.top() ;
            pq.pop() ;
            count-- ;
        } 
    }
    
    cout << count << endl;


    return 0;
}

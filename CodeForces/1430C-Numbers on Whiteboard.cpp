#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long 


int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    int t ;
    cin >>t ;

    while(t--){
        priority_queue<int>v ;
        int n ;
        cin>>n;
        for (int i = 0; i <n; i++)
        {
            v.push(i+1);
            
        }
        
       
        cout <<2 <<endl; 
        while(v.size()>1){
            int s1 = v.top();
            cout << s1 << " ";
            v.pop(); 
            int s2 = v.top();
            v.pop(); 
            cout << s2 <<endl;
            int avg = (s1+s2+1)/2;
            v.push(avg);
        }
    }
  
}
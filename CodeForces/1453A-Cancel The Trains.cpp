#include <bits/stdc++.h>
#define el "\n"
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

        int n ;
        cin >> n ;
        while (n--){
            int t ,x,z;
            set<int>set;
            cin >> x >> z ;
            t = x+z;
            for(int i=0 ; i< x ; i++ ){
                int s ;
                cin >>s ;
                set.insert(s);
            }
            for(int i=0 ; i< z ; i++ ){
                int s ;
                cin >>s ;
                set.insert(s);
            }
            

            cout << t - set.size() << endl;  
        
        }


    return 0;
}

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

        int t ;
        cin >> t ;
        while(t--){
            bool flage = true ;
            int n ,d ;cin >> n>>d ;
            vector<int> v(n) ;
            for (int i = 0; i < n; i++)
            {
                cin >> v[i] ;
                if(v[i] > d){
                    flage = false;
                }
            }
            if(flage){
                cout << "YES" <<endl; 
            }else {
                bool flage2 =false ;
                sort(v.begin(),v.end());
                for (int i = 0; i < n-1; i++)
                {
                    if(v[i] + v[i+1]  <= d ){
                            flage2 =true;
                            break; 
                    }
                }
                if(flage2){
                    cout << "YES" <<endl; 
                }else {
                    cout << "NO" <<endl; 
                }

            }



        }


    return 0;
}


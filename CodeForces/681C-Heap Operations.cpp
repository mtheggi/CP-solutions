#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
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
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<string> v;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {   int z ;
            cin >>z ;
            pq.push(z);
            v.push_back("insert " +to_string(z));
        }
        else if (s == "getMin")
        {   
            int z ;
            cin >>z ;
            if(pq.size() == 0){
                pq.push(z) ;
                v.push_back("insert " + to_string(z));
                v.push_back("getMin " + to_string(z)) ;
            }else if( z < pq.top()){
                pq.push(z) ;
                v.push_back("insert " + to_string(z));
                v.push_back("getMin " + to_string(z)) ; 
            }else if( z >=pq.top()){
                while(pq.size() && z > pq.top()){
                    v.push_back("removeMin") ;
                    pq.pop();
                } 
                if(pq.size() && z == pq.top()){
                    v.push_back("getMin " + to_string(z)) ;
                }else{
                    pq.push(z) ; 
                    v.push_back("insert " + to_string(z));
                    v.push_back("getMin " + to_string(z)) ;
                }
            }
            

        }else{
            if(!pq.empty()){
                v.push_back("removeMin") ;
                pq.pop() ;
            }else{
                v.push_back("insert 1") ;
                v.push_back("removeMin") ; 
            }

        }
    }
    cout << v.size() << endl; 
    for(auto i : v ){cout << i <<endl;}


    return 0;
}

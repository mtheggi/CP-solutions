#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<utility>



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
    set<int> s ;
    multiset<int >sm ;
    int count = 6; 
    for (size_t i = 0; i < count; i++)
    {
        int a ;
        cin >>a ;
        s.insert(a);
    }
    bool z = s.count(100) ;// return boolean`
    string s2 = (z) ? "YES" : "NO";
    cout << s2 << endl  ;

    auto lower = s.lower_bound(5) ;// return iterator   الخمسة اول رقم اكبر من او يساوى  o(log(n))
    for(int i : s ){
        cout << i << ' ' << '\n' << endl;    
    }
    cout << "===================================" << endl; 
    auto it = s.begin(); 
    cout << *(it++) << endl; 
    s.erase(4) ;
    
    for(int i : s ){
        cout << i << ' ' << '\n' << endl;    
    }

    auto its = s.find(3) ;
    
    cout << *its << endl; 
    cout << *next(its) << endl; 
    cout << *prev(its)<< endl; 

    // 2y 7aga fel set o(log(N))
    map<string , int > score  ;
    score["Ahmed "] = 23 ; score["samir"] = 232 ;
    
    score["Ahmed"] = 40 ; //you can  overwrite it  
    cout << score["samir"] << endl; 
    
    return 0;
}

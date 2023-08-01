#include <bits/stdc++.h>


#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
bool greaterthanthree(int n){

    return n>3 ;
}

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input", "rt", stdin);
    #endif
    #ifndef ONLINE_JUDGE
        freopen("output", "wt", stdout);
    #endif

    vector<int> v ;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++  ) {
        cout << *it << " "; //
    }
    cout << endl; 
    
    vector<int>::iterator it = v.end();
    cout << *(v.end()-1);
    cout << endl; 
    for(auto it : v){
        cout << it << endl;
    }

    vector<int>::reverse_iterator rit = v.rbegin();
    cout << *rit << endl ; 
    
    vector<int>s = {1,2,100,2,1,2,-2};
    cout << *min_element(s.begin(),s.end()) << endl;  // = > return address 

    cout << *max_element(s.begin(),s.end()) << endl;
    cout << *minmax_element(s.begin(),s.end()).first << " "  << *minmax_element(s.begin(),s.end()).second << endl;
    auto p =  minmax_element(s.begin(), s.end());
    
    
    cout << *p.first <<endl;  
    cout << *p.second << endl; 


    vector<int>x = {0,1,2,3,4,5,6,7,10};
    sort(x.begin(),x.end());
    auto it2= find_if(x.begin(),x.end(),greaterthanthree);

    for(;it2!=x.end();it2++ ){
        cout << *it2 << endl;
    }
   
   int arr [] = {60,60,60,60,60,120};
   vector<int>n(6);
   copy(arr, arr+6 , n.begin());
   for(auto it : n){
       cout << it << endl; 
   }
   cout << " =================================" << endl; 
   copy(n.begin(),n.end(), ostream_iterator<int>(cout," "));
    cout << endl<<" =================================" << endl; 
    
    return 0;
}

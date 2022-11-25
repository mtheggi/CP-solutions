#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
map<char ,int> mp ;
void Generate() {
    mp['a'] =1;
    char a = 'a';
    for (int i = 2; i <=26 ; ++i) {
        a++;
        mp[a] = i ;
    }
}
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    Generate();
    int t ;cin >> t ;
    while(t--){
        string s; cin >>s;
        map<char , int>freq;
        map<char ,vector<int>>ind ;
        int p ; cin >>p;
        int current =0 ;
        for (int i = 0; i <s.size() ; ++i) {
            current+=mp[s[i]];
            freq[s[i]]++;
            ind[s[i]].push_back(i);
        }
         // cout << current <<el;
        if(current<=p){
            cout << s << el;
            continue;
        }
        char x ='z';
        for (int i = 26; i >=1 ; i--) {
            if(freq[x]!= 0){
                current-=mp[x];
                    s[ind[x][ind[x].size()-1]]= '!';
                    ind[x].pop_back();
                if(current <= p ){
                    break;
                }
                freq[x]--;
                if(freq[x]!= 0 ){
                    x++;
                    i++;
                }
            }
            x--;
        }
        for( int i   =0 ; i< s.size() ; i++){
            if(s[i]!='!'){
                cout<<s[i];
            }
        }
        cout <<el;
    }
    return 0 ;
}

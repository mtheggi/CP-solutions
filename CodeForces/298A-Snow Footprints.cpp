#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int n ;
    // cin >> n ;
    // string x ;
    // set<char> z;
    // cin >>x ;
    // int  s,t;
    // for (int i = 0; i < n; i++)
    // {
    //     if(x[i] != '.' ){
    //     z.insert(x[i]);
    //     }
    // }
    // bool flage = true ;
    // bool flage2 = true ;
    // bool flage3 = true ;
    // if(z.size() == 1 && *z.begin() == 'R'){
    //     for (int i = 0; i < n; i++){
    //         if(x[i] == 'R'){
    //             t = i ;
    //         }
    //         if (x[i] == 'R' && flage){
    //             s=i;
    //             flage = false ;
    //         }
    //     }
    //     t= t+2 ;
    //     s= s+1 ;
    // }else if (z.size() == 1 && *z.begin() == 'L'){
    //      for (int j = 0; j < n; j++){
    //         if(x[j] == 'L'){
    //             s = j ;
    //         }
    //         if (x[j] == 'L' && flage2){
    //             t=j;
    //             flage2 = false ;
    //         }
    //     }
    //     s=s+1 ;
    // }else if (z.size() == 2  ){
    //     for (int k = 0; k < n; k++){
    //         if(x[k] == 'R'){
    //             t = k ;
    //         }
    //         if (x[k] == 'R' && flage3 ){
    //             s=k;
    //             flage3 = false ;
    //         }
    //     }
    //     s=s+1;
    //     t=t+1;

    // }

    // cout << s  << " " << t ;
    //* ********************much  cleaner **************************************
    int fst, lst;
    int t;
    cin >> t;
    string s;
    cin >> s;
    for (int i = 0; i < t; ++i)// detect first 
    {
        if (s[i] != '.')
        {
            fst = i;
            break;
        }
    }
    for (int i = t - 1; i > 0; --i) // find last 
    {
        if (s[i] != '.')
        {
            lst = i;
            break;
        }
    }
    if (s[fst] == 'R' && s[lst] == 'R')
        cout << fst + 1 << " " << lst + 2;
    else if (s[fst] == 'L' && s[lst] == 'L')
        cout << lst + 1 << " " << fst;
    else if (s[fst] == 'R' && s[lst] == 'L')
    {
        for (int i = 0; i < t; ++i)
        {
            if (s[i] == 'L')
            {
                lst = i;
                break;
            }
        }
        cout << fst + 1 << " " << lst-1+1;
    }
}
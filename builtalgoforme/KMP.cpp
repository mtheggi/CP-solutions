#include<bits/stdc++.h>
using namespace std;
/*
 * vector KMP(string ) {} --> return vector<int> on  the same size of the string ;;
 *  longest prober  suffix is also prefix of the string
 *  if at some pos there is x -- > last x charachter is the same of the first x charachters
 * */

// if done with naive approach O(n^3 );
vector<int> KMPNaive(string str ){
    vector<int> fails(str.size() +2  , 0 ) ;
    for(int i =1 ; i < str.size() ;i++) {
        for(int  j= i ;  j < str.size() ; j++) {
            string suffix = str.substr(i , j-i+1 ) ;
            string prefix = str.substr(0, j-i+1 );
            if(suffix == prefix )
                fails[j]= max(fails[j], j-i+1)  ;
        }
    }
    return fails ;
}
/* examples  :
 *  1- abcdabcdabcd
 *     000012345678
 *  2- abcdab dabcdab C
 *     000012 012345     3
 *  Observation to turn O(n^3)  -> O(n) ;
 *  1- you can not increment by more than one , but you can decrement by variable number(see example 2 ).
 *
 * */
vector<int> KMP_PrefixFunction(string str ){ // O(n)
    vector<int> Fails (str.size(),0 );
    for(int i =1 ; i < str.size() ;i++) {
        int j = Fails[i-1];
        while(j>0 && str[i] != str[j])
            j= Fails[j-1];
        if(str[i] == str[j])
            Fails[i] = j+1 ;
        else Fails[i] =0;
    }
    return Fails ;
}

int main() {
   string str ; cin >> str ;  
   vector<int> kmp = KMP_PrefixFunction(str); 
 }
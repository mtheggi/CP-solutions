#include<iostream>
#include<string>
using namespace std ;
int main(){
    string s,z  ; 
    cin >> s >>z ;
    if (s ==z ) 
         cout << -1 <<endl; 
    else if (s.length() > z.length())
        cout << s.length() <<endl; 
    else 
        cout << z.length() <<endl; 
         
}
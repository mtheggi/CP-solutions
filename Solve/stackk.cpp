#include<iostream>
using namespace std;

int factorial(int n ){
    // base case
    if(!n) return 1 ;
    // transition
    return n * factorial(n-1);
}


int main(){
cout << factorial(10) << endl;

}
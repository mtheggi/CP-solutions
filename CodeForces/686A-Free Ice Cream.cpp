#include <iostream>
#include <string>
using namespace std;
int main(){
  __int64 n,x,d;
    cin >> n >> x ;
    int sad = 0;
    char c ;
    while(n--){
        cin >> c >>d ;
        if(c == '+')
            x+=d;
        else if(d <=x )
            x-=d ;
        else if (d>x)
            sad++;

    }
cout << x <<' '<< sad<< endl;
}
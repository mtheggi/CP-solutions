#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    unsigned long long int  n;
    long long int  sum;
    unsigned long long int  z;
    while (t--)
    {
        
        cin >> n >> sum;
        z = n*n ;
        int c ;
        c =sum /z ;
        if(c <= (n+1)){            
            cout << c << endl;
        }else{
            cout << c - (n+1 -c)<< endl;
        }

    }
}

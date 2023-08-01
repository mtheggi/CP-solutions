#include<bits/stdc++.h>

using namespace std;
int const N = 1e9 +7  ;
int const H = 1e3 + 2 ;
#define ll long long
#define f first
#define s second
char mat[H][H];
int dp[H][H];
int h , w ;
bool checkinborder(int i , int j ) {return (i>=0  && i <h && j>=0 &&  j<w ) ; }

int getNumOfPath(int i , int j ){
    if(!checkinborder(i, j )) return 0 ;
    if(i+1 == h && j+1 == w ) return 1;

    int &ret = dp[i][j] ;
    if(~ret ) return ret;

    int a =0 ;
    if(mat[i+1][j] != '#')
        a  = getNumOfPath(i+1,j)%N;
    if(mat[i][j+1] != '#')
        a =( a%N + getNumOfPath(i , j+1)%N )%N  ;

    return ret =  a  ;
}



int main() {
 cin >> h >> w ;
    memset(mat,'#', sizeof mat);
    memset(dp , -1 , sizeof dp );
    for(int i =0 ;i < h  ; i++) {
        for(int j =0  ; j < w ; j++) {
            cin >> mat[i][j] ;
        }
    }

    cout << getNumOfPath(0, 0 )  << endl;

    return 0;
}
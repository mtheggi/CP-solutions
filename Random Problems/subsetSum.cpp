// Backtracking 
/*
! U R given some some elements and a target sum . U goal to is to print all subsets that sum up to the target Sum. 
input Example : 
5 6
1 5 2 7 3
output Example :
1 5
1 2 3
*/ 
// states : sum(indx)
// transition : sum(indx +1)
// base case : sum == targert sum  , indx >= n  
#include<iostream>
#include<string> 
#include<vector> 
using namespace std; 
int n, target ; 

vector<int> Msum;
vector<int> v; 
void sumsubset(int indx, int sum){

    if(indx == n) {
        if(sum == target)
        {
            
            for(auto j: Msum){
                cout  << j << " "; 
            }
            cout << endl; 
        }
        return ; 
    }
    
    Msum.push_back(v[indx]);
    sumsubset(indx+1 , sum + v[indx]); 
    Msum.pop_back();
    sumsubset(indx+1 ,sum);

}
int main(){

     #ifndef ONLINE_JUDGE
        freopen("input", "rt", stdin);
    #endif
    #ifndef ONLINE_JUDGE
        freopen("output", "wt", stdout);
    #endif

    
    cin >> n >> target ; 
    for (int i = 0; i < n; i++)
    {
         int a; 
         cin >>a ;
         v.push_back(a); 
    }
    sumsubset(0,0);
    return 0 ; 
}


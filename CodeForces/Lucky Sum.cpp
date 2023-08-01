#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
vector<ll>luckies ;
void Generate(ll val){
	if(val> 0 ){
		luckies.push_back(val);
	}
	if(val>1e9){
		return ;
	}
	Generate(val*10+4);
	Generate(val*10+7);

}

int main()
{
    fastio;    	 
    	Generate(0) ;
    	sort(luckies.begin(),luckies.end());
    	int l ,r ; cin >> l >> r ;
    	 	 ll sum = 0 ;
    	 	 ll j =0 ;  
	    	for (int i = l; i <=r ; ++i)
	    	{
	    			if(luckies[j]>=i){
	    				sum+=luckies[j];
	    			}else{
	    				j++;
	    				i--;
	    			}						
	    	}	

	    	cout << sum <<el; 



    return 0;
}

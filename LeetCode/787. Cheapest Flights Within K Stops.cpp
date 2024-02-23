#define ll long long 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<ll> dist(n+2 , 1e10);
        vector<ll> dist2(n+2 , 1e10);
        dist[src]  =0;
        dist2[src] =0; 

        for(int i =0 ; i <= k ; i++) {
            for(int j=0 ; j <flights.size() ; j++) {
                int s = flights[j][0] , d =flights[j][1] , cost = flights[j][2];   
                if(dist[s] + cost < dist2[d] ) {
                    dist2[d] = dist[s] + cost;
                }
            }
            dist=dist2; 
        }
        return dist[dst]==1e10 ? -1 :dist[dst];

    }
};

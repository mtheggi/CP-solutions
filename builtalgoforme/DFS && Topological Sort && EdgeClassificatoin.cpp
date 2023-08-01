#include<bits/stdc++.h>
using namespace std;
int const N = 1e4 ;
// O(V+E);
vector<int> topsort; // for Topological Sort  
int timer =0 ; 
int start[N] , finish[N];  
map<pair<int ,int > , char > edgesClass ; 
bool cycle =0 ; 
void DFS(int node, vector<bool> & visited , vector<vector<int>> & graph )
{
	visited[node] = true;
    for(auto child  : graph[node])
	{
		if (!visited[child])	
			DFS(child, visited , graph );
	}

	topsort.push_back(node);	//  reverse when used 
}

void EdgeClassification(int src , vector<vector<int>> &graph){
    timer++; 
    start[src]= timer ; 
    for(auto child : graph[src]){
        if(start[child] == -1 ) {
            EdgeClassification(child , graph ); 
        }else {
            if(finish[child] == -1 ){
                edgesClass[{src, child}] = 'B' ;// backword;  
                cycle = 1; 
            }else {
                if(start[child] > start[src]) {
                    edgesClass[{src, child}] = 'F'; 
                }else 
                    edgesClass[{src, child}] = 'C'; 
            }
        }
    }

    timer++; 
    finish[src]  = timer; 
}

int main() {
    int nodes ,edges ;
    cin >> nodes >>  edges ;
    vector<vector<int>> graph(nodes+2);
    for(int i =0 ;i < edges ; i++){
        int u ,v ;
        cin >> u >> v;
        graph[u].push_back(v) ;
        graph[v].push_back(u); // if undirected ;
    }
    vector<bool> visited(nodes +2, 0 );
    topsort.clear(); 
    DFS(nodes, visited , graph ) ;     
    memset(start, -1 , sizeof start); 
    memset(finish, -1 , sizeof start); 
    for(int i =1;i <= nodes ; i++ ) {
        if(start[i] == -1 ){
            EdgeClassification(i ,graph); 
        }
    }
    return 0;
}
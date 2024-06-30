class Solution {
    int size;
    int component;
    int *sz;
    int *parent;
public:
    void construct(int size_ ) {
        size = size_; 
        component=size_; 
        sz = new int[size_]; 
        parent = new int[size_]; 
        for (int i = 0; i < size_; i++) {
            sz[i] = 1;
            parent[i] = i;
        }
    }
    int Find(int a){
        if (parent[a] == a) return a;
        int root = a;
        while (root != parent[root]) {
            root = parent[root];
        }
        while (a != root) {
            int temp = parent[a];
            parent[a] = root;
            a = temp;
        }
        return root; 
    }
    int getcomponent() { return component; }
    bool connected(int a, int p) { return (Find(a) == Find(p)); }
    void unify(int a, int b) { // unify by size 
       int root_a = Find(a);
       int root_b = Find(b);
       if (root_a == root_b) return; // cycles --> they are connected 
       if (sz[root_a] < sz[root_b]) swap(root_a, root_b);
       parent[root_b] = root_a;
       sz[root_a] += sz[root_b];
       component--;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {        
        construct(n); 
        int ans =0 ; 
        map<pair<int,int>, vector<int>> newEdges;  
        for(auto edge : edges ) newEdges[make_pair(min(edge[1],edge[2])  , max(edge[1],edge[2]) )].push_back(edge[0]); 
        for(auto  &edge: newEdges) {
            if(find(edge.second.begin() , edge.second.end() , 3) != edge.second.end()){
                ans+=(edge.second.size()-1);
                edge.second = { 3 }; 
            }
        }
        // alice 
        for(auto edge : newEdges) {
            if(find(edge.second.begin() , edge.second.end() , 3) != edge.second.end()){
                if(connected( edge.first.first -1 , edge.first.second-1 )){
                    ans++; 
                }else{
                    unify( edge.first.first -1 , edge.first.second-1 ); 
                }
            } 
        }
        for(auto edge : newEdges) {
            if(find(edge.second.begin() , edge.second.end() , 1) != edge.second.end()){
                if(connected( edge.first.first -1 , edge.first.second-1 )){
                    ans++; 
                }else{
                    unify( edge.first.first -1 , edge.first.second-1 ); 
                }

            }
        }
        if(getcomponent() != 1 ) return -1 ; 
        construct(n); 
        // bob 
        for(auto edge : newEdges) {
            if(find(edge.second.begin() , edge.second.end() , 3) != edge.second.end()){
                if(!connected( edge.first.first -1 , edge.first.second-1 )){
                    unify( edge.first.first -1 , edge.first.second-1 ); 
                }
            } 
        }
        for(auto edge : newEdges) {
            if(find(edge.second.begin() , edge.second.end() , 2) != edge.second.end()){
                if(connected( edge.first.first -1 , edge.first.second-1  )){
                    ans++; 
                }else{
                    unify( edge.first.first -1 , edge.first.second-1 ); 
                }
            }
        }
        if(getcomponent() != 1 ) return -1 ; 
    
        return ans;
    }

    ~Solution(){
        delete[] sz;
        delete[] parent;
    }
};

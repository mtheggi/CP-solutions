class Solution {
private : 
    int size  , component; 
    int * sz  ; int * parent;  
public:
    void _init(int n ) {
        size = n ;  
        component = n; 
        sz = new int[n+1]; 
        parent = new int[n+1]; 
        for(int i =0 ;i < n ; i++) {
            sz[i]= 1; 
            parent[i] =i ; 
        } 
    }
    int Find(int a) {
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
    void unify(int a, int b) {
        int root_a = Find(a);
        int root_b = Find(b);
        if (root_a == root_b) return;
        if (sz[root_a] < sz[root_b]) swap(root_a, root_b);
        parent[root_b] = root_a;
        sz[root_a] += sz[root_b];
        component--;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        _init(nums.size()); 
        map<int , set<int>> factors ;         
        for(int i =0 ;i < nums.size() ; i++) {
            map<int, bool> primes ;
            int n = nums[i];  
            for(int j =2 ; j*j <=n ; j++){
                while(n%j ==0 ) {
                    n/=j; 
                    factors[j].insert(i); 
                }
            }
             if (n > 1)
                factors[n].insert(i);
        }
        for(auto [factor , indxs] : factors) {
            int root = *indxs.begin(); 
            for(auto indx : indxs ) {
                int finsd = Find(indx);
                unify(root , indx ); 
            }
            cout <<endl ;
        }

        if(component ==1  ) return true; else return false; 
  }
    ~Solution() {
        delete[] sz ; 
        delete[] parent; 
    }
};

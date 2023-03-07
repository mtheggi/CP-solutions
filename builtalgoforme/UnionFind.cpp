#include<bits/stdc++.h>
using namespace std ;
class unionfind {
private  :
    int size;
    int component;
    int *sz;
    int *parent;
public :
    unionfind(int _size) : size(_size), component(_size) {
        sz = new int[_size];
        parent = new int[_size];
        for (int i = 0; i < _size; i++) {
            sz[i] = 1;
            parent[i] = i;
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
        return root; // another way of doing that recursively ---> return parent[a] = Find(parent[a]); [can cause memory overhead];
    }
    int componentSize(int p) { return sz[Find(p)]; }
    bool connected(int a, int p) { return (Find(a) == Find(p)); }
    int getcomponent() { return component; }
    void unify(int a, int b) {
        int root_a = Find(a);
        int root_b = Find(b);
        if (root_a == root_b) return;
        if (sz[root_a] < sz[root_b]) swap(root_a, root_b);
        parent[root_b] = root_a;
        sz[root_a] += sz[root_b];
        component--;
    }
  ~unionfind() {
        delete[] sz;
        delete[] parent;
    }
};

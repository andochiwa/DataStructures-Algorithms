#include<bits/stdc++.h>
using namespace std;
// template
class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind() {}

    UnionFind(int m)
    {
        parent.resize(m);
        for(int i = 0; i < m; i++) parent[i] = i;
    }

    int find(int index) {
        while(index != parent[index])
        {
            parent[index] = parent[parent[index]];
            index = parent[index];
        }
        return index;
    }

    void unite(int index1, int index2) {
        parent[find(index1)] = find(index2);
    }
};

int main()
{
    int m;
    cin >> m;
    UnionFind DSU = UnionFind(m);
    return 0;
}
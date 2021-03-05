#include<bits/stdc++.h>
using namespace std;

bool topsort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> edge(n);
    vector<int> inedge(n);
    for(auto& g : graph)
    {
        edge[g[0]].push_back(g[1]);
        inedge[g[1]]++;
    }

    queue<int> myque;
    for(int i = 0; i < n; i++)
    {
        if(inedge[i] == 0) myque.push(i);
    }

    int count = 0;
    while(!myque.empty())
    {
        auto temp = myque.front();
        myque.pop();
        count++;
        for(auto i : edge[temp])
        {
            inedge[i]--;
            if(inedge[i] == 0) myque.push(i);
        }
    }
    return count == n;
}

int main()
{
    int n;
    cout << "input size" << endl;
    cin >> n;
    cout << "input graph" << endl;
    vector<vector<int>> graph;
    for(int k = 0; k < n; k++)
    {
        int i, j;
        cin >> i >> j;
        graph.emplace_back(i, j);
    }
    if(topsort(graph) == true) cout << "graphs have not ring";
    else cout << "graphs have ring";
    return 0;
}
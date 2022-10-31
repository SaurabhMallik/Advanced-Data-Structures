#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    for (int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int src;
    cin>>src;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INF);
    pq.push({0,src});
    dist[src]=0;
    while (!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        for (pair<int,int> t: g[p.second])
        {
            if (dist[t.first]>dist[p.second]+t.second)
            {
                dist[t.first]=dist[p.second]+t.second;
                pq.push({dist[t.first],t.first});
            }
        }
    }
    cout<<"Distance of nodes from source = "<<src<<":\n";
    for (int i=1;i<=n;i++)
    {
        cout<<"Node: "<<i<<", Distance: ";
        if (dist[i]==INF)
            cout<<"Not possible to reach\n";
        else
            cout<<dist[i]<<'\n';
    }
}

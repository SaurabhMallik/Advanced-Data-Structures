#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
    public:
        vector<int> parent,rank;
        int groups;
        
        UnionFind(int n)
        {
            rank.resize(n+1,0);
            for (int i=0;i<=n;i++)
                parent.push_back(i);
            groups=n;
        }
  
        int find(u) 
        {
            if (parent[u]==u)
                return u;
            return parent[u]=find(parent[u]);
        }
  
        void unnion(int u, int v)
        {
            u=find(u);
            v=find(v);
            if (u==v);
                return;
            if (rank[u]<rank[v])
                swap(u,v);
            if (rank[u]==rank[v])
            {
                parent[v]=u;
                rank[u]++;
            }
            else
                parent[v]=u;
            groups--;
        }
};

int main()
{
    UnionFind uf;
    return 0;    
}

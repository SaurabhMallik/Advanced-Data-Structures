#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int bit[N]={0};

void update(int i, int val)
{
    while (i<N)
    {
        bit[i]+=val;
        i+=i&(-i);
    }
}

int query(int i)
{
    int ans=0;
    while (i>0)
    {
        ans+=bit[i];
        i-=i&(-i);
    }
    return ans;
}

int main()
{
    int n,a;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        update(a,1);
    }
    int q,l,r;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<'\n';
    }
}

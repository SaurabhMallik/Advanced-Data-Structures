#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n;
    vector<int> a;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int y;
    cin>>y;
    int l=0,r=n-1,res=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (a[mid]==y)
        {
            res=mid;
            break;
        }
        else if (a[mid]>y)
            r=mid-1;
        else
            l=mid+1;
    }
    if (res==-1)
        cout<<"Element is not avaiable in the given array.\n";
    else
        cout<<"Element is available in the given array.\n";
}

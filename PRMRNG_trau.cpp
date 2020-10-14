#include <bits/stdc++.h>
using namespace std;


deque <int> st;
int n,m,k;
int d[1000005],D[1000005];



void sang()
{
    for (int i=2;i<=sqrt(1e6);i++)
    {
        if (d[i]==1) continue;
        for (int j=i*i;j<=1e6;j+=i) d[j]=1;
    }
    d[1]=1;
    for (int i=1e6;i>=1;i--)
    {
        if (d[i]==0) st.push_front(i);
        if (st.size()>k) st.pop_back();
        if (st.size()==k)
        {
            int t=st.back();
            D[i]=t-i+1;
        }
        else D[i]=1e9;
        //cout<<d[i]<<" "<<st.size()<<" "<<D[i]<<'\n';
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("PRMRNG.inp","r",stdin);
    freopen("PRMRNG.ans","w",stdout);
    cin>>n>>m>>k;
    sang();
    int ans=0,res=-1;
    for (int i=n;i<=m;i++)
    {
        ans=max(ans,D[i]);
        if (ans+i-1<=m) res=m-i+1;
    }
    cout<<res<<'\n';

}

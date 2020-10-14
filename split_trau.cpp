#include <bits/stdc++.h>
using namespace std;



int t,n,top;
int d[100005],ddd[1000005],dd[200005],a[200005],vitri[1000005];
vector <int> A[200005];


void sang()
{
    for (int i=2;i<=sqrt(1e6);i++)
    {
        if (ddd[i]==1) continue;
        for (int j=i*i;j<=1e6;j+=i) ddd[j]=1;
    }
    for (int i=2;i<=1e6;i++)
    {
        if (ddd[i]==1) continue;
        d[++top]=i;
        vitri[i]=top;
    }
    top=0;
    for (int i=2;i<=1e3;i++)
    {
        if (ddd[i]==1) continue;
        d[++top]=i;
        vitri[i]=top;
    }
}



void dfs(int u)
{
    dd[u]=1;
    for (int i=0;i<A[u].size();i++)
    {
        int v=A[u][i];
        if (dd[v]==1) continue;
        dfs(v);
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("split.inp","r",stdin);
    freopen("split.ans","w",stdout);
    sang();
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n+100000;i++) {A[i].clear();dd[i]=0;}
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            int j=1;
            while (a[i]!=1)
            {
                //cout<<a[i]<<'\n';
                if (ddd[a[i]]==0)
                {
                    A[i].push_back(n+vitri[a[i]]);
                    A[n+vitri[a[i]]].push_back(i);
                    break;
                }
                if (a[i]%d[j]==0)
                {
                    A[i].push_back(n+j);
                    A[n+j].push_back(i);
                    while (a[i]%d[j]==0) a[i]/=d[j];
                }
                j++;
            }
        }
        int Count=0;
        for (int i=1;i<=n;i++)
        {
            if (dd[i]==1) continue;
            dfs(i);
            Count++;
        }
        long long MOD=1e9+7;
        long long ans=1;
        for (int i=1;i<=Count;i++)
            ans=(ans*2)%MOD;
        ans=(ans+MOD-2)%MOD;
        cout<<ans<<'\n';
    }
}

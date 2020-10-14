#include<bits/stdc++.h>
using namespace std;

#define task "connect558"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005;
int dd[mxn],n,m,cnt=0;
vector<int> a[mxn],q;
void dfs(int u)
{
    dd[u]=1;
    ++cnt;
    for(int v:a[u])
        if(!dd[v]) dfs(v);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i=1;i<=n;++i)
    if(!dd[i])
    {
        dfs(i);
        q.push_back(cnt);
        cnt=0;
    }
    sort(q.begin(),q.end(),greater<int>());
    if(q.size()==1) cout<<q[0];
    else cout<<q[0]+q[1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}


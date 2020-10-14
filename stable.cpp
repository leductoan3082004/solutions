#include<bits/stdc++.h>
using namespace std;
#define task "stable"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e4+5;
int f[N],n,m,s,dp[N];
vector<int> a[N];

void solve()
{
        cin>>n>>m>>s;
        for(int i=1;i<=m;++i)
        {
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
        }
        for(int i=1;i<=n;++i)
        {
                sort(a[i].begin(),a[i].end());
                a[i].resize(unique(a[i].begin(),a[i].end())-a[i].begin());
        }
        priority_queue<pii,vector<pii>,greater<pii>> q;
        for(int i=1;i<=n;++i) f[i]=1e9;
        q.push({0,s});
        f[s]=0;
        dp[s]=1;
        while(!q.empty())
        {
                int u=q.top().se, len=q.top().fi;
                q.pop();
                if(f[u]<len) continue;
                for(int v:a[u])
                {
                        if(f[v]>f[u]+1)
                        {
                                f[v]=f[u]+1;
                                dp[v]=dp[u];
                                q.push({f[v],v});
                        }
                        else if(f[v]==f[u]+1)
                        {
                                dp[v]+=dp[u];
                                if(dp[v]>=2) dp[v]=2;
                                q.push({f[v],v});
                        }
                }
        }
        int ans=0;
        for(int i=1;i<=n;++i) if(dp[i]>=2)
        {
//                cout<<i<<endl;
                ++ans;
        }
        cout<<ans;
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




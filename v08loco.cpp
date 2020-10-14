#include<bits/stdc++.h>
using namespace std;
#define task "v08loco"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

unordered_map<int,vector<int>> pos;
vector<int> dsk[1005];
int n,a[1005],deg[1005],f[1005];
void solve()
{
        cin>>n;
        FOR(i,1,n)
        {
                cin>>a[i];
                pos[a[i]].push_back(i);
        }

        FOR(i,1,n)
        {
                FOR(j,i+1,n)
                {
                        int k=a[i]+a[j];
                        if(pos.count(k))
                        {
                                for(int t:pos[k])
                                {
                                        dsk[i].push_back(t);
                                        dsk[j].push_back(t);
                                        deg[t]+=2;
                                }
                        }
                }
        }

//        FOR(i,1,n)
//        {
//                for(int v:dsk[i]) cout<<v<<' ';
//                cout<<endl;
//        }
        deque<int> q;
        for(int i=1;i<=n;++i)
        {
                if(deg[i]==0)
                {
                        q.push_back(i);
//                        cout<<i<<endl;
                }
        }
        vector<int>ord;
        while(!q.empty())
        {
                int u=q.front();
                q.pop_front();
                ord.push_back(u);
                for(int v:dsk[u])
                {
                        --deg[v];
                        if(deg[v]==0) q.push_back(v);
                }
        }

        for(int u:ord)
        {
                for(int v:dsk[u])
                {
                        f[v]=max(f[u]+1,f[v]);
                }
        }
        int ans=0;
        FOR(i,1,n) ans=max(ans,f[i]);
        cout<<ans+1;
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




#include<bits/stdc++.h>
using namespace std;
#define task "qbrobot"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=505;
struct three
{
    int u,t,c;
};
int n,ok[N],m,f[N];
vector<three> a[N];

struct cmp
{
        bool operator()(const three &a, const three &b)
        {
                return a.c>b.c;
        }
};
void run1(int s)
{
        fill(f,f+n+1,1e9);
        priority_queue<pii,vector<pii>,greater<pii>> q;
        f[s]=0;
        q.push({0,s});
        while(!q.empty())
        {
                int u=q.top().se, len=q.top().fi;
                q.pop();
                if(f[u]<len) continue;
                for(int i=0;i<a[u].size();++i)
                {
                        int v=a[u][i].u, w=a[u][i].t;
                        if(f[v]>f[u]+w)
                        {
                                f[v]=f[u]+w;
                                q.push({f[v],v});
                        }
                }
        }
}
int run2(int w)
{
        priority_queue<three,vector<three>,cmp> q;
        /// u,t,c;
        q.push({1,0,w});
        while(!q.empty())
        {
                int u=q.top().u,t=q.top().t,pw=q.top().c;
                q.pop();
                if(u==n) return 1;
                for(int i=0;i<a[u].size();++i)
                {
                        int v=a[u][i].u;
                        int t1=a[u][i].t;
                        int w1=a[u][i].c;
                        if(pw<w1) continue;
                        if(t+t1+f[v]==f[1])
                        {
                                int newpw=(ok[v]?w:pw-w1);
                                q.push({v,t+t1,newpw});
                        }
                }
        }
        return 0;
}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;++i) cin>>ok[i];
        cin>>m;
        FOR(i,1,m)
        {
                int u,v,t,c;
                cin>>u>>v>>t>>c;
                a[u].push_back({v,t,c});
                a[v].push_back({u,t,c});
        }
        run1(n);
        int l=0, r=1e9,ans;
        while(l<=r)
        {
                int mid=(l+r)>>1;
                if(run2(mid))
                {
                        r=mid-1;
                        ans=mid;
                }
                else l=mid+1;
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




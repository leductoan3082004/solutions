#include<bits/stdc++.h>
using namespace std;
#define task "split"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int mod=1e9+7;
int n,a[100005],f[1000006],pos[10000505],dd[1000005];
vector<int> dsk[1000005];
vector<int> q;
ll pw(int n, int k)
{
        if(k==0) return 1;
        if(k==1) return n;
        ll t=pw(n,k/2);
        if(k&1) return ((t*t)%mod)*n%mod;
        else return t*t%mod;
}
void sang()
{
        f[0]=1;
        f[1]=1;
        for(int i=2;i<=1e3;++i) {
                if(f[i]) continue;
                for(int j=i*i;j<=1e6;j+=i) {
                        f[j]=1;
                }
        }
        for(int i=1;i<=1e6;++i) {
                if(!f[i]) {
                        q.push_back(i);
                        pos[i]=q.size();
                }
        }
}
void dfs(int u)
{
        dd[u]=1;
        for(int v:dsk[u]) {
                if(!dd[v])
                        dfs(v);
        }
}
void solve()
{
        cin>>n;
        for(int i=1;i<=n+100000;++i)  {
                dd[i]=0;
                dsk[i].clear();
        }
        for(int i=1;i<=n;++i) {
                int x;
                cin>>x;
                for(int j=0;j<q.size();++j) {
                        if(sqrt(x)<q[j]) break;
                        if(x%q[j]==0) {
                                dsk[i].push_back(n+pos[q[j]]);
                                dsk[n+pos[q[j]]].push_back(i);
                        }
                        while(x%q[j]==0) x/=q[j];
                }
                if(x>1) {
                        dsk[i].push_back(n+pos[x]);
                        dsk[n+pos[x]].push_back(i);
                }
        }
        int cnt=0;
        for(int i=1;i<=n;++i) {
                if(!dd[i]) {
                        dfs(i);
                        ++cnt;
                }
        }
        cout<<(pw(2,cnt)-2+mod)%mod<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    sang();
    while(t--)
        solve();
}






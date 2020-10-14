#include<bits/stdc++.h>
using namespace std;
#define task "diameter"
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

int n;
vector<int> a[300005];
int h[300005];

void dfs(int u, int pre)
{
        for(int v:a[u]) {
                if(v==pre)
                        continue;
                h[v]=h[u]+1;
                dfs(v,u);
        }
}
void solve()
{
        cin>>n;
        for(int i=1;i<n;++i) {
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
                a[v].push_back(u);
        }
        dfs(1,1);
        int id=-1;
        for(int i=1;i<=n;++i)
                if(id==-1||h[id]<h[i])
                        id=i;
        for(int i=1;i<=n;++i)
                h[i]=0;
        dfs(id,id);
        cout<<*max_element(h+1,h+n+1)<<'\n';
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
    solve();
}






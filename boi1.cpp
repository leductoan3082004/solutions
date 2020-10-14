#include<bits/stdc++.h>
using namespace std;
#define task "boi1"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=2e5+5;
int n,m,q;
vector<pii> e,qry;
int ok=0,col[N],dd[N];
vector<int> a[N];

void dfs(int u, int c){
        dd[u]=1;
        col[u]=c;
        for(int v:a[u])
        {
                if(dd[v])
                {
                        if(col[v]==col[u])
                        {
                                ok=1;
                                return;
                        }
                        continue;
                }
                dfs(v,1-c);
        }
}
int check(int l, int r) {
        for(int i=1;i<=n;++i){
                a[i].clear();
                dd[i]=0;
                col[i]=0;
        }
        ok=0;
        for(int i=0;i<l;++i){
                int u=e[i].fi,v=e[i].se;
                a[u].push_back(v);
                a[v].push_back(u);
        }
        for(int i=r+1;i<e.size();++i){
                //cout<<'d'<<endl;
                int u=e[i].fi,v=e[i].se;
                a[u].push_back(v);
                a[v].push_back(u);
        }
        for(int i=1;i<=n;++i){
                if(!dd[i]) dfs(i,0);
                if(ok) break;
        }
        return ok;
}
void sub2(){
        //cout<<"haha\n";
        for(int i=0;i<qry.size();++i){
                int l=qry[i].fi,r=qry[i].se;
                if(check(l,r)) cout<<"YES\n";
                else cout<<"NO\n";
        }
}
void sub3(){
        //cout<<"haha\n";
        int l=1,r=m,ans;
        while(l<=r) {
                int mid=(l+r)>>1;
                if(check(1,mid)) {
                        l=mid+1;
                        ans=mid;
                }
                else r=mid-1;
        }
        for(pii i:qry) {
                if(i.se<=ans) cout<<"YES\n";
                else cout<<"NO\n";
        }
}
void solve(){
        cin>>n>>m>>q;
        for(int i=1;i<=m;++i){
                int u,v;
                cin>>u>>v;
                e.push_back({u,v});
        }
        int oksub=1;
        for(int i=1;i<=q;++i){
                int l,r;
                cin>>l>>r;
                --l,--r;
                qry.push_back({l,r});
                oksub&=(l==0);
        }
//        cout<<oksub<<endl;
        if(oksub) sub3();
        else sub2();
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




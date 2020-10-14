/*BINH :))*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long llu;
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f  first
#define s  second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)
#define EL cout<<endl
#define ii pair<ll,ll>

void init(){
    freopen("UPGRADE.inp","r",stdin);
    freopen("UPGRADE.out","w",stdout);
}
vector<ii>a[100000];
ll n,m,dd[1000000],dis[1000000],trace[1000000];
int main(){
    IO
    init();
    cin>>n>>m;
    for(ll i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    ll w,v;
    priority_queue<ii,vector<ii>,greater<ii> >q;
    fill(dis,dis+n+1,LLONG_MAX);
    q.push({0,1});
    while(q.size()){
        ll u = q.top().s;w= q.top().f;
        q.pop();
        if(dd[u])continue;else dd[u]=1;
        for(ll i=0;i<a[u].size();i++){
            v = a[u][i].f;
            ll wv = a[u][i].s;
            if(wv+w<dis[v]){
                dis[v]=wv+w;
                trace[v]=u;
                q.push({wv+w,v});
            }
        }
    }
    if(dis[n]==LLONG_MAX) cout << -1, exit(0);
    ll i=n;
    stack<int>s;
    trace[1]=0;
    //cout<<trace[1];
    while(i!=0){
        s.push(i);
        i=trace[i];
    }
    //while(s.size()) cout << s.top() << ' ', s.pop();



    while(q.size())q.pop();
    fill(dis,dis+n+1,LLONG_MAX);
    fill(dd,dd+n+1,0);
    fill(trace,trace+n+1,0);
    q.push({0,1});
    while(q.size()){
        ll u = q.top().s;w= q.top().f;
        q.pop();
        if(dd[u])continue;else dd[u]=1;
        for(ll i=0;i<a[u].size();i++){
            v = a[u][i].f;
            ll wv = a[u][i].s;
            if(wv+w<=dis[v]){
                dis[v]=wv+w;
                trace[v]=u;
                q.push({wv+w,v});
            }
        }
    }
    if(dis[n]==LLONG_MAX) cout << -1, exit(0);
    i=n;
    stack<int>s1;
    trace[1]=0;
    //cout<<trace[1];
    while(i!=0){
        s1.push(i);
        i=trace[i];
    }
    int res =0;
    while(s1.size())
        if(s1.top()==s.top())
        {
            s1.pop();
            s.pop();
            res++;
        }
        else break;
    cout<<--res;

}

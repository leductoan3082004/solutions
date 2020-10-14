#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long long oo=1e18;
struct two
{
    int val;
    long long len;
};
struct cmp
{
    bool operator()( two a, two b )
    {
        return a.len>b.len;
    }
};
long long f[N],g[N],p[N];
vector<two>a[N];
priority_queue<two,vector<two>,cmp> Heap;
int n,m;
void dijkstra(int s)
{
    for (int i=1; i<=n; i++) f[i]=oo;
    f[s]=0;
    g[s]=p[s];
    Heap.push({s,f[s]});
    while(!Heap.empty()){
        two A=Heap.top();
        int u=A.val;
        long long w=A.len;
        Heap.pop();
        if (f[u]<w) continue;
        for (int i=0; i<a[u].size(); i++){
            two B=a[u][i];
            int v=B.val;
            int len=B.len;
            if (f[v]>f[u]+len){
                f[v]=f[u]+len;
                Heap.push({v,f[v]});
                g[v]=g[u]+p[v];
            }
            else
            if (f[v]==f[u]+len) g[v]=max(g[v],g[u]+p[v]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>p[i];
    cin>>m;
    while(m--){
        int u,v,w;
        cin >> u >>v >>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dijkstra(1);
    if (f[n]>=oo) cout<<"impossible\n";
    else
    cout<<f[n]<<" "<<g[n];
}

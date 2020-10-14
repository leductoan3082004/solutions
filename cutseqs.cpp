#include<bits/stdc++.h>
using namespace std;
#define task "cutseqs"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define __builtin_popcount __builtin_popcountll
#define rep(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (int i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int N=100005;
ll it[4*N];
int n,m,a[N],l[N];

void upd(int i=1, int l=1, int r=n, int p, ll val)
{
    if(l==r) {st[i]=val; return;}
    int mid=(l+r)>>1;
    if(p<=mid) upd(i<<1,l,mid,p,val);
    else upd(i<<1|1,mid+1,r,p,val);
    st[i]=max(st[i<<1],st[i<<1|1]);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]>m) {cout<<-1; return;}
    }
    int j=1;
    deque<int> q;
    for(int i=1;i<=n;++i)
    {
        s+=a[i];
        while(j<i&&s>m) s-=a[j++];
        while((int)q.size()&&q.front()<j) q.pop_front();
        while((int)q.size()&&a[i]>=a[q.back()]) q.pop_back();
        q.push_back(i);
        l[i]=q.front()-1;
    }
    for(int i=1;i<=4*n;++i) st[i]=1e15;
    f[1]=a[1]; j=1;
    for(int i=2;i<=n;++i)
    {
        upd()
    }
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






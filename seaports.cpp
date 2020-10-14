#include<bits/stdc++.h>
using namespace std;
#define task "seaports"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e5+5;
int n,m,thuoc[N];
pii st1[4*N],st2[4*N];
struct three
{
        int l,r,pos;
};
three a[N];

void upd(int i, int l, int r, int p, int val)
{
        if(p>r||p<l) return;
        if(l==r)
        {
                st1[i]={val,p};
                st2[i]={val,p};
                return;
        }
        int mid=(l+r)>>1;
        upd(i<<1,l,mid,p,val);
        upd(i<<1|1,mid+1,r,p,val);
        st1[i]=min(st1[i<<1],st1[i<<1|1]);
        st2[i]=max(st2[i<<1],st2[i<<1|1]);
}

bool cmp(three a, three b)
{
        if(a.r!=b.r) return a.r<b.r;
        else return a.l<b.l;
}
void solve()
{
        cin>>m>>n;
        FOR(i,1,n)
        {
                cin>>a[i].l>>a[i].r;
                a[i].pos=i;
        }
        FOR(i,1,m) upd(1,1,m,i,0);
        sort(a+1,a+n+1,cmp);
        int ans=0;
        FOR(i,1,n)
        {
                pii k=st2[1];
                if(k.fi<=a[i].l)
                {
                        ++ans;
                        thuoc[a[i].pos]=k.se;
                        upd(1,1,m,k.se,a[i].r);
                        continue;
                }
                k=st1[1];
                if(k.fi<=a[i].l)
                {
                        ++ans;
                        thuoc[a[i].pos]=k.se;
                        upd(1,1,m,k.se,a[i].r);
                        continue;
                }
        }
        cout<<ans<<'\n';
        FOR(i,1,n) cout<<thuoc[i]<<' ';
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




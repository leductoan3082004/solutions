#include<bits/stdc++.h>
using namespace std;
#define task "bonus13"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define rep(i,a,b) for(ll i=(a),_b=(b);i<=_b;++i)
#define repd(i,a,b) for(ll i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
int n;
ull ma[100],tuong[100],hau[100],xe[100],cnt[100];
pii a[100];
ull val[100];

int pos(int u, int v)
{
    return u*8+v;
}
void solve()
{
    cin>>n;
    ll bug=0;
    for(int i=1;i<=n;++i)
    {
        int c;
        cin>>a[i].fi>>a[i].se>>c;
        a[i].fi--,a[i].se--;
        val[pos(a[i].fi, a[i].se)]+=c;
        bug+=c;
        cnt[pos(a[i].fi,a[i].se)]=1;
    }
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(cnt[pos(i,j)])continue;
            for(int x=0;x<8;++x)
            {
                for(int y=0;y<8;++y)
                {
                    ll k=pos(i,j);
                    ll k1=pos(x,y);
                    ///tuong
                    if(x-y==i-j) tuong[k]|=(1LL<<k1);
                    if(x+y==i+j) tuong[k]|=(1LL<<k1);
                    if(x==i) xe[k]|=(1LL<<k1);
                    if(y==j) xe[k]|=(1LL<<k1);
                    if((abs(x-i)==2&&abs(y-j)==1)||(abs(x-i)==1&&abs(y-j)==2)) ma[k]|=(1LL<<k1);
                }
            }
            hau[pos(i,j)]=tuong[pos(i,j)]|xe[pos(i,j)];
        }
    }
    ll ans=0;
    for(int h=0;h<64;++h) if(!cnt[h])
    {
        cnt[h]=1;
        for(int x=0;x<64;++x) if(!cnt[x])
        {
            cnt[x]=1;
            for(int t=0;t<64;++t) if(!cnt[t])
            {
                cnt[t]=1;
                for(int m=0;m<64;++m) if(!cnt[m])
                {
                    ll tmp=0;
//                    cout<<hau[h]<<' '<<xe[x]<<' '<<tuong[t]<<' '<<ma[m]<<endl;
                    ll mask=1LL*hau[h]|xe[x]|tuong[t]|ma[m];
//                    cout<<mask<<endl;
                    for(int i=1;i<=n;++i) if((mask>>pos(a[i].fi,a[i].se))&1) tmp+=val[pos(a[i].fi,a[i].se)];
                    ans=max(ans,tmp);
                }
                cnt[t]=0;
            }
            cnt[x]=0;
        }
        cnt[h]=0;
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





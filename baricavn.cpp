#include<bits/stdc++.h>
using namespace std;
#define task "baricavn"
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

const int N=300000;
int  st[4*N+4],n,k,dp[N+5];
ar<int,3> a[N+5];
void upd(int i, int l, int r, int p, int val)
{
    if(l==r)
    {
        st[i]=max(st[i],val);
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) upd(i<<1,l,mid,p,val);
    else upd(i<<1|1,mid+1,r,p,val);
    st[i]=max(st[i<<1],st[i<<1|1]);
}
int get(int i, int l, int r, int u, int v)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[i];
    int mid=(l+r)>>1;
    return max(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    upd(1,1,N,a[1][1],a[1][2]);
    sort(a+2,a+n);
    for(int i=1;i<=n;++i) dp[i]=-1e9;
    dp[1]=a[1][2];
    for(int i=2;i<=n;++i)
    {
        /// x1<x2, y1=y2
        /// x1=x2, y1<y2;
        int ep=i;
        while(a[ep+1][0]==a[i][0]) ++ep;
        for(int j=i;j<=ep;++j)
        {
            int tmp=get(1,1,N,a[j][1],a[j][1]);
            if(tmp<k) continue;
            tmp-=k;
            tmp+=a[j][2];
            dp[j]=tmp;
        }
        int mx=dp[i];
        for(int j=i+1;j<=ep;++j)
        {
            if(mx>=k) dp[j]=max(dp[j],mx-k+a[j][2]);
            mx=max(mx,dp[j]);
        }
        for(int j=i;j<=ep;++j)
        {
            upd(1,1,N,a[j][1],dp[j]);
        }
        i=ep;
    }
//    cout<<dp[2]<<endl;
    cout<<dp[n];
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





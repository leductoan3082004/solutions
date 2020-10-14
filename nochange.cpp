#include<bits/stdc++.h>
using namespace std;
#define task "nochange"
#define BIT(x,i) (((x)>>(i))&1)
#define __builtin_popcount __builtin_popcountll
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int N=1e5+5;
int k,n,coin[20],a[N],dp[70007],f[N];
void solve()
{
    cin>>k>>n;
    for(int i=1;i<=k;++i) cin>>coin[i];
    for(int i=1;i<=n;++i) cin>>a[i], f[i]=f[i-1]+a[i];

    for(int mask=0;mask<(1<<k);++mask) dp[mask]=-1e9;
    dp[0]=0;
    for(int mask=0;mask<(1<<k);++mask)
    {
        if(dp[mask]==-1e9) continue;
        for(int i=1;i<=k;++i)
        {
            if(BIT(mask,i-1)==0)
            {
                int mask1=mask|(1<<(i-1));
                int l=id, r=n, tam=n, id=dp[mask];
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(f[mid]-f[id]<=coin[i])
                    {
                        l=mid+1;
                        tam=mid;
                    }
                    else r=mid-1;
                }
                dp[mask1]=max(dp[mask1],tam);
            }
        }
    }
    int ans=-1;
    for(int mask=0;mask<(1<<k);++mask)
        if(dp[mask]==n)
        {
            int tmp=0;
            for(int i=0;i<k;++i)
            if(BIT(mask,i)==0) tmp+=coin[i+1];
            ans=max(ans,tmp);
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







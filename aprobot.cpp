#include<bits/stdc++.h>

using namespace std;

#define task "aprobot"
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

const int mod=998244353;

const int mxn=5005;

int n,k,dp[mxn],c[mxn];
ii a[mxn];

bool cmp(ii a, ii b)
{
    if(a.fi!=b.fi) return a.fi>b.fi;
    return a.se<b.se;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].fi;
        a[i].se=i;
    }

    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i) c[a[i].se]=(i+k-1)/k;
    for(int i=1;i<=n;++i) dp[i]=1;
    int ans=0;
    for(int i=1;i<=n;++i)
    for(int j=1;j<i;++j)
    {
        if(c[i]>=c[j]) dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
    }
    cout<<n-ans;
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







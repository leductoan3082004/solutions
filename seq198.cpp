#include<bits/stdc++.h>

using namespace std;

#define task "seq198"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=2005;
vector<int> a;
int n,dp[mxn][(1<<11)];
map<int,int> cnt;

void solve()
{
    cin>>n;
    a.resize(n+1);
    a[0]=-1;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    a.resize(unique(a.begin(),a.end())-a.begin());
    int nn=a.size()-1;
    for(int i=10;i<=nn;++i) fill(dp[i],dp[i]+1025,1e9);
    for(int i=10;i<=nn;++i)
    {
        for(int m=0;m<(1<<10);++m)
        {
            int mask=(m/2);
            for(int j=i-9;j<i;++j)
            {

            }
        }
    }
    int ans=2e9;
    for(int mask=0;mask<(1<<10);++mask) ans=min(ans,dp[nn][mask]);
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







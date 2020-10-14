#include<bits/stdc++.h>
using namespace std;

#define task "smax"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=5005;
int n,dp[mxn],a[mxn],trace[mxn];
void solve()
{
    cin>>n;
    fore(i,1,n)
    {
        cin>>a[i];
        dp[i]=a[i];
    }

    fore(i,1,n)
    {
        fore(j,1,i-1)
        {
            if(a[j]<a[i]&&dp[j]+a[i]>dp[i])
            {
                dp[i]=dp[j]+a[i];
                trace[i]=j;
            }
        }
    }
    int id=1, mx=dp[1];

    fore(i,2,n)
        if(dp[i]>mx)
        {
            mx=dp[i];
            id=i;
        }
    vector<int> ans;
    while(id!=0)
    {
        ans.push_back(id);
        id=trace[id];
    }
    reverse(ans.begin(),ans.end());
    cout<<mx<<'\n';
    cout<<ans.size()<<'\n';
    for(int i:ans) cout<<i<<' ';
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



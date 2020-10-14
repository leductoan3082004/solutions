#include<bits/stdc++.h>
using namespace std;
#define task "twosum"
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

const int N=5005;
int n,a[N];
ll f[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],f[i]=f[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;++i)
    for(int j=min(i-1,i-ans);j>=1;--j)
    {
        if((f[i]-f[j-1])&1) continue;
        int k=(f[i]-f[j-1])/2;
        int l=j, r=i-1, ok=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(f[mid]-f[j-1]==k) {ok=1; break;}
            if(f[mid]-f[j-1]>=k) r=mid-1;
            else l=mid+1;
        }
        if(ok) ans=max(ans,i-j+1);
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






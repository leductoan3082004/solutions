#include<bits/stdc++.h>

using namespace std;

#define task "bientau"
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

const int mod=998244353;
const int mxn=5005;

int n,a[mxn],ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];

    for(int len=2;len<=n;++len)
    {
        int tmp=1;
        for(int i=len+1;i<n;++i)
        if(a[i]-a[i+1]==a[i-len]-a[i-len+1])
        {
            ++tmp;
            ans=max(ans,tmp);
            if(tmp==len) break;
        }
        else tmp=1;
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






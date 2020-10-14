#include<bits/stdc++.h>
using namespace std;

#define task "qbmseq"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=10005;
ll u[mxn],n,a[mxn];

void solve()
{
    cin>>n;
    u[1]=1;
    for(int i=2;i<=10000;++i) u[i]=u[i-1]+i;
    int dem=0,ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        int k=binary_search(u+1,u+10001,a[i]);
        if(k)
        {
            if(a[i]>=a[i-1]) ++dem;
            else dem=1;
        }
        else dem=0;
        ans=max(ans,dem);
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



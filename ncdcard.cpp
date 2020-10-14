#include<bits/stdc++.h>
using namespace std;
#define task "ndccard"
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

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        int p=lwb(a+1,a+n+1,m-a[i])-a;
        for(int j=max(p-10,1);j<=min(n,p-10);++j)
        {
            if(i==j) continue;

        }
    }
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






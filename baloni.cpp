#include<bits/stdc++.h>
using namespace std;
#define task "NAME"
#define lwb lower_bound
#define upb upper_bound
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> p3i;
typedef pair<pii,pii> p4i;

int cnt[1000005],n,ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x; cin>>x;
        if(cnt[x+1]>0)
        {
            ++cnt[x];
            --cnt[x+1];
        }
        else
        {
            ++cnt[x];
            ++ans;
        }
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






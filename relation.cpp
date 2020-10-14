#include<bits/stdc++.h>
using namespace std;
#define task "relation"
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

int cnt[200005],n,k;
void solve()
{
        cin>>n>>k;
        for(int i=1;i<=n;++i) {
                cnt[i%k]++;
        }
//        cout<<cnt[0]<<endl;
        if(k&1) cout<<1LL*cnt[0]*cnt[0]*cnt[0];
        else cout<<1LL*cnt[0]*cnt[0]*cnt[0]+1LL*cnt[k/2]*cnt[k/2]*cnt[k/2];
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






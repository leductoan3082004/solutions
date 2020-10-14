#include<bits/stdc++.h>
using namespace std;
#define task "coupon"
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

vector<int> a[40];
int n,m,s[40],c[40];
void solve()
{
        cin>>n>>m;
        for(int i=1;i<=n;++i) {
                int k; cin>>k;
                a[i].clear();
                for(int j=1;j<=k;++j) {
                        int x; cin>>x;
                        a[i].push_back(x);
                }
                int x; cin>>x;
                s[i]=x;
        }
        for(int i=1;i<=m;++i) {
                cin>>c[i];
        }
        int ans=0;
        for(int i=1;i<=n;++i) {
                int mn=1e9;
                for(int j:a[i]) mn=min(mn,c[j]);
                ans+=mn*s[i];
                for(int j:a[i]) c[j]-=mn;
        }
        cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    while(t--)
    solve();
}






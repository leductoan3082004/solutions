#include<bits/stdc++.h>
using namespace std;
#define task "NAME"
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

ll L,R;

ll pw(ll n, ll k)
{
    if(k==0) return 1;
    if(k==1) return n;
    ll t=pw(n,k/2);
    if(k&1) return t*t*n;
    else return t*t;
}
void solve()
{
    cin>>L>>R;
    for(int k=40;k>=1;--k)
    {
        int  l=2,r=5+(int)pow(R,(ld)1/k);
        for(int i=max(2,r-50);i<=r+4;++i)
        {
            ll tam=pw(i,k);
            if(tam>=L&&tam<=R)
            {
                cout<<k<<'\n';
                return;
            }
        }
        /*while(l<=r)
        {
            int mid=(l+r)>>1;
            ll tam=pw(mid,k);
            if(tmp>=L&&tmp<=R)
            {
                cout<<k<<'\n';
                return;
            }
            if(tmp<L) l=mid+1;
            else r=mid-1;
        }*/
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
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}






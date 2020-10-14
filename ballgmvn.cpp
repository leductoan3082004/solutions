#include<bits/stdc++.h>
using namespace std;
#define task "ballgmvn"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1005;
int n;
pii a[N],b[N];

void calc(int beg, int pos, pii q[])
{
    vector<pair<ld,int>> s;
    s.clear();
    pii p;
    if(beg==0) p=a[pos];
    else p=b[pos];
    for(int i=1;i<=n;++i)
    {
        int x=q[i].fi-p.fi, y=q[i].se-p.se;
        if(y==0) s.push_back({1e9,i});
        else s.push_back({1.00*x/y,i});
    }
    sort(ALL(s));
    for(int i=1;i<s.size();++i)
    {
        if(s[i].fi==s[i-1].fi)
        {
            if(beg==0)
            {
                cout<<pos<<' '<<n+s[i-1].se<<' '<<n+s[i].se;
            }
            else cout<<pos+n<<' '<<s[i-1].se<<' '<<s[i].se;
            exit(0);
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].fi>>a[i].se;
    for(int i=1;i<=n;++i) cin>>b[i].fi>>b[i].se;
    for(int i=1;i<=n;++i) calc(0,i,b);
    for(int i=1;i<=n;++i) calc(1,i,a);
    cout<<-1;
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






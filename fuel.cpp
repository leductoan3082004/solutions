#include<bits/stdc++.h>
using namespace std;
#define task "fuel"
#define BIT(x,i) (((x)>>(i))&1)
#define __builtin_popcount __builtin_popcountll
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int N=50005;
int n,g,b,d;
ii a[N];
int pos[N];
void solve()
{
    cin>>n>>g>>b>>d;
    for(int i=1;i<=n;++i) cin>>a[i].fi>>a[i].se;
    ++n;
    a[n]={d,0};
    sort(a+1,a+n+1);
    stack<int> st;
    for(int i=n;i>=1;--i)
    {
        if(st.size()&&a[st.top()].se>=a[i].se) st.pop();
        if(st.size()) pos[i]=st.top();
        else pos[i]=-1;
        st.push(i);
    }
    b-=a[1].se;
    ll ans=0;
    for(int i=1;i<n;++i)
    {
        if(b<0)
        {
            cout<<-1;
            return;
        }
        int need;
        if(pos[i]==-1) need=g;
        else need=a[pos[i]].fi-a[i].fi;
        need=min(need,g);
        if(b<need)
        {
            ans+=(need-b)*a[i].se;
            b=need;
        }
        b-=need;
    }
    if(b<0) cout<<-1;
    else
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







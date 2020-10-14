#include<bits/stdc++.h>
using namespace std;
#define task "cprime"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(ll i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(ll i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pii;

const ll N=1e6+5;
vector<ll> q;
vector<ll> st1,st2;
ll f[N];

void sang()
{
        f[1]=1;
        f[0]=1;
        for(ll i=2;i<=1000;++i)
        {
                if(!f[i])
                for(ll j=i*i;j<=1000000;j+=i)
                {
                        f[j]=1;
                }
        }
        for(ll i=2;i<=1000000;++i)
                if(!f[i]) q.push_back(i);
}
ll pw(ll n, ll k)
{
        if(k==0) return 1;
        if(k==1) return n;
        ll t=pw(n,k/2);
        if(k&1) return t*t*n;
        else return t*t;
}
void cb1()
{
//        for(ll i:q) cout<<i<<' ';
        for(ll i:q)
        {
                for(ll j:q)
                {
//                        cout<<i<<' '<<j<<' '<<pw(i,j-1)<<endl;
                        if(pw(i,j-1)<=1000000)
                        {

                                st1.push_back(pw(i,j-1));
                        }
                        else break;
                }
        }
        sort(st1.begin(),st1.end());
//        for(ll i:st1) cout<<i<<' ';
}
void cb2()
{
        for(ll i:q)
        {
                for(ll j:q)
                {
                        if(j==2) continue;
                        if(1000000<=pw(i,j-1)&&pw(i,j-1)<=1000000000000)
                        {
                                st2.push_back(pw(i,j-1));
                        }
                        else if(pw(i,j-1)>1e12) break;
                }
        }
        sort(ALL(st2));
}
void sub1(ll a, ll b)
{
        ll l=lower_bound(ALL(st1),a)-st1.begin();
        ll r=upper_bound(ALL(st1),b)-st1.begin()-1;
        cout<<r-l+1<<'\n';
}
void sub2(ll a,ll b)
{
        ll l=lower_bound(ALL(st2),a)-st2.begin();
        ll r=upper_bound(ALL(st2),b)-st2.begin()-1;
        cout<<r-l+1<<'\n';
}
void solve()
{
        ll a,b;
        cin>>a>>b;
        if(a>1000000) sub2(a,b);
        else sub1(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    sang();
    cb1();
    cb2();
    ll t;
    cin>>t;
    while(t--) solve();
}




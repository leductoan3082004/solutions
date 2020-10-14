

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll pw[30],ans=0;
int scs(ll a) {
    int cnt=0;
    while(a>0) {
        cnt++;
        a/=10LL;
    }
    return cnt;
}
bool check(ll s, ll k, ll u, ll cnt) {
    ll cost=0;
    ll l=k+1, r=k+cnt;
//    cout<<l<<' '<<r<<endl;
    for(ll i=l;i<=r;++i) {
        cost+=scs(i)*u;
    }
    return (cost<=s);
}
long long maxSizeOfNumbers(long long s, long long k, long long u)
{
    pw[1]=1;
    for(int i=2;i<=18;++i) pw[i]=pw[i-1]*10;
    ll l=1, r=1e5;

    while(l<=r) {
        ll mid=(l+r)/2;
        if(check(s,k,u,mid)) {
            l=mid+1;
            ans=mid;
        }
        else {
            r=mid-1;
        }
    }
    return ans;
}
int main() {
        freopen("codewar.inp","r",stdin);
        freopen("codewar.ans","w",stdout);
        ll s,k,u;
        cin>>s>>k>>u;
        cout<<maxSizeOfNumbers(s,k,u);
}

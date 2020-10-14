#include<bits/stdc++.h>

using namespace std;

#define task "trungvi"
#define fi first
#define se second
#define fore(i,a,b) for(ll i=(ll)a;i<=(ll)b;++i)
#define ford(i,a,b) for(ll i=(ll)a;i>=(ll)b;--i)

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=100005;

ll n,m,a[2*mxn],b[2*mxn];
multiset<ll,greater<ll>> s1;
multiset<ll> s2;

void ILYPTV()
{
    cin>>n>>m;
    for(ll i=1;i<=2*n+1;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+2*n+2);
    for(ll i=1;i<=n;++i) s1.insert(b[i]);
    for(ll i=n+1;i<=2*n+1;++i) s2.insert(b[i]);
//    cout<<*s1.begin()<<'\n';
    while(m--)
    {
        ll i,k;
        cin>>i>>k;
        ++i;
        if(s1.find(a[i])!=s1.end())
        {
            s1.erase(s1.find(a[i]));
            s1.insert(k);
        }
        else
        {
            s2.erase(s2.find(a[i]));
            s2.insert(k);
        }
        a[i]=k;
        if(*s1.begin()>=*s2.begin())
        {
            ll tmp1=*s1.begin();
            ll tmp2=*s2.begin();
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            s1.insert(tmp2);
            s2.insert(tmp1);
        }
        cout<<*s2.begin()<<'\n';
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
    ILYPTV();
}







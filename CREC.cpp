#include <bits/stdc++.h>
using namespace std;

#define oo 1e9
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;

ll n,k,i,l,h,sl;
pll a[400009];

int main(){
    IO;
    cin>>n>>k;
    for (i=1;i<=n;i++) {
        cin>>a[i].fi>>a[i].se;
    }
    sort(a+1,a+n+1);
    l=a[1].fi;
    h=a[1].se;
    sl=1;
    for (i=2;i<=n;i++) {
        if (max(h,a[i].se)*(a[i].fi-l)>k) {
            sl++;
            l=a[i].fi;
            h=a[i].se;
        }
        else {
            h=max(h,a[i].se);
        }
    }
    cout<<sl;
}

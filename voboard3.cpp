#include<bits/stdc++.h>
using namespace std;
#define task ""
#define BIT(x, i) (((x) >> (i)) & 1)
#define lb lower_bound
#define ub upper_bound
#define lla(v) (v).begin(),(v).end()
#define zs(v) (v).size()
#define fi first
#define se second
#define pb push_back
#define ar array
#define endl '\n'
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

x+y>z
x+z>y
y+z>x

void solved()
{
    ll n,m;
    cin>>n>>m;
    cout<<(n+2)%mod*m%mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solved();
}

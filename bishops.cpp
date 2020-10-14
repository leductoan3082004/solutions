#include<bits/stdc++.h>
using namespace std;
#define task "NAME"
#define lb lower_bound
#define ub upper_bound
#define alll(v) (v).begin(),(v).end()
#define szz(v) (v).size()
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int MOD=1000000007; /// 998244353
const int base=311; /// for hash actually
const int N=1e5+5;

void solved()
{
    ll a,b,x,y,n;
    cin>>n;
    cin>>a>>b>>x>>y;
    if((a+b)%2==(x+y)%2) cout<<"yes";
    else cout<<"no";
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

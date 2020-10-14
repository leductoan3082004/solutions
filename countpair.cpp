#include<bits/stdc++.h>
using namespace std;
#define task "countpair"
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
    string s;
    cin>>s;
    int a=0,b;
    ll ans=0;
    FOR(i,0,szz(s)-1)
    {
        if(s[i]=='2') ans+=a;
        if(s[i]=='1') ++a;
//        cout<<a<<endl;
    }
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
    solved();
}

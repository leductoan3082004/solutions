#include<bits/stdc++.h>
using namespace std;
#define task "rmatrix"
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

int n,m,a[55][55];
void solved()
{
    cin>>n>>m;
    FOR(i,1,n) FOR(j,1,m) cin>>a[i][j];

    FOR(i,1,n)
    {
        if(a[i][1]==1) continue;
        FOR(j,1,m) a[i][j]=1-a[i][j];
    }
//    FOR(i,1,n)
//    {
//        FOR(j,1,m) cout<<a[i][j]<<' ';
//        cout<<endl;
//    }
    ll ans=0;
    FOR(j,1,m)
    {
        int ko=0,mot=0;
        FOR(i,1,n)
        {
            ko+=(a[i][j]==0);
            mot+=(a[i][j]==1);
        }
        mot=max(mot,ko);
        ans+=mot*(1LL<<(m-j));
//        if(j==1) cout<<mot<<endl;
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

#include<bits/stdc++.h>
using namespace std;
#define task "vo17lan"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=5e4+5;

int n,a[N];
int ans=1;

void sol(int tap1)
{
    int tap2=-1;
    for(int i=1;i<=n;++i)
    {
        if(a[i]%tap1==0) continue;
        if(a[i]%tap1!=0)
        {
            if(tap2==-1) tap2=a[i];
            else tap2=__gcd(tap2,a[i]);
        }
        if(ans>=min(tap1,tap2)) return ;
    }
    if(tap2==-1) tap2=2e9;
    ans=max(ans,min(tap1,tap2));
}
void biot()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    ans=1;
    for(int i=1;i<=sqrt(a[1]);++i)
    {
        if(a[1]%i==0)
        {
            sol(i); sol(a[1]/i);
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    while(t--) biot();
    return 0;
}

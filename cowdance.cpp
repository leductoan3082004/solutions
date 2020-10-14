#include<bits/stdc++.h>

using namespace std;

#define task "cowdance"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,b,a) for(int i=(b);i>=(a);--i)
#define REP(i,a,b) for(int i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;

const int N=1e4+5;

int n,t,a[N];

int check(int k)
{
    priority_queue<int,vector<int>,greater<int>> q;
    while(zs(q)) q.pop();


    for(int i=1;i<=k;++i) q.push(a[i]);

    ll  cur=0;

    for(int i=k+1;i<=n;++i)
    {
        int val=q.top(); q.pop();
        cur=val;
        q.push(cur+a[i]);
    }

    while(zs(q)>1) q.pop();

    return (q.top()<=t);
}
void biot()
{
    cin>>n>>t;
    for(int i=1;i<=n;++i) cin>>a[i];
    int l=1,r=n,ans;

    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".in","r"))
    {
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
    biot();
    return 0;
}


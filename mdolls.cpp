#include<bits/stdc++.h>
using namespace std;
#define task "mdolls"
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) (int)(v).size()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define cntbit __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

void upd(int i,int l,int r,int p,int val)
{

}
void biot()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].X>>a[i].Y;
    sort(a+1,a+n+1);

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int T;
    cin>>T;
    while(T--)
    biot();
}












#include<bits/stdc++.h>
using namespace std;
#define task "fenwick"
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) (int)(v).size()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define cntbit __builtin_popcountll
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

int fen[N];

void upd(int i, int val)
{
    for(;i<=N;i+=i&-i) fen[i]+=val;
}
int get(int i)
{
    int ans=0;
    for(;i;i-=i&-i) ans+=fen[i];
    return ans;
}
void biot()
{
    int a[]={0,1,2,3,100,5,6};
    for(int i=1;i<=6;++i) upd(i,a[i]-a[i-1]);
    for(int i=1;i<=6;++i) cout<<get(i)<<' ';
    cout<<endl;
    upd(3,100); upd(5,-100);
    for(int i=1;i<=6;++i) cout<<get(i)<<' ';
//    cout<<get(4);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    biot();
}












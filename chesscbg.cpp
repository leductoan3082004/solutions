#include<bits/stdc++.h>

using namespace std;

#define task "chesscbg"
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
const int N=1e5+5;

string s[5],t[5];
int dp[N], dd[N];

int posmask(int x, int y)
{
    return x*4+y;
}
void biot()
{
    for(int i=0;i<4;++i) cin>>s[i];
    for(int i=0;i<4;++i) cin>>t[i];

    int tam=0;

    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            int c=s[i][j]-'0';
            if(c) tam+=(1<<posmask(i,j));
        }
    }

    for(int mask=0;mask<(1<<16);++mask) dp[mask]=1e9;
    dp[tam]=0;
    dd[tam]=1;
    deque<int> q;
    q.pb(tam);
    while(zs(q))
    {
        int mask=q.front(); q.pf();
        for(int i=0;i<16;++i)
        {
            if(!BIT(mask,i)) continue;
            int u=i/4, v=i%4;
            for(int k=0;k<4;++k)
            {
                int x=u+dx[k], y=v+dy[k];
                if(x>=0&&x<=3&&y>=0&&y<=3)
                {
                    if(BIT(mask,posmask(x,y))) continue;
                    int nmask=mask-(1<<posmask(u,v))+(1<<posmask(x,y));
                    if(dd[nmask]) continue;
                    dd[nmask]=1;
                    dp[nmask]=dp[mask]+1;
                    q.pb(nmask);
                }
            }
        }
    }
    tam=0;
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            int c=t[i][j]-'0';
            if(c) tam+=(1<<posmask(i,j));
        }
    }
    cout<<dp[tam];
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
    return 0;
}



















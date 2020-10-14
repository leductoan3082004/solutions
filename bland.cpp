#include<bits/stdc++.h>
using namespace std;
#define task "bland"
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
const int N=305;

template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
int n,m,k,a[N][N];

deque<int> qmin[N],qmax[N];
int cotmax[N][N][N],cotmin[N][N][N],hangmax[N][N][N],hangmin[N][N][N];

void calcrow()
{
    for(int i1=1;i1<=n;++i1)
    {
        for(int j=1;j<=m;++j)
        {
            while(zs(qmin[j])) qmin[j].pf();
            while(zs(qmax[j])) qmax[j].pf();
        }
        /// add a[i2][j] to each q[j] and find max
        for(int j=1;j<=m;++j)
        {
            for(int i2=i1;i2<=n;++i2)
            {
                while(zs(qmax[j])&&a[qmax[j].back()][j]<=a[i2][j]) qmax[j].pop_back();
                while(zs(qmin[j])&&a[qmin[j].back()][j]>=a[i2][j]) qmin[j].pop_back();
                qmin[j].pb(i2); qmax[j].pb(i2);
                cotmax[i1][i2][j]=a[qmax[j].front()][j];
                cotmin[i1][i2][j]=a[qmin[j].front()][j];
            }
        }
    }
//    cout<<cotmax[1][4][2]<<endl;
}
void calccol()
{
    for(int j1=1;j1<=m;++j1)
    {
        for(int i=1;i<=n;++i)
        {
            while(zs(qmin[i])) qmin[i].pf();
            while(zs(qmax[i])) qmax[i].pf();
        }
        for(int i=1;i<=n;++i)
        {
            for(int j2=j1;j2<=m;++j2)
            {
            /// add a[i][j2] to each i
                while(zs(qmax[i])&&a[i][j2]>=a[i][qmax[i].back()]) qmax[i].pop_back();
                while(zs(qmin[i])&&a[i][j2]<=a[i][qmin[i].back()]) qmin[i].pop_back();
                qmin[i].pb(j2); qmax[i].pb(j2);
                hangmax[j1][j2][i]=a[i][qmax[i].front()];
                hangmin[j1][j2][i]=a[i][qmin[i].front()];
            }
        }
    }
}
int tinhhang()
{
    vector<int> l(n+3,0), r(n+3,0);
    deque<int> q1,q2;
    for(int i1=1;i1<=n;++i1)
    {
        for(int i2=i1;i2<=n;++i2)
        {
            while(zs(q1)) q1.pop_front();
            while(zs(q2)) q2.pop_front();
            int bot=1;
            for(int j=1;j<=m;++j)
            {
                while(zs(q1)&&cotmax[i1][i2][q1.back()]<=cotmax[i1][i2][j]) q1.pop_back();
                while(zs(q2)&&cotmin[i1][i2][q2.back()]>=cotmin[i1][i2][j]) q2.pop_back();
                q1.pb(j);
                q2.pb(j);
                while(bot<=j&&zs(q1)&&zs(q2)&&cotmax[i1][i2][q1.front()]-cotmin[i1][i2][q2.front()]>k)
                {
                    ++bot;
                    while(zs(q1)&&q1.front()<bot) q1.pop_front();
                    while(zs(q2)&&q2.front()<bot) q2.pop_front();
                }
                if(bot>j) continue;
                l[j]=max(l[j],(j-bot+1)*(i2-i1+1));
            }
            while(zs(q1)) q1.pop_front();
            while(zs(q2)) q2.pop_front();
            bot=m;
            for(int j=m;j>=1;--j)
            {
                while(zs(q1)&&cotmax[i1][i2][q1.back()]<=cotmax[i1][i2][j]) q1.pop_back();
                while(zs(q2)&&cotmin[i1][i2][q2.back()]>=cotmin[i1][i2][j]) q2.pop_back();
                q1.pb(j);
                q2.pb(j);
                while(bot>=j&&zs(q1)&&zs(q2)&&cotmax[i1][i2][q1.front()]-cotmin[i1][i2][q2.front()]>k)
                {
                    --bot;
                    while(zs(q1)&&q1.front()>bot) q1.pop_front();
                    while(zs(q2)&&q2.front()>bot) q2.pop_front();
                }
                if(bot<j) continue;
                r[j]=max(r[j],(bot-j+1)*(i2-i1+1));
            }
        }
    }
    for(int j=m;j>=0;--j) r[j]=max(r[j+1],r[j]);
    for(int j=1;j<=m;++j) l[j]=max(l[j-1],l[j]);
    int ans=0;
    for(int j=0;j<=m;++j) ans=max(ans,l[j]+r[j+1]);
    //cout<<ans<<'\n';
    return ans;
}
int tinhcot()
{
    vector<int> l(n+3,0), r(n+3,0);
    deque<int> q1,q2;
    for(int j1=1;j1<=m;++j1)
    {
        for(int j2=j1;j2<=m;++j2)
        {
            while(zs(q1)) q1.pop_front();
            while(zs(q2)) q2.pop_front();
            int bot=1;
            for(int i=1;i<=n;++i)
            {
                while(zs(q1)&&hangmax[j1][j2][q1.back()]<=hangmax[j1][j2][i]) q1.pop_back();
                while(zs(q2)&&hangmin[j1][j2][q2.back()]>=hangmin[j1][j2][i]) q2.pop_back();
                q1.pb(i);
                q2.pb(i);
                while(bot<=i&&zs(q1)&&zs(q2)&&hangmax[j1][j2][q1.front()]-hangmin[j1][j2][q2.front()]>k)
                {
                    ++bot;
                    while(zs(q1)&&q1.front()<bot) q1.pop_front();
                    while(zs(q2)&&q2.front()<bot) q2.pop_front();
                }
                if(bot>i) continue;
                l[i]=max(l[i],(i-bot+1)*(j2-j1+1));
            }
            while(zs(q1)) q1.pop_front();
            while(zs(q2)) q2.pop_front();
            bot=n;
            for(int i=n;i>=1;--i)
            {
                while(zs(q1)&&hangmax[j1][j2][q1.back()]<=hangmax[j1][j2][i]) q1.pop_back();
                while(zs(q2)&&hangmin[j1][j2][q2.back()]>=hangmin[j1][j2][i]) q2.pop_back();
                q1.pb(i);
                q2.pb(i);
                while(bot>=i&&zs(q1)&&zs(q2)&&hangmax[j1][j2][q1.front()]-hangmin[j1][j2][q2.front()]>k)
                {
                    --bot;
                    while(zs(q1)&&q1.front()>bot) q1.pop_front();
                    while(zs(q2)&&q2.front()>bot) q2.pop_front();
                }
                if(bot<i) continue;
                r[i]=max(r[i],(bot-i+1)*(j2-j1+1));
            }
        }
    }
    for(int j=n;j>=0;--j) r[j]=max(r[j+1],r[j]);
    for(int j=1;j<=n;++j) l[j]=max(l[j-1],l[j]);
    int ans=0;
    for(int j=0;j<=n;++j) ans=max(ans,l[j]+r[j+1]);
    //cout<<ans<<'\n';
    return ans;
}
void biot()
{
    read(n); read(m); read(k);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) read(a[i][j]);
    calcrow();
    calccol();
//    tinhcot();
    int ans=max(ans,max(tinhhang(),tinhcot()));
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
    biot();
    return 0;
}


















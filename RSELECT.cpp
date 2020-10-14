#include<bits/stdc++.h>

using namespace std;

#define task "rselect"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

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
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int n,a[mxn][mxn],f[mxn][mxn][6],d=0;
int ans=0,dd[mxn][mxn];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

void bfs(int u, int v, int delta)
{
    int cnt=0;
    ++d;
    deque<pii> q;
    q.push_back({u,v});
    while(!q.empty())
    {
        u=q.front().fi;
        v=q.front().se;
        dd[u][v]=d;
        ++cnt;
        q.pop_front();
        for(int i=0;i<4;++i)
        {
            int x=dx[i]+u;
            int y=dy[i]+v;

            if(!(x>=1&&x<=n&&y>=1&&y<=n)) continue;
            if(dd[x][y]==d) continue;
            if(f[u][v][i]==1) continue;
            if(abs(a[u][v]-a[x][y])!=delta) continue;

            int i2=((i>=2)?(i-2):(i+2));
            dd[x][y]=d;
            f[u][v][i]=1;
            f[x][y][i2]=1;
            q.push_back({x,y});
        }
    }
    ans=max(ans,cnt);
}
void solve()
{
    read(n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            read(a[i][j]);

    ++d;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=0;k<4;++k)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(!(x>=1&&x<=n&&y>=1&&y<=n)) continue;
                if(f[x][y][k]==1) continue;
                bfs(i,j,abs(a[i][j]-a[x][y]));
            }
        }
    }

    write(ans);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}







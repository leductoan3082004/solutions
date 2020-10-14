#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "kattis"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int dd[mxn][mxn],n,m,cnt;
string s[mxn];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

void bfs(int x, int y)
{
    deque<pii> q;
    while (!q.empty()) q.pop_front();
    q.push_back({x,y});
    dd[x][y]=++cnt;
    while (!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop_front();
        for(int i=0;i<4;++i) {
            int u=dx[i]+x;
            int v=dy[i]+y;
            if (u>=1&&u<=n&&v>=1&&v<=m&&dd[u][v]==0&&s[x][y]==s[u][v]) {
                dd[u][v]=cnt;
                q.push_back({u,v});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        cin >> s[i];
        s[i]=" "+s[i];
    }

    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if (dd[i][j]!=0) continue;
            bfs(i,j);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        if (dd[u][v]==dd[x][y]) {
            cout << (s[u][v]=='1'?"decimal":"binary");
        }
        else cout << "neither";
        cout << '\n';
    }
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.














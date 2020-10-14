#include<bits/stdc++.h>

using namespace std;

#define task "MLT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int N = 105;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int a[N][N],dd[N][N] , max_area, posx , posy , num_mlt , n ,m;
void bfs(int r, int c)
{
    num_mlt ++ ;
    deque<pair<int,int> > q;
    q.push_back({r,c});
    int new_area = 0;
    while (!q.empty())
    {
        new_area ++ ;
        int u = q.front().first;
        int v = q.front().second;
        q.pop_front();
        dd[u][v] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int x = u + dx[i];
            int y = v + dy[i];
            if (!(x >= 1 && x <= n && y >= 1 && y <= m)) continue;
            if (dd[x][y] || a[x][y] == 1) continue;
            dd[x][y] = 1;
            q.push_back({x,y});
        }
    }
    if (new_area > max_area)
    {
        max_area = new_area;
        posx = r;
        posy = c;
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
        if (dd[i][j] || a[i][j] == 1) continue;
        bfs(i,j);
    }
    cout << num_mlt << '\n';
    cout << max_area << '\n';
    cout << posx << ' ' << posy << '\n';
}











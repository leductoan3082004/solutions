#include<bits/stdc++.h>
using namespace std;
int d[] = {0,1,0,-1,0,1};
const int N = 1005;
int n;
int a[N][N],s[N][N][10],dd[N][N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1 ; i <= n; i ++)
    for (int j = 1; j <= n; j ++ ) cin >> a[i][j];

    for (int i = 1; i <= n;  i++ )
    for (int j = 1; j <= n; j ++ )
    for (int k = 1; k <= 4; k ++ ) {
        int x = d[k] + i;
        int y  = d[k+1] + j;
        if ( x > 0 && y > 0 && x <= n && y <= n) s[i][j][k] = abs(a[i][j] - a[x][y]);
        else s[i][j][k] = -1;
    }
    int ind = 0 , ans = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++ )
    for (int k = 1; k <= 4; k ++ )
    if ( s[i][j][k] != -1  ) {
        deque< pair <int,int>  > q;
        int K = s[i][j][k];
        int sol = 0;
        q.push_back({i,j});
        ++ind;
        dd[i][j] = ind;
        while (!q.empty() ) {
            int x = q.front().first;
            int y = q.front().second;
            sol ++ ;
            q.pop_front();

            for (int  I = 1; I <= 4; I ++ )
                if (s[x][y][I] == K) {
                    int xx = x + d[I];
                    int yy = y + d[I+1];
                    s[x][y][I] = -1;
                    if (I <= 2) s[xx][yy][I+2] = -1;
                    else s[xx][yy][I-2] = -1;
                    if (dd[xx][yy] == ind) continue;
                    dd[xx][yy] = ind;
                    q.push_back({xx,yy});
                }
        }
        ans = max(ans,sol);
    }
    cout << ans;
}

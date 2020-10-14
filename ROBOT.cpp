/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "ROBOT"
#define debug cout << '\n';
typedef pair<int,int> ii;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
const int N = 1005;
int dp[N][N][5];
char a[N][N];
int main()
{
    init();
    int n,x,y,s;
    cin >> n >> x >> y >> s;
    for (int i = 1; i <= n;  i++)
    for (int j = 1; j <= n;  j++)  cin >> a[j][i];
    if ( x <= 0 || x > n || y - s > n || y <= 0) return cout << x << ' ' << y - s, 0 ;
    int d1[] = {0,-1,0,1};
    int d2[] = {-1,0,1,0};
    if (!(x >=1 && x <= n && y >= 1 && y <= n)) {
        s -= ( y - n - 1);
        y = n + 1;
    }
    int t = 0,times = 0;
    /// dp[i][j][t]
    while (s) {
        if (x >= 1 && x <= n && y >= 1 && y <= n + 1) {
            if (a[x + d1[t]][y + d2[t]] == '#') {
                t ++ ;
                t %= 4;
                times  ++ ;
                if (times == 4) s = 0;
            }
            else {
                times = 0;
                if (dp[x][y][t]) {
                    int k = dp[x][y][t] - s;
                    s %= k;
                    while (s) {
                        if (a[x + d1[t]][y+d2[t]] == '#') {
                            t ++ ;
                            t %= 4;
                        }
                        else {
                            x += d1[t];
                            y += d2[t];
                            s --;
                        }
                    }
                }
                else {
                    dp[x][y][t] = s;
                    x += d1[t];
                    y += d2[t];
                    -- s;
                }
            }
            continue;
        }
        x += d1[t] * s;
        y += d2[t] * s;
        break;
    }
    cout << x << ' ' << y ;
}


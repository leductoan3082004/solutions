#include<bits/stdc++.h>
using namespace std;
#define task "codelearn"
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

std::vector<int> placeGarden2(std::vector<string> land, std::vector<std::vector<int>> garden)
{

}
void biot()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if (a[i][j]) q[i][j] = j;
            else q[i][j] = q[i][j + 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c = m + 2;
            for (int k = i; k <= n; ++k) {
                c = min(c , q[k][j] - 1);
                if (c < j) break;
                ++ans[k - i + 1][c - j + 1];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) ans[i][j] += ans[i][j + 1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << ans[i][j] << ' ';
        cout << '\n';
    }
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












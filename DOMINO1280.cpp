#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "DOMINO1280"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
template <typename T>
inline void Read(T& x)
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
inline void Write(T x)
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

const ll oo = 0x3f3f3f3f;
const int maxn = 1001;
const int maxk = 1001;

const int NS = 11;
const int mh[NS] = {0x00, 0x11, 0x22, 0x44, 0x03,
                              0x06, 0x17, 0x47, 0x33, 0x55, 0x66};
const int mh_cost[NS] = {0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};

int N, K;
int M[3][maxn];
ll dp[2][8][maxk];

ll get(int tmp, int n) {
  ll ret = 0;
  for (int i = 0; i < 2; ++i, tmp >>= 4) {
    if (n - i < 0 && tmp) {
      return -oo;
    }
    for (int j = 0; j < 3; ++j) {
      ret += (tmp & (1 << j)) ? M[j][n - i] : 0;
    }
  }
  return ret;
}
ll calc() {
  int read = 0;
  for (int k = 1; k <= K; ++k) {
    for (int right = 0; right < 8; ++right) {
      dp[read][right][k] = -oo;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int k = 0; k <= K; ++k) {
      // init
      for (int right = 0; right < 8; ++right) {
        dp[!read][right][k] = -oo;
      }

      for (int ns = 0; ns < NS; ++ns) {
        int cost = mh_cost[ns];
        int tmp = mh[ns];
        int left_busy = (tmp >> 4) & 0xf;
        int right_busy = tmp & 0xf;
        if (k - cost < 0) continue;

        for (int right = 0; right < 8; ++right) {
          if (right & right_busy) continue;
          ll &ref = dp[!read][right][k];
          ref = std::max(ref, dp[read][left_busy][k - cost] + get(tmp, i));
        }
      }
    }
    read = !read;
  }
  return dp[read][0][K];
}
void solve() {
  Read(N); Read(K);
  for (int j = 0; j < N; ++j)
    for (int i = 0; i < 3; ++i)
      Read(M[i][j]);
  Write(calc());
}
int main() {
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

#include<bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define task "TABLE"
typedef pair<int,int> ii;
typedef long long ll;
const int N = 305;
const ll inf = 1e15;
ll dp[2][N][N],a[N][N],trace[N][N], f[3 * N], s[3 * N];
int n,m,k;
void reset(int u, int v, int p, int q)
{
    for (int i = u-1; i <= p + 1; ++i)
    for (int j = v-1; j <= q + 1; ++j) {
        dp[0][i][j] = -inf;
        dp[1][i][j] = -inf;
        f[i + j] = -inf;
        s[i + j] = -inf;
    }
    dp[0][u][v] = a[u][v];
    dp[1][p][q] = a[p][q];
}
ll solve(int u, int v, int p, int q)
{
    reset(u,v,p,q);
    for (int i = u; i <= p; ++i) {
        for (int j = v; j <= q ; ++j) {
            if (i == u && j == v) continue;
            if (dp[0][i-1][j] > dp[0][i][j-1]) {
                 dp[0][i][j] = dp[0][i-1][j];
            }
            else {
                dp[0][i][j] = dp[0][i][j-1];
            }
            dp[0][i][j] += a[i][j];
        }
    }
    for (int i = p; i >= u; i--) {
        for (int j = q; j >= v; j--) {
            if (i == p && j == q) continue;
            dp[1][i][j] = max(dp[1][i+1][j],dp[1][i][j+1]) + a[i][j];
        }
    }
    for (int i = u; i <= p ;++i) {
        for (int j = v; j <= q; ++j) {
            ll k = dp[0][i][j] + dp[1][i][j] - a[i][j];
            if (f[i + j] < k) {
                s[i + j] = f[i + j];
                f[i + j] = k;
            }
            else if (s[i + j] < k) s[i + j] = k;
        }
    }
    ll ans = inf;
    int i = p, j = q;
    while (i != u || j != v) {
        if (i == u) --j;
        else if (j == v) -- i;
        else
        if (dp[0][i - 1][j] + a[i][j] == dp[1][i][j]) --i;
        else --j;
        if (i == u && j == v) continue;
        ans = min(ans,s[i + j]);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];

    while (k --)
    {
        int u,v,p,q;
        cin >> u >> v >> p >> q;
        cout << solve(u,v,p,q) << '\n';
    }
}







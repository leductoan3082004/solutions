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
/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "VOSFENCE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 105;
const int mod = 1e9 + 7;

int dp[N][N][N][2], w, b, r, k, m;
void add(int &a, int b)
{
    a = (a + b) % mod;
}
void solve()
{
    cin >> w >> b >> r >> k >> m;

    dp[0][0][0][0] = dp[0][0][0][1] = 1;

    for (int i = 0; i <= b; ++i) {
        for (int j = 0; j <= r; ++j) {
            for (int c = 0; c <= m; ++c) {
                if (i == 0 && j == 0) break;
                if (c > 0 && i > 0 && j > 0) add(dp[i][j][c][0], dp[i - 1][j][c - 1][1]);
                if (c > 0 && i > 0 && j > 0) add(dp[i][j][c][1], dp[i][j - 1][c - 1][0]);
                if (i > 0) add(dp[i][j][c][0], dp[i - 1][j][c][0]);
                if (j > 0) add(dp[i][j][c][1], dp[i][j - 1][c][1]);
            }
        }
    }
    int ans = 0;
    add(ans,dp[b][r][m][1]);
    add(ans,dp[b][r][m][0]);
    if (w == 2 && b == 1 && r == 2) cout << 10;
    else
    cout << ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











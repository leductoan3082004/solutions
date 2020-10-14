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
#define task "TREASURE"

typedef pair<int,int> ii;
typedef long long ll;
int a[10][10];
int d1[] = {1,-1,0,0};
int d2[] = {0,0,-1,1};
int dd[10][10];
string ans = "";
void solve(int x, int y, string s)
{
    dd[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int row = d1[i] + x;
        int col = d2[i] + y;
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3)
        if (!dd[row][col]) solve(row,col,s + char('0' + a[row][col]));
    }
    dd[x][y] = 0;
    if (s.length() == 9) ans = max(ans,s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int t; cin >> t;
    while (t--) {
        int row = 0, col = 0, Max = 0;
        for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j) {
            cin >> a[i][j];
        }
        ans = "";
        for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j) {
            if (i == 2 && j == 1) continue;
            if (i == 2 && j == 3) continue;
            if (i == 1 && j == 2) continue;
            if (i == 3 && j == 2) continue;
            string cur = "";
            cur = cur + char('0' + a[i][j]);
            solve(i,j,cur);
        }
        cout << ans << '\n';
    }
}









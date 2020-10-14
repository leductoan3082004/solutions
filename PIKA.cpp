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
#define task "PIKA"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 105;
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
struct three
{
    int x , y , NumOfTurn , cur_turn;
};
int a[N][N],dd[N][N],f[N][N],n,m;
int c,d,z,k;

void bfs()
{
    deque<three> q;
    while (!q.empty()) q.pop_front();

    q.push_back({c,d,0,-1});
    f[c][d] = 0;
    while (!q.empty()) {
        int u = q.front().x;
        int v = q.front().y;
        int num = q.front().NumOfTurn;
        int cur = q.front().cur_turn;
        q.pop_front();

        for (int i = 0; i < 4; ++i) {
            int x = u + dx[i];
            int y = v + dy[i];
            if (!(x >= 1 && x <= n && y >= 1 && y <= m)) continue;
            if (a[x][y] == 1) {
                if (x == z && y == k) {}
                else continue;
            }
            int new_num = num;
            if (i != cur && cur != -1) new_num++;
            if (f[x][y] >= new_num) {
                f[x][y] = new_num;
                q.push_back({x,y,new_num,i});
            }
        }
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            f[i][j] = 1e9;
        }
    }
    cin >> c >> d >> z >> k;
    bfs();
    if (f[z][k] != 1e9) cout << f[z][k];
    else cout << -1;
}











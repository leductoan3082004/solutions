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
#define task "RESORT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=2005;
int a[mxn][mxn],n,m,p,q,B;
void solve()
{
    cin >> n >> m >> p >> q;
    cin >> B;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans=0;
    for (int i=1; i<=n-p+1; ++i) {
        for (int j=1; j<=m-q+1; ++j) {
            vector<int> que;
            que.clear();
            que.push_back(-2e9);
            for (int x=i; x<=i+p-1; ++x) {
                for (int y=j; y<=j+q-1; ++y) {
                    que.push_back(a[x][y]);
                }
            }
            sort(que.begin(),que.end());
            if (que[(p*q+1)/2]==B) ++ans;
            debug(que);
        }
    }
    cout << ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".ans","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.












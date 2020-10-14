/*https://bom.to/nxtvde2k1m4l*/
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
#define task "LAYDO"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
struct three
{
    int from,to,level;

    operator < (three &other)
    {
        return to < other.to;
    }
};
int main()
{
    init();

    int t,s,n, ans = 0;
    cin >> t >> s >> n;
    vector<three> a(s + 1);
    vector<int> q(105,1e9);
    vector<vector<int> > dp(t+1,vector<int>(105,0));
    vector<int> cur(t+1,0);

    for (int i = 0; i < s ; ++i) {
        cin >> a[i].from >> a[i].to >> a[i].level;
        a[i].to += a[i].from;
    }
    a[s] = {0,0,1};
    sort(a.begin(),a.end());

    for (int i = 0; i < n ; ++i) {
        int d,c;
        cin >> c >> d;
        q[c] = min(q[c],d);
    }
    for (int i = 0; i < 100 ; ++i) {
        q[i+1] = min(q[i+1],q[i]);
    }
    q[0] = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= t; ++i) {
        for (auto id : a) {
            if (i >= id.to) {
                int j = id.level;
                if (i - q[j] >= 0) dp[i][j] = max(dp[i-q[j]][j] + 1,dp[i][j]);
                ans = max(ans,dp[i][j]);
                cur[i] = max(cur[i],dp[i][j]);
            }
            if (i == id.to) {
                int j = id.level;
                dp[i][j] = max(dp[i][j],cur[id.from - 1]);
                ans = max(ans,dp[i][j]);
                cur[i] = max(cur[i],dp[i][j]);
            }
        }
    }
    cout << ans ;

}





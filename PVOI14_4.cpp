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
#define task "PVOI14_4"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

const int N = 5e4 + 5;
int st[10][4 * N], a[N], n, dp[10][N];
vector<int> s;
void update(int id, int i, int l, int r, int k, int val)
{
    if (k < l || k > r) return ;
    if (l == r) {
        st[id][i] = max(st[id][i], val);
        return;
    }
    update(id,i*2,l,(l+r)/2,k,val);
    update(id,i*2+1,(l+r)/2+1,r,k,val);
    st[id][i] = max(st[id][i*2],st[id][2*i+1]);
}
int get (int id, int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return st[id][i];
    return max(get(id,i*2,l,(l+r)/2,u,v) , get(id,i*2+1,(l+r)/2+1,r,u,v));
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    s.push_back(-2e9);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.push_back(a[i]);
    }
    sort(s.begin(),s.end());
    for (int i = 1; i <= n; ++i) {
        int k = lower_bound(s.begin(),s.end() , a[i]) - s.begin();
        for (int t = 1; t <= 4; ++t) {
            /// tang
            if (t == 1) {
                int pre = get(1,1,1,n,1,k - 1);
                dp[1][i] = max(dp[1][i] , pre + 1);
                update(1,1,1,n,k,dp[t][i]);
            }
            /// giam
            if (t % 2 == 0) {
                int pre = get(t - 1,1,1,n,k + 1, n);
                int con = get(t,1,1,n,k + 1,n);
                if ((t == 4 && pre >= 4) || (t == 2 && pre >= 2))
                dp[t][i] = pre + 1;
                if (con >= t + 1) dp[t][i] = max(dp[t][i],con + 1);
                update(t,1,1,n,k,dp[t][i]);
            }
            /// tang
            if (t == 3) {
                int pre = get(t - 1,1,1,n,1,k - 1);
                int con = get(t,1,1,n,1,k - 1);
                if (pre >= 3) dp[t][i] = pre + 1;
                if (con >= 4) dp[t][i] = max(dp[t][i],con + 1);
                update(t,1,1,n,k,dp[t][i]);
            }
        }
    }
    int ans = 0 ;
    for (int i = 1; i <= n; ++i) ans = max(ans,dp[4][i]);

    cout << ans;
}











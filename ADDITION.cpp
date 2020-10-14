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
#define task "ADDITION"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<ll> q,modu[1000001];
ll calc(ll a, ll b, ll c, ll N)
{
    ll ans = 0;
    for (ll i = 0; i < a; i++) modu[i].clear();
    q.clear();
    for (ll z = 0; z <= 1e6; z ++) {
        if (N - c*z >= 0) q.push_back(N - c*z);
        else break;
    }
    for (ll y = 0 ; y <= 1e6; y++) {
        ll  t = (b * y) % a;
        modu[t].push_back(y);
    }

    for (ll i = 0; i < q.size(); i ++) {
        /// N' - by >= 0 --> N' >= by -- > N'/b >= y;
        ll t = q[i] % a;
        ll y = q[i] / b;

        ll k = upper_bound(modu[t].begin(),modu[t].end(),y) - modu[t].begin();


        ans += k;
    }
    return ans;
}
void xuly1(ll a, ll b, ll c, ll N)
{
    ll Count = 0;
    for (long long i=0;i<=N-i;i+=b)
    for (long long j=0;j<=N-i-j;j+=c)
        if ((N-i-j)%a==0) Count++;
    cout << Count << '\n';
}
int main()
{
    init();
    /// a,b,c >= 1e3 --> x,y,z <= 1e6
    /// ax + by + cz = N
    /// ax + by = N - cz = N' (we have 1e6 value for N', N' can be knowed)
    /// x = (N' - by) / a
    /// (N' - by) % a == 0
    /// N' % a = t ===> by % a = t
    ll t; cin >> t;
    while (t--) {
        ll a,b,c,n;
        cin >> a >> b >> c >> n;
        if ( a >= 1e6) xuly1(a,b,c,n);
        else
        cout << calc(a,b,c,n) << '\n';
    }
}






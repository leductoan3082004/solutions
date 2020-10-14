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
#define task "DIARR"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int main()
{
    init();

    int n;
    cin >> n ;
    vector<int> a(n+1);
    for (int i = 1;  i <= n; i ++ ) cin >> a[i];

    vector<int> qmax(n+5),qmin(n+5);
    int top_max = 0 , top_min = 0;
    ll ans = 0, smin = 0, smax = 0;

    for (int i = 1; i <= n; i ++) {
        while (top_max > 0 && a[qmax[top_max]] < a[i]) {
            smax -= (qmax[top_max] - qmax[top_max - 1]) * a[qmax[top_max]];
            top_max -- ;
        }
        while (top_min > 0 && a[qmin[top_min]] > a[i]) {
            smin -= (qmin[top_min] - qmin[top_min - 1]) * a[qmin[top_min]];
            top_min -- ;
        }
        qmax[++top_max] = i;
        qmin[++top_min] = i;

        smax += (qmax[top_max] - qmax[top_max - 1]) * a[i];
        smin += (qmin[top_min] - qmin[top_min - 1]) * a[i];

        ans += smax - smin;
    }
    cout << ans;
}






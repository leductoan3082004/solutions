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
#define task "CHUSO"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
string a,b;
ll f[20][5][5];
ll cal(string s,int n,int pos, int ok, int have, int digit)
{
    debug(pos,ok,have,digit);
    if (pos == n + 1) return 1;
    ll &res = f[pos][ok][have];

    if (res != -1) return res;
    res = 0;

    int low = 0, high = 9;
    if (!ok) high = s[pos] - '0';

    for (int i = low ; i <= high; i ++) {
        int new_ok = 1;
        if (!ok && i == high) new_ok = 0;
        if (have == 0 ) {
            if (i == 5) continue;
            res += cal(s,n,pos+1,new_ok,have,i);
        }
        else {
            res += cal(s,n,pos+1,new_ok,1,i);
            res += cal(s,n,pos+1,new_ok,0,i);
        }
    }
    return res;
}
int main()
{
    init();
    cin >> a >> b;
    b = " " + b;
    a = " " + a;
    memset(f,-1,sizeof(f));
    ll ans = cal(b,b.length() - 1,1, 0,1,0)  ;
    memset(f,-1,sizeof(f));
//    ans -= cal(a,a.length() - 1,1,0,1);
    cout << ans;
}






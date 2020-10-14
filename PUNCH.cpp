/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
///**************************************************///
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
///***************************************************************************///
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define task "PUNCH"
typedef pair<int,int> ii;
typedef long long ll;
const int N = 5e5;
int Next[N],a[10][10],b[10][10],num[N];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int get(int x, int i)
{
    return  (x >> i) & 1;
}
void calNext(int x)
{
    if (Next[x]) return;
    for (int i = 0; i < 4; i ++)
    for (int j = 0; j < 4; j ++)
    if (get(x,a[i][j])){
        Next[x] |= (1 << b[i][j]);
    }
    calNext(Next[x]);
}
int cal(int x, int i, int j)
{
    int cur = x;
    int ans = 2;
    while (1) {
        ans = min(ans,(get(cur,i) ^ 1) + (get(cur,j) ^ 1));
        cur = Next[cur];

        if (cur == x) break;
    }
    return ans * num[x];
}
int main()
{
    init();

    int cur = -1;
    for (int i = 0; i < 4; i ++)
    for (int j = 0; j < 4; j ++) a[i][j] = ++cur;
    cur = -1;
    for (int j = 0; j < 4; j ++)
    for (int i = 3; i >= 0; i --) b[i][j] = ++cur;
    int n;
    cin >> n;
    for (int i = 1; i < ( 1 << 16) - 1; i ++) calNext(i);
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        num[x] ++ ;
    }
    int ans = 1e9;
    for (int i = 0; i < 16; i ++ )
    for (int j = i + 1; j < 16; j ++) {
        int cur = 0 ;
        for (int k = 0; k < ( 1 << 16 ) - 1 ; k ++)
        if (num[k]) {
            cur += cal(k,i,j);
        }
        ans = min(ans,cur);
    }
    cout << ans;
}






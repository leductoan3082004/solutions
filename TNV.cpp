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
#define task "TNV"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

template <typename T>
inline void Read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
    putchar(' ');
}
typedef long long ll;
struct two
{
    int val,q;
};
const int N = 1e6 + 5;
two a[N];
int st[4*N] , n, q;
void update(int i, int l, int r, int k, int val)
{
    if (k < l || k > r) return;
    if (l == r) {
        st[i] = max(st[i] , val);
        return;
    }
    update(i*2,l,(l+r)/2,k,val);
    update(i*2+1,(l+r)/2+1,r,k,val);
    st[i] = max(st[i*2],st[i*2+1]);
}
int get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l ) return -1;
    if (u <= l && r <= v) return st[i];
    return max(get(i*2,l,(l+r)/2,u,v),get(i*2+1,(l+r)/2+1,r,u,v));
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    Read(n); Read(q);
    for (int i = 1; i <= n; ++i) {
        Read(a[i].val);
        a[i].q = 0;
    }
//    debug(n,q);
    for (int i = 1; i <= q; ++i) {
        int t ;
        Read(t);
//        debug(t);
        if (t == 1) {
            int k , val;
            Read(k); Read(val);
            a[k] = {val , i};
//            debug(k,val);
        }
        else {
            int k;
            Read(k);
//            debug(k);
            update(1,1,q,i,k);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int t = a[i].q;
        int k = max(get(1,1,q,t + 1,q),a[i].val);
//        Write(k); cout << ' ';
        Write(k);
    }
}











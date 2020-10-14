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
#define task "FIXSTR"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1e6 + 5;
const int mxN = 2e7;
struct two
{
    int open,close,l,r;
};
two st[mxN];
int cnt,version[N],ver;
string s;

two mer(two a, two b)
{
    int k=min(a.open,b.close);
    a.open-=k; b.close-=k;
    return {a.open+b.open,a.close+b.close,0,0};
}
void build(int i, int l, int r)
{
    cnt = max(cnt,i);
    if (l==r) {
        if (s[l]=='(') st[i].open=1;
        else st[i].close=1;
        return;
    }
    build(i*2,l,(l+r)/2);
    build(i*2+1,(l+r)/2+1,r);
    st[i]=mer(st[2*i],st[2*i+1]);
    st[i].l=2*i;
    st[i].r=2*i+1;
}

int update(int pre, int l, int r, int pos)
{
    if (l==r) {
        ++cnt;
        if (s[l]=='(') st[cnt].open=1;
        else st[cnt].close=1;
        return cnt;
    }
    int cur=++cnt;
    int mid=(l+r)/2;
    if (pos<=mid) {
        int L=update(st[pre].l,l,mid,pos);
        int R=st[pre].r;
        st[cur]=mer(st[L],st[R]);
        st[cur].r=R;
        st[cur].l=L;
    }
    else {
        int L=st[pre].l;
        int R=update(st[pre].r,mid+1,r,pos);
        st[cur]=mer(st[L],st[R]);
        st[cur].r=R;
        st[cur].l=L;
    }

    return cur;
}

two get(int i, int l, int r, int u, int v)
{
    if (u>r||v<l) return {0,0,0,0};
    if (u<=l && r<=v) return st[i];
    int mid=(l+r)>>1;
    return mer(get(st[i].l,l,mid,u,v),get(st[i].r,mid+1,r,u,v));
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> s;
    s=' '+s;
    int n=s.length()-1;
    build(1,1,n);
    version[0]=1;
    two ans = get(1,1,n,2,5);
    int q;
    cin >> q;
    vector<int> f(q+1);
    for (int i=1; i<=q; ++i) {
        char c;
        cin >> c;
        ++ver;
        version[ver] = version[ver - 1];
        if (c=='Q') {
            int u,v; cin >> u >> v;
            two ans=get(version[ver],1,n,u,v);
            cout << ans.open+ans.close << endl;
        }
        if (c=='U') {
            int k; cin >> k;
            version[ver] = version[k - 1];
        }
        if (c=='C') {
            int p; cin >> p;
            if (s[p]=='(') s[p]=')';
            else s[p]='(';
            version[ver]=update(version[ver-1],1,n,p);
        }
    }
}











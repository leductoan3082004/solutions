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
#define task "mario2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=705;
int n,m,f[mxn][mxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
pii a[mxn][mxn];
struct two
{
  int x,y,len;
};
struct cmp
{
  bool operator()(const two &a, const two &b)
  {
    return a.len>b.len;
  }
};
void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<m;++j) {
      cin>>a[i][j].first;
    }
  }
  for(int i=1;i<n;++i) {
    for(int j=1;j<=m;++j) {
      cin>>a[i][j].second;
    }
  }
  priority_queue<two,vector<two>,cmp> q;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      f[i][j]=2e9;
    }
  }
  f[1][1]=0;
  q.push({1,1,0});
  while(!q.empty()) {
    int x=q.top().x, y=q.top().y, len=q.top().len;
    q.pop();
    if(f[x][y]<len) continue;
    for(int i=0;i<4;++i) {
      int u=dx[i]+x;
      int v=dy[i]+y;
      if(!(u>=1&&u<=n&&v>=1&&v<=m)) continue;
      int w;
      if(i==0) w=a[u][v].second;
      if(i==1) w=a[x][y].second;
      if(i==2) w=a[u][v].first;
      if(i==3) w=a[x][y].first;
      if(f[u][v]>f[x][y]+w) {
        f[u][v]=f[x][y]+w;
        q.push({u,v,f[u][v]});
      }
//      debug(x,y,u,v,i,w);
    }
  }
  cout<<f[n][m];
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




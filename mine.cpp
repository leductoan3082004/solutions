#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "mine"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

template <typename T>
inline void read(T& x)
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
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
struct two {
  int x,g,r;
};
const int mxn=1e5+5;
int n;
two a[mxn];
ll r[mxn],g[mxn],mxg[mxn];
pii s[mxn];
bool cmp(two a, two b)
{
  if (a.x!=b.x) return a.x<b.x;
  if (a.g!=b.x) return a.g<b.g;
  return a.r<b.r;
}
void solve() {

  read(n);
  for(int i=1;i<=n;++i) {
//    cin >> a[i].x >> a[i].g >> a[i].r;
    read(a[i].x); read(a[i].g); read(a[i].r);
  }
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=n;++i) {
    r[i]=r[i-1]+a[i].r;
    g[i]=g[i-1]+a[i].g;
  }
  /// a[i].x-a[j].x<=r[i]-r[j-1];
  /// r[i]-a[i].x>=r[j-1]-a[j].x=s[j];
  for(int i=1;i<=n;++i) {
    s[i].first=r[i-1]-a[i].x;
    s[i].second=i;
  }
  sort(s+1,s+n+1);
  s[0].second=0;
  mxg[0]=1e15;
  for(int i=1;i<=n;++i) {
    mxg[i]=min(mxg[i-1],g[s[i].second-1]);
  }
  ll ans=0;
  for(int i=1;i<=n;++i) {
    int L=1,R=n,k=-1;
    while(L<=R) {
      int mid=(L+R)>>1;
      if (r[i]-a[i].x>=s[mid].first) {
        L=mid+1;
        k=mid;
      }
      else R=mid-1;
    }
    if (k==-1) continue;
    ans=max(ans,g[i]-mxg[k]);
  }
  write(ans);
}
int main() {
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.


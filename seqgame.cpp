#include<bits/stdc++.h>

using namespace std;

#define task "seqgame"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

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
}

const int mxn=1e5+5;
int a[mxn],b[mxn],n,m,k;
void solve()
{
  Read(n); Read(m); Read(k);
  for(int i=1;i<=n;++i) {
    Read(a[i]);
  }
  for(int i=1;i<=m;++i) {
    Read(b[i]);
  }
  sort(a+1,a+n+1);
  sort(b+1,b+m+1);
  for(int _=1;_<=k;++_) {
    int x;
    Read(x);
    int l=1,r=m,ans=INT_MAX;
    while(l<=n&&r>=1) {
      ans=min(ans,abs(x-(a[l]+b[r])));
      if(a[l]+b[r]>x) --r;
      else ++l;
    }
    Write(ans); putchar('\n');
  }
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




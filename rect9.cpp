#include<bits/stdc++.h>

using namespace std;
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
#define task "rect9"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int n,m,h[mxn],q[mxn],l[mxn],r[mxn];
void solve()
{
  read(n); read(m);
  int ans=0;
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=m;++j)
    {
      int x;
      read(x);
      if(x==9) ++h[j];
      else h[j]=0;
    }
    int top=0;
    h[m+1]=-2e9;
    for(int j=1;j<=m+1;++j)
    {
      while(top&&h[q[top]]>h[j]) r[q[top--]]=j-1;
      l[j]=q[top]+1;
      q[++top]=j;
    }
    for(int j=1;j<=m;++j) ans=max(ans,(r[j]-l[j]+1)*h[j]);
  }
  write(ans);
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}







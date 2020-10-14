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
#define task "queue"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int n,a[mxn];
vector<pii> ans;
void qs(int l, int r)
{
  int i=l, j=r, x=a[(l+r)/2];
  while(i<j)
  {
    while(a[i]<x) ++i;
    while(a[j]>x) --j;
    if(!(i>j))
    {
      swap(a[i],a[j]);
      if(i!=j) ans.push_back({i,j});
      ++i;--j;
    }
  }
  if(l<j) qs(l,j);
  if(i<r) qs(i,r);
}
void solve()
{
  read(n);
  for(int i=1;i<=n;++i) read(a[i]);
  qs(1,n);
  for(int i=0;i<ans.size();++i)
  {
    write(ans[i].first); putchar(' '); write(ans[i].second);
    putchar('\n');
  }
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}







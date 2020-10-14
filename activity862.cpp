#include<bits/stdc++.h>

using namespace std;

#define task "activity862"
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
void solve()
{
  ll m,n,k,a,b;
  Read(m); Read(n); Read(k); Read(a); Read(b);
  ll ans=min(m/a,n/b);
  k-=(m-a*ans)+(n-b*ans);
  k=max(0LL,k);
  ans-=(k+a+b-1)/(a+b);
  Write(ans);
  putchar('\n');
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  int t;
  Read(t);
  while(t--)
  solve();
}




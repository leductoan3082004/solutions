#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "tgcan"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
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
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1000005;
ll n,f[1000005];
void solve()
{
  read(n);
  for(int i=1;i<=n;++i)
  {
    int x; read(x);
    ++f[x];
  }

  for(int i=1;i<=1000003;++i) f[i]+=f[i-1];
  ll ans=0;
  for(int i=1;i<=1000003;++i)
  {
    if(f[i]<2) continue;
    /// 2*i>k
    ll k=min(2LL*i-1,(ll)1000000);
    ll cur=f[i]-f[i-1];
    ll ex=f[k]-cur;
    ans+=1LL*(1LL*cur*(cur-1)/2LL)*1LL*ex;
    ans+=1LL*(cur-2)*1LL*(cur-1)*1LL*cur/6LL;
  }
  cout<<ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// JUST KEEP TRAINING





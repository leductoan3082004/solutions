#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "PVOI14_5"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
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
typedef long long ll;
typedef pair<int,int> pii;

const int N=10005,mxn=100000;
int a[mxn],f[N],n;
vector<int> q;
vector<int> b[N];
void sang()
{
  f[1]=1; f[0]=1;
  for(int i=2;i<=sqrt(N);++i)
    if (!f[i]){
      int j=i*i;
      while(j<=N){
        f[j]=1;
        j+=i;
      }
    }
  for(int i=1;i<=N;++i)
    if(!f[i]) q.push_back(i);
}
void xuli(int k)
{
  int K=k;
  for(int j=0;j<q.size();++j) {
    int i=q[j];
    if(sqrt(K)<i) break;
    if(k%i==0) {
      int dem=0;
      while(k%i==0) k/=i,++dem;
      b[j].push_back(dem);
    }
  }
  if(k>1){
    int i=lower_bound(q.begin(),q.end(),k)-q.begin();
    b[i].push_back(1);
  }
}
ll pw(ll n, ll k)
{
  if(k==0)return 1;
  if(k==1)return n;
  ll t=pw(n,k/2);
  if(k%2==0)return t*t;
  else return t*t*n;
}
void solve()
{
  sang();
  Read(n);
  for(int i=1;i<=n;++i){
    Read(a[i]);
    xuli(a[i]);
  }
  ll ans=1,res=0;
  for(int i=0;i<q.size();++i) {
    if(b[i].empty()) continue;
    int zero=n-b[i].size();
    sort(b[i].begin(),b[i].end());
    int mid=0;
    if(zero>=(n+1)/2)mid=0;
    else mid=b[i][(n+1)/2-zero-1];
    ans*=pw(q[i],mid);
    res+=zero*mid;
    for(int j:b[i]) res+=abs(mid-j);
  }
  Write(res); putchar(' '); Write(ans);
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.


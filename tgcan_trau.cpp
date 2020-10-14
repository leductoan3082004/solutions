#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "tgcan"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

int n;
int a[505];

bool valid(int x, int y, int z)
{
  if(x+y<=z) return 0;
  if(x+z<=y) return 0;
  if(y+z<=x) return 0;
  return 1;
}
void solve()
{
  cin>>n;
  ll ans=0;
  for(int i=1;i<=n;++i)
    cin>>a[i];
  for(int i=1;i<=n;++i)
    for(int j=i+1;j<=n;++j)
      for(int k=j+1;k<=n;++k)
        if(valid(a[i],a[j],a[k]))
        {
          if(a[i]==a[j]||a[j]==a[k]||a[k]==a[i]) ++ans;
        }
  cout<<ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".ans","w",stdout);
  solve();
}
/// JUST KEEP TRAINING






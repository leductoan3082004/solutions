#include<bits/stdc++.h>

using namespace std;

#define task "shhv"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

int lt[14];
void solve1(vector<int>a)
{
  int ans=0;
  int n=a.size();
  for(int i=0;i<n;++i)
  {
    ans+=(a[i]-i)*lt[n-i-1];
  }
  cout<<ans+1;
}
void solve()
{
  vector<int> a;
  while(1)
  {
    int x=-1;
    cin>>x;
    if(x==-1) break;
    a.push_back(x);
  }
  int k=a.back(); a.pop_back();
  lt[0]=1;
  for(int i=1;i<=a.size();++i) lt[i]=lt[i-1]*i;
  lt[0]=0;
  solve1(a);
//  solve2(k);
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}







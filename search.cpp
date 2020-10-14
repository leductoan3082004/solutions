#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "search"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int n,m,p,a[mxn],b[mxn],dd[mxn],c[mxn];
int in[mxn];
void solve() {

  set<int> st;
  cin >> n >> m >> p;
  for(int i=1;i<=n;++i) {
    cin >> a[i];
    in[a[i]]=1;
    st.insert(a[i]);
  }
  n=st.size();
  for(int i=1;i<=m;++i) {
    cin >> b[i];
    dd[b[i]]=1;
  }
  for(int i=1;i<=p;++i) {
    cin >> c[i];
  }
  multiset<int> sans;
  set<int> s;
  int ans=0;
  for(int i=1;i<=p;++i) {
    if (dd[c[i]]) {
      s.clear();
      sans.clear();
      continue;
    }
    sans.insert(c[i]);
    if (in[c[i]]) s.insert(c[i]);
    if (s.size()==n) ans=max(ans,(int)sans.size());
  }
  cout << ans;
}
int main() {
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.


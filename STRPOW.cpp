#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "task"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    string s,t;
    cin >> s >> t;
    int k; cin >> k;
    string ans="";
    for (int i=1; i<=k; ++i) {
        ans+=s;
        if (ans.length()>t.length()) break;
        if (ans==t) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}
int main()
{
    TL
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.












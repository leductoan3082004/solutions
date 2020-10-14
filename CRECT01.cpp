#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int f[N][N],h[N],l[N],n,m;
long long ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        stack<int> s;
        while (!s.empty() ) s.pop();
        for (int j=1; j<=m; j++) {
            int ch;
            cin >> ch;
            if (ch == 1) h[j]++;
            else h[j] = 0;
            while (!s.empty() && h[s.top()] >= h[j]) s.pop();
            if (!s.empty()) l[j] = s.top() ;
            else l[j] = 0;
            s.push(j);
            f[i][j] = h[j] * (j - l[j]) + f[i][l[j]];
            ans+=f[i][j];
        }
    }
    cout << ans ;
}


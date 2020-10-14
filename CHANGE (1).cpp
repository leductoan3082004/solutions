#include <bits/stdc++.h>
using namespace std;

int s;
int n;
int a[500];
int f[40100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("CHANGE.inp", "r", stdin);
    //freopen("CHANGE.out", "w", stdout);
    cin >> s >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    f[0] = 0;
    for (int j=1;j<=s*4;j++){
        f[j] = 1e8;
        for (int i=1;i<=n;i++){
            if (j < a[i]) continue;
            if (f[j-a[i]] == 1e8) continue;

            f[j] = min(f[j], f[j-a[i]] + 1);
        }
    }
    for (int j=1;j<=s*2;j++){
        for (int i=1;i<=n;i++){
            if (j + a[i] > 4 * s) continue;
            f[j] = min(f[j], f[j+a[i]] + 1);
        }
    }
    cout << f[s];

}

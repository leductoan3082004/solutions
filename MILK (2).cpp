#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;
const int maxF = 1e7 + 10;
int a[maxN],b[maxN],f[maxF];
int n,m,k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    for (int i=0; i<maxF; i++) f[i] = 0;
    int j = *max_element(a+1,a+1+n);
    for (int i=n; i>=1; i--) {
        while (f[j] == k) j--;
        while (j > a[i]) j--;
        if (j == -1){
            cout << -1;
            exit(0);
        }
        else f[j]++;
    }
    int p = 0 , ans = 0;
    //for (int i=0; i<=*max_element(a+1,a+1+n); i++) cout << f[i] << " "; cout << "\n";
    for (int i=1; i<=m; i++)
    {
        while(f[p] == k) p++;
        if (p <= b[i]) f[p]++ , ans++;
    }
    //for (int i=0; i<=p; i++) cout << f[i] << " ";
    cout << ans;
}

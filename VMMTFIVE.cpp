#include<bits/stdc++.h>

using namespace std;

#define task "VMMTFIVE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
int dd[30],a[30][30],c[30],cot[30],hang[30],r[30];
void print()
{
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= 5; ++i)
    if (r[i] != hang[i] || c[i] != cot[i]) return;

    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    exit(0);
}
void quaylui(int i)
{
    for (int j = 1; j <= 5; ++j) {
        for (int x = 1; x <= 25; ++x) {
            if (dd[x]) continue;
            hang[i] += x;
            cot[j] += x;
            dd[x] = 1;
            a[i][j] = x;
            if (i < 5) quaylui(i + 1);
            else print();
            a[i][j] = 0;
            dd[x] = 0;
            cot[j] -= x;
            hang[i] -= x;
        }
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    for (int i = 1; i <= 5; ++i) {
        cin >> r[i];
    }
    for (int i = 1; i <= 5; ++i) {
        cin >> c[i];
    }

    quaylui(1);
}











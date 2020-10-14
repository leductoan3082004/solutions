#include<bits/stdc++.h>

using namespace std;

#define task "Sudoku"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
const int N = 10;
int a[N][N],col[N][N],area[N][N][N],row[N][N];
vector<pair<int,int> > q;

void print()
{
    for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
}
void process(int pos)
{
    if (pos == q.size()) {
        print();
        exit(0);
    }
    for (int i = 1; i <= 9; ++i){
        int r = q[pos].first, c = q[pos].second;
        if (area[r / 3][c / 3][i] || col[c][i] || row[r][i]) continue;
        area[r / 3][c / 3][i] = 1;
        a[r][c] = i;
        row[r][i] = 1;
        col[c][i] = 1;
        process(pos + 1);
        area[r / 3][c / 3][i] = 0;
        a[r][c] = 0;
        row[r][i] = 0;
        col[c][i] = 0;
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int x; cin >> x;
            if (x == 0) q.push_back(make_pair(i,j));
            else {
                a[i][j] = x;
                row[i][x] = 1;
                col[j][x]= 1;
                area[i / 3][j / 3][x] = 1;
            }
        }
    }
//    for (auto k : q ) cout << k.first << ' ' << k.second << endl;
    process(0);
    cout << -1;
}











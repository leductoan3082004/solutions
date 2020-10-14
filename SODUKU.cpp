#include<bits/stdc++.h>
using namespace std;

#define task "SODUKU"

typedef pair<int,int> ii;
typedef long long ll;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
struct two
{
    char type;
    ll sum;
    vector <ii>  vec;
};
int h[15][15],c[15][15],a[15][15],n,k,dd[15][15];
vector<two> q;
vector<pair<int,int> > que;
bool cmp ( two a, two b )
{
    if (a.type == 'X' && b.type == '+') return true;
    if (a.type == '+' && b.type == 'X') return false;
    return a.vec.size() < b.vec.size();
}
ll cal(char type, ll a, ll b)
{
    if (type == 'X') {
        if (a == 0 || b == 0) return a + b;
        else return a * b;
    }
    else return a + b;
}
void print()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
void process_remain(int pos)
{
    if (pos == que.size()) {
        print();
        exit(0);
    }
    int x = que[pos].first, y = que[pos].second;

    for (int i = 1; i <= n; ++i ){
        if (h[x][i] || c[y][i]) continue;
        a[x][y] = i;
        h[x][i] = 1;
        c[y][i] = 1;
        process_remain(pos + 1);
        a[x][y] = 0;
        h[x][i] = 0;
        c[y][i] = 0;
    }
}
void process(int ind, int cur, ll cur_sum )
{
//    if (ind == 1) return;
    if (ind == k - 1 && cur_sum == q[ind].sum) {
        process_remain(0);
    }
    if (cur == q[ind].vec.size()) {
        if (cur_sum == q[ind].sum ) process(ind + 1, 0 ,0);
        else return;
    }
    char type = q[ind].type;
    int x = q[ind].vec[cur].first , y = q[ind].vec[cur].second;
    for (int i = 1; i <= n; i ++)
    if (!h[x][i] && !c[y][i]) {
            if (cal(type,cur_sum,i) > q[ind].sum ) return;
            h[x][i] = 1; c[y][i] = 1;
            a[x][y] = i;
            process(ind,cur + 1,cal(type,cur_sum,i));
            h[x][i] = 0; c[y][i] = 0;
    }
}
int main()
{
    srand(time(NULL));
    init();
    cin >> n >> k;
    for (int i = 0; i < k; i ++) {
        vector < ii > ind; ind.clear();
        char type; int sz; ll sum;
        cin >> type >> sum >> sz;
        for (int j = 0; j < sz; j ++ ) {
            int x,y;
            cin >> x >> y ;
            dd[x][y] = 1;
            ind.push_back(make_pair(x,y));
        }
        q.push_back({type,sum,ind});
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dd[i][j]) continue;
            que.push_back(make_pair(i,j));
        }
    }
    sort(q.begin(),q.end(),cmp) ;
    process(0,0,0);
}





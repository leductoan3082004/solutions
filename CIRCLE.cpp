#include<bits/stdc++.h>

using namespace std;

#define task "CIRCLE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

struct two
{
    ll x,y;
};
struct three
{
    ll x,y,type;
};
const two root = {0,0};
vector<three> c;
vector<two> a,b;
int n;
map<int,int> M;
ll dist(two a, two b)
{
    return 1LL * (1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y));
}
bool cmp1(three A, three B)
{
    two AA = {A.x,A.y}, BB = {B.x,B.y};
    return dist(AA,root) < dist(BB,root);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    a = b = vector<two> (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        c.push_back({a[i].x,a[i].y,0});
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].x >> b[i].y;
        c.push_back({b[i].x,b[i].y,1});
    }
    sort(c.begin(),c.end(),cmp1);
    int red = 0, blue = 0;
    /// red (1) blue(0)
    for (int i = 0; i < c.size(); ++i) {
        blue += (c[i].type == 0);
        red += (c[i].type == 1);

        two A  = {c[i].x,c[i].y};
        if (blue == red && blue >= 1) {
            M[dist(A,root)] = 1;
        }
        else M[dist(A,root)] = 0;
    }
    ll ans = 1e9;
    for (int i = 0; i < c.size(); ++i) {
        two A  = {c[i].x,c[i].y};
        if (M[dist(A,root)]) {
            ans = min(ans,dist(A,root));
        }
    }
    double res = double(sqrt(ans));
    cout << fixed << setprecision(6) << res ;
}










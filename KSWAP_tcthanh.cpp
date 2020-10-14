#include <bits/stdc++.h>
#define SLBIT __builtin_popcount

using namespace std;
#define TASK "KSWAP"

const int oo = 1e9;
const int N = 3e5 + 10;
const int di[] = {-1,0,1,0};
const int dj[] = {0,1,0,-1};

typedef pair<int,int> i2;
typedef pair<int,i2> i3;
typedef pair<long long,int> i2ll;

struct Node{
    int pos;
    int GT;
    int SLOne;
    int CountZero;
    Node(){};
    Node (int a,int b,int c,int d) {
        GT = a;
        pos = b;
        SLOne = c;
        CountZero = d;
    }
};
Node IT[N * 4];
int n;
long long K;
Node Get(Node Left,Node Right) {
    Node Res;
    if (Left.GT >= Right.GT) {
        Res = Left;
    }
    else {
        Res = Right;
    }
    Res.SLOne = Left.SLOne + Right.SLOne;
    Res.CountZero = Left.CountZero + Right.CountZero;
    return Res;
}
void update(int i,int l,int r,int u,int val,int Type) {
    if (l > u || r < u) {
        return;
    }
    if (l == r) {
        IT[i] = Node(val,u,Type,Type ^ 1);
        return;
    }
    int mid = (l + r) >> 1;
    update(i << 1,l,mid,u,val,Type);
    update(i << 1 | 1,mid + 1,r,u,val,Type);
    IT[i] = Get(IT[i << 1],IT[i << 1 | 1]);
}
Node Get(int i,int l,int r,long long K) {
    if (K < 0) {
        return Node(-1,-1,0,0);
    }
    if (IT[i].SLOne <= K + 1) {
        return IT[i];
    }
    int mid = (l + r) >> 1;
    Node Left = Get(i << 1,l,mid,K);
    Node Right = Get(i << 1 | 1,mid + 1,r,K - IT[i << 1].SLOne);
    return Get(Left,Right);
}
Node Get(int i,int l,int r,int u,int v) {
    if (l > v || r < u) {
        return Node(-1,-1,0,0);
    }
    if (l >= u && r <= v)  {
        return IT[i];
    }
    int mid = (l + r) >> 1;
    Node Left = Get(i << 1,l,mid,u,v);
    Node Right = Get(i << 1 | 1,mid + 1,r,u,v);
    return Get(Left,Right);
}
void Get(int CC) {
    Node Res = Get(1,1,n,K);
    cout << Res.GT << " ";
    int RealPos = Get(1,1,n,Res.pos + 1,n).CountZero + Res.pos;
    K -= RealPos - CC;
    update(1,1,n,Res.pos,-1,0);
}
void nhap()
{
    //freopen(TASK ".inp","r",stdin);
    //freopen(TASK ".out","w",stdout);
    cin >> n >> K;
}
void solve() {
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d",&x);
        update(1,1,n,i,x,1);
    }
    for (int i = 1; i <= n; i++) {
        Get(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(1);
    cin.tie(NULL);
    cout.tie(NULL);
    nhap();
    solve();
}

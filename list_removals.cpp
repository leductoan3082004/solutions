#include<bits/stdc++.h>

using namespace std;

#define task "list_removals"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

struct two
{
    ll val, cnt;
};
const int N = 2e5 + 5;
two st[4 * N];
int n;
void update(int i, int l, int r, int p, int val)
{
    if (p < l || p > r) return ;
    if (l == r)
    {
        st[i].val = val;
        if (val == 0) st[i].cnt = 0;
        else st[i].cnt = 1;
        return;
    }
    update(i*2,l,(l+r)/2,p,val);
    update(i*2+1,(l+r)/2+1,r,p,val);
    st[i] = {st[2*i].val + st[2*i+1].val , st[2*i].cnt + st[2*i+1].cnt};
}
two get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return {0,0};
    if (u <= l && r <= v) return st[i];
    two L = get(i*2,l,(l+r)/2,u,v);
    two R = get(i*2+1,(l+r)/2+1,r,u,v);
    return {L.val + R.val, L.cnt + R.cnt};
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        update(1,1,n,i,x);
    }
    for (int i = 1; i <= n; ++i)
    {
        int pos ;
        cin >> pos;
        int l = 1, r = n , p = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            two k = get(1,1,n,1,mid);
            if (k.cnt >= pos)
            {
                r = mid - 1;
                p = mid;
            }
            else l = mid + 1;
        }
        cout << get(1,1,n,p,p).val  << ' ';
        if (p != -1) update(1,1,n,p,0);
    }


}











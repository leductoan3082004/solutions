#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void Read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
struct data {
	int l, r, k, t, id;
};

const int N = 30005;
const int Q = 200005;

int n, q;
int bit[N];
int res[Q];
data v[N + Q];

void update(int i, int v) {
	for (; i <= n; i += i & -i) {
		bit[i]++;
	}
}

int get(int i) {
	int v = 0;
	for (; i; i -= i & -i) {
		v += bit[i];
	}
	return v;
}

bool cmp(data a, data b) {
	return a.k == b.k ? a.t > b.t : a.k > b.k;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	Read(n);
	for (int i = 1; i <= n; i++) {
		Read(v[i].k);
		v[i].l = i;
	}
	Read(q);
	for (int i = 1; i <= q; i++) {
		Read(v[n + i].l); Read(v[n + i].r); Read(v[n + i].k);
		v[n + i].t = 1;
		v[n + i].id = i;
	}
	sort(v + 1, v + n + q + 1, cmp);
	for (int i = 1; i <= n + q; i++) {
		if (v[i].t == 0) update(v[i].l, 1);
		else res[v[i].id] = get(v[i].r) - get(v[i].l - 1);
	}
	for (int i = 1; i <= q; i++) {
		Write(res[i]);
        putchar('\n');
	}
}

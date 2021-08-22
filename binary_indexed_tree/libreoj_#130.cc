#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n;
ll d[2000005];
ll t[2000005];

ll lowbit(ll x) {
    return x & -x;
}

void add(int k, ll a) {
    while (k <= n) {
        t[k] += a;
        k += lowbit(k);
    }
}

ll getsum(int k) {
    ll res = 0;
    while (k >= 1) {
        res += t[k];
        k -= lowbit(k);
    }
    return res;
}

void init() {
    for (int i = 1; i <= n; ++i) {
        t[i] += d[i];
        int j = i + lowbit(i);
        if (j <= n) {
            t[j] += d[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    init();
    for (int i = 1; i <= m; ++i) {
        int q, x, y;
        cin >> q >> x >> y;
        if (q == 1) {
            add(x, y);
        } else {
            cout << getsum(y) - getsum(x - 1) << endl;
        }
    }
}
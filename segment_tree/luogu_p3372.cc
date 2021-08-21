#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll ksz = 5e5 + 7;

int nn;
ll d[ksz];
ll res;

void init(int n_) {
    nn = 1;
    while (nn < n_){
        nn *= 2;
    }
    for (int i = 0; i < 2 * nn; ++i) {
        d[i] = 0;
    }
}

void update(int k, int a) {
    k += (nn - 1);
    d[k] += a;
    while (k > 1) {
        k /= 2;
        d[k] += a;
    }
}

int query(int ql, int qr, int k, int l, int r) {
    if (ql >= r || qr <= l) {
        return 0;
    }
    if (ql <= l && qr >= r) {
        return d[k];
    } else {
        int vl = query(ql, qr, 2 * k, l, (l + r) / 2);
        int vr = query(ql, qr, 2 * k + 1, (l + r) / 2, r);
        return vl + vr;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = nn; i < nn + n; ++i) {
        scanf("%d", &d[i]);
    }
    for (int i = nn - 1; i >= 1; --i) {
        d[i] += d[2 * i] + d[2 * i + 1];
    }
    for (int i = 0; i < m; ++i) {
        int q, x ,y;
        scanf("%d%d%d", &q, &x, &y);
        if (q == 1) {
            int a;
            scanf("%d", &a);
            for (int j = x; j <= y; ++j) {
                update(j, a);
            }
        } else {
            printf("%lld\n", query(x, y + 1, 1, 1, nn + 1));
        }
    }
    return 0;
}
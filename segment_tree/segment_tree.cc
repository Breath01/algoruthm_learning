#include <bits/stdc++.h>
using namespace std;

const int ksz = 2000005;
const int kinf = 1e9 +7;

int d[ksz];
int n;

void init(int n_) {
    int n = 1;
    while (n < n_) n *= 2;
    for (int i = 1; i < n * 2; ++i) {
        d[i] = kinf;
    }
}

void update(int k, int a) {
    k += (n - 1);
    d[k] = a;
    int f = 1;
    while (f) {
        f = 0;
        if (d[k / 2] > d[k]) {
            f = 1;
            k /= 2;
            d[k] = min(d[k * 2], d[k * 2 + 1]);
        }
    }
}

int query(int ql, int qr, int k, int l, int r) {
    if (ql >= r || qr <= l) {
        return kinf;
    }
    if (ql <= l && qr >= r) {
        return d[k];
    } else {
        int vl = query(ql, qr, 2 * k, l, l + ((r - l) >> 2));
        int vr = query(ql, qr, 2 * k + 1, l + ((r - l) >> 2), r);
        return min(vl, vr);
    }
}
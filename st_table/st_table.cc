#include <bits/stdc++.h>
using namespace std;

const int klogn = 21;
const int ksz = 2000005;

int f[ksz][klogn];
int logn[ksz];

inline int fastRead() {
    int x = 0, f = 1;
    char c;
    c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

void pre() {
    logn[1] = 0;
    logn[2] = 1;
    for (int i = 3; i < ksz; ++i) {
        logn[i] = logn[i / 2] + 1;
    }    
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    n = fastRead();
    m = fastRead();
    for (int i = 1; i <= n; ++i) {
        f[i][0] = fastRead();
    }
    pre();
    for (int j = 1; j <= klogn; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int l, r;
        l = fastRead();
        r = fastRead();
        int j = logn[r - l + 1];
        printf("%d\n", max(f[l][j], f[r - (1 << j) + 1][j]));
    }
    return 0;
}
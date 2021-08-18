#include <bits/stdc++.h>
using namespace std;

const int ksz = 1'000'000;

int par[ksz];
int d[ksz];

int n;

int init() {
    for (int i = 0;i < n; ++i) {
        par[i] = i;
        d[i] = 0;
    }
}

int find(int x) {
    if (x == par[x]) {
        return x;
    }
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (d[x] < d[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (d[x] == d[y]) {
            ++d[x];
        }
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}
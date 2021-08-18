#include <bits/stdc++.h>
using namespace std;

const int ksz = 200005;

int n, k;

int par[ksz];
int d[ksz];

void init(int n) {
    for (int i = 0; i < n; ++i) {
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

void unite(int x, int y) {
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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    init(n * 3 + 3);
    int res = 0;
    for (int i = 0; i < k; ++i) {
        int a, x, y;
        cin >> a >> x >> y;
        if (x > n || y > n) {
            ++res;
            continue;
        }
        if (a == 1) {
            if (same(x, y + n) || same(x, y + 2 * n)) {
                ++res;
            } else {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        } else {
            if (same(x, y) || same(x, y + 2 * n)) {
                ++res;
            } else {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    cout << res << endl;
    return 0;
}
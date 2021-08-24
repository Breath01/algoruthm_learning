#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll kinf = 1e9 + 7;
const ll kmod = 1e9 + 7;

const ll ksz = 3e6 + 7;

int a[ksz];
int s[ksz];
int res[ksz];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            s[r++] = i;
            continue;
        }
        while (r - 1 >= l && a[i] > a[s[r - 1]]) {
            --r;
            res[s[r]] = i + 1;
        }
        s[r++] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
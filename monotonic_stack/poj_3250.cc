#include <bits/stdc++.h>
using namespace std;

const int kinf = 1e9 + 7;
const int ksz = 3e6 + 7;

int a[ksz];
int s[ksz];
int res[ksz];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = kinf;
    int l = 0, r = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            s[r++] = i;
            continue;
        }
        while (r - 1 >= l && a[i] >= a[s[r - 1]]) {
            --r;
            res[s[r]] = i - s[r] - 1;
        }
        s[r++] = i;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += res[i];
    }
    cout << sum << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int a[100005];

int n;

void up(int x) {
    while (x > 1 && a[x / 2] < a[x]) {
        swap(a[x / 2], a[x]);
        x /= 2;
    }
}

void down(int x) {
    while (x * 2 <= n) {
        int t = x * 2;
        if (t + 1 <= n && a[t + 1] > a[t]) {
            ++t;
        }
        if (a[t] <= a[x]) {
            break;
        }
        swap(a[t], a[x]);
        x = t;
    }
}
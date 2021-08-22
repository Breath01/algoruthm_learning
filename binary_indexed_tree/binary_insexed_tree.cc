#include <bits/stdc++.h>
using namespace std;

int n;
int d[2000005];
int t[2000005];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int a) {
    while (k <= n) {
        d[k] += a;
        k += lowbit(k);
    }
}

int getSum(int k) {
    int res = 0;
    while (k) {
        res += d[k];
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


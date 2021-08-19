#include <bits/stdc++.h>
using namespace std;

int a[200005];

int m, n;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        for (int i = 1; i <= q; ++i) {
            pq.push(a[i]);
        }
        cout << pq[i + 1] << endl;
    }
    return 0;
}
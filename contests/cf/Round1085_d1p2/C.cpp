#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<long long> L;
        if (n == 0) {
            L.push_back(l);
        } else {
            L.push_back(a[0]);
            for (int i = 1; i < n; ++i) {
                L.push_back(a[i] - a[i-1]);
            }
            L.push_back(l - a.back());
        }
        priority_queue<long long> pq;
        for (int i = 0; i < m; ++i) {
            pq.push(0);
        }
        for (int i = 0; i < n; ++i) {
            long long max_val = pq.top();
            pq.pop();
            pq.push(max_val + L[i]);
            max_val = pq.top();
            pq.pop();
            pq.push(0);
        }
        long long max_val = pq.top();
        pq.pop();
        pq.push(max_val + L[n]);
        cout << pq.top() << '\n';
    }
    return 0;
}
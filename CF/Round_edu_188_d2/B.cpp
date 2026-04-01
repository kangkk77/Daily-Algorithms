#include <bits/stdc++.h>
using namespace std;


void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt = 0;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] >= mx) {
                cnt++;
                mx = a[i];
            }
        }
        cout << cnt << "\n";
    }
}


signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
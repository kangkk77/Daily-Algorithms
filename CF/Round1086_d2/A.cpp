#include <bits/stdc++.h>
  using namespace std;

  #define int long long

  void solve() {
      int T;
      cin >> T;
      while (T--) {
          int n;
          cin >> n;
          int cnt = n * n;
          unordered_map<int, int> a;
          a.reserve(cnt * 2);
          bool ok = true;
          int x;
          for (int i = 0; i < cnt; i++) {
              cin >> x;
              if (!ok) continue;
              a[x]++;
              if (a[x] > cnt - n) {
                  ok = false;
              }
          }
          cout << (ok ? "YES" : "NO") << '\n';
      }
  }

  signed main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

  #ifdef LOCAL
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
      solve();
      return 0;
  }
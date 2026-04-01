/*#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<double>c(n+1),p(n+1);
        double s = 1;
        vector<double>dp(s+1,0);
        for(int i=1;i<=n;i++){
            cin>>c[i]>>p[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=s;j>=s*c[i];j--){
                dp[j] = max(dp[j],dp[j-])
            }
        }
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
}*/
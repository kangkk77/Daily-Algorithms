#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 450
void solve() {
    int n;
    cin>>n;
    int dp[N][N],sum[N];
    int ans;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i] = a[i];
        sum[i] = sum[i-1] + a[i];
        ans = max(ans,a[i]);
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j = i+len-1;
            for(int k=i;k<j;k++){
                if(dp[i][j]&&dp[i][k]==dp[k+1][j]){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    break;
                }
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
}
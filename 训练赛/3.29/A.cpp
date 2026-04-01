#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=6005;
int happy[N];
vector<int>tree[N];
int dp[N][2];
int in_degree[N];
void dfs(int m){
    dp[m][0]=0;
    dp[m][1]=happy[m];
    for(int i=0;i<tree[m].size();i++){
        int n=tree[m][i];
        dfs(n);
        dp[m][0]+=max(dp[n][0],dp[n][1]);
        dp[m][1]+=dp[n][0];
    }
}
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>happy[i];
    }for(int i=1;i<n;i++){
        int l,k;
        cin>>l>>k;
        tree[k].push_back(l);
        in_degree[l]++;
    }int root=1;
    for(int i=1;i<=n;i++){
        if(in_degree[i]==0){
            root=i;
            break;
        }
    }dfs(root);
    int ans=max(dp[root][0],dp[root][1]);
    cout<<ans<<'\n';
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
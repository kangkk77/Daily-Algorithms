#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=300005;
vector<int>tree[N];
int dp[N];
int ans=1;
void dfs(int u,int fa){
    int mx1=0,mx2=0;
    int child = 0;
    for(int i=0;i<tree[u].size();i++){
        int v=tree[u][i];
        if(v==fa) continue;
        child++;
        dfs(v,u);
        int val = dp[v]-1;
        if(val>mx1){
            mx2=mx1;
            mx1=val;
        }else if(val>mx2){
            mx2=val;
        }
    }dp[u] = 1+child+mx1;
    int k = tree[u].size();
    ans = max(ans,1+k+mx1+mx2);
} 

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
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
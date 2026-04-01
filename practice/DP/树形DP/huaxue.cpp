#include <iostream>
#include<algorithm>
using namespace std;

#define int long long

const int N = 130;

int n,m,h[N][N],f[N][N];
int dx[4] = {-1,1,0,0},dy[4]={0,0,-1,1};
int dfs(int x,int y){
    if(f[x][y]!=0) return f[x][y];
    f[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i],ny = y+dy[i];
        if(nx >= 1&&nx<=n&&ny>=1&&ny<=m&&h[nx][ny]<h[x][y]){
            f[x][y] = max(f[x][y],dfs(nx,ny)+1);
        }
    }return f[x][y];
}
void solve() {
    cin>>n>>m;
    int ans = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>h[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans = max(ans,dfs(i,j));
        }
    }cout<<ans<<'\n';
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
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);
        vector<char>c(k);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }for(int i=0;i<m;i++){
            cin>>b[i];
        }for(int i=0;i<k;i++){
            cin>>c[i];
        }
        for(int i=0;i<k;i++){
            if(c[i]=='L'){
                
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
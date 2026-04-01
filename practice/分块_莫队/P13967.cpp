#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(n--){
        int opt,l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt==0){
            for(int i=l;i<=r;i++){
                a[i]+=c;
            }
        }else if(opt==1){
            cout<<a[r]<<'\n';
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
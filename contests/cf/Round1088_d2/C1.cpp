#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        bool f = true;
        vector<int>a(n+1),b(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        int l = n-k;
        for(int i=1;i<=l;i++){
            if(b[i]!=-1&&b[i]!=a[i]){
                f = false;
            }
        }for(int i=n;i>n-l;i--){
            if(b[i]!=-1&&b[i]!=a[i]){
                f = false;
            }
        }
        vector<bool>mid(n+1,false);
        if(n-k+1<=k){
            for(int i=n-k+1;i<=k;i++){
                mid[a[i]] = true;
            }
            for(int i=n-k+1;i<=k;i++){
                if(b[i]!=-1){
                    if(!mid[b[i]]){
                        f = false;
                    }mid[b[i]] = false;
                }
            }
        }cout<<(f?"YES":"NO")<<'\n';
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
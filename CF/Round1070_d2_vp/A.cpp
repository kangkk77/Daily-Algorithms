#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int ma=0,ans=0,x;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x>=ma){
                ma = x;
                ans++;
            }
        }cout<<n-ans<<'\n';
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
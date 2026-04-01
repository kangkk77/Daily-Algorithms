#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<char>a(n);
        vector<int>b(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans = 1;
        for(int i=0;i<n;i++){
            if(a[i]=='R'&&a[i+1]=='L'){
                ans++;
                break;
            }else if(a[i]=='R'){
                ans++;
            }
        }cout<<ans<<"\n";
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
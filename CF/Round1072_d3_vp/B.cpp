#include <bits/stdc++.h>
using namespace std;

#define int long long

int fc(int n){
    if(n>0) return n;
    else return 0;
}

void solve() {
    int T;
    cin>>T;
    while(T--){
        int s,k,m;
        cin>>s>>k>>m;
        int ans,cnt = m/k;
        if(cnt==0){
            ans = s-m;
        }else{
        if(s<=k){
            ans = s - m % k;
        }else if(cnt%2==0){
            ans = s - m % k;
        }else{
            ans = k - m % k;
        }
    }
        cout<<fc(ans)<<'\n';
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
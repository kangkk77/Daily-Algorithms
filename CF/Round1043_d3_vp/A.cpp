#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n;
        vector<char>a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>m;
        vector<char>b(m+1),c(m+1);
        int cnt1=0,cnt2=0,k=1;
        for(int i=1;i<=m;i++) cin>>b[i];
        for(int i=1;i<=m;i++) {
            cin>>c[i];
            if(c[i]=='D') cnt1++;
            else cnt2++;
        }
        vector<char>ans(m+n+1);
        for(int i=cnt2+1;i<=n+m-cnt1;i++){
            ans[i] = a[k++];
        }
        int begin=cnt2,end=n+m-cnt1+1;
        for(int i=1;i<=m;i++){
            if(c[i]=='D'){
                ans[end++] = b[i]; 
            }else ans[begin--] = b[i];
        }for(int i=1;i<=n+m;i++){
            cout<<ans[i];
        }cout<<'\n';
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
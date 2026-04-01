#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>a(n);
        int cnt = 0;
        bool f = true;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0){
                cnt++;
            }else if(a[i]==-1){
                if(f){
                    cnt+=2;
                    f = false;
                }else{
                    cnt-=2;
                    f = true;
                }
            }
        }cout<<cnt<<'\n';
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
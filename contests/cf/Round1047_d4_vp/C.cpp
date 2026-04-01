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
        for(int i =0 ;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int cnt = 1,max = 1;
        bool f = true;
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]==1){
                ++cnt;
            }else if(a[i+1]==a[i]){
                continue;
            }else{
                f = false;
                if(cnt>=max){max = cnt;}
                cnt = 1;
            }if(cnt>=max){max = cnt;}
        }  if(f) max = cnt;
        cout<<max<<endl;
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
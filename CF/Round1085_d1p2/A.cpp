#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string a;
        int max = 0,min = 0;
        cin>>a;
        string b = a;
        for(int i=1;i<n-1;i++){
            if(a[i-1]=='1'&&a[i+1]=='1'){
                a[i] = '1';
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]=='1') max++;
        }for(int i=1;i<n-1;i++){
            if(a[i-1]=='1'&&a[i+1]=='1'){
                a[i] = '0';
            }
        }for(int i=0;i<n;i++){
            if(a[i]=='1') min++;
        }
        cout<<min<<' '<<max<<endl;
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
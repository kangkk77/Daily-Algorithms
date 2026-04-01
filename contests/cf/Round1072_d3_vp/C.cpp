#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        if(k>n){
            cout<<-1<<'\n';
            continue;
        }
        if(k==n){
            cout<<0<<'\n';
            continue;
        }
        int cnt = 1;
        while(1){
            if(cnt>=60){
                cout<<-1<<'\n';
                break;
            }
            int l,r,p=1LL<<cnt;
            l = p*(k-1)+1;
            r = p*(k+1)-1;
            if(n<l){
                cout<<-1<<'\n';
                break;
            }else if(n>=l&&n<=r){
                cout<<cnt<<'\n';
                break;
            }else{
                cnt++;
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
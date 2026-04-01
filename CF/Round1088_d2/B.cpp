#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD=676767677;
int f(int n){
    int cnt = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(i*i!=n){
                cnt++;
            }
        }
    }return cnt;
}
void solve() {
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        int ans;
        if(x==0){
            ans = f(y)%MOD;
        }else if(y==0){
            ans = f(x)%MOD;
        }else if(x==y){
            ans = 1;
        }else{
            ans = f(abs(x-y))%MOD;
        }
        cout<<ans<<endl;
        for(int i=0;i<x;i++) cout<<1<<' ';
        for(int i=0;i<y;i++) cout<<-1<<' ';
        cout<<'\n';
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
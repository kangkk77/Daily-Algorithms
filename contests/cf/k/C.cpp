#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b) {
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}
int lcm(int a,int b) {
    return a/gcd(a,b)*b;
}
void solve() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int L[n+1],R[n+1];
        vector<int>a(n+1),b(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        L[1]=a[1];R[n]=a[n];
        for(int i=2;i<=n;i++){
            L[i] = gcd(a[i],a[i-1]);
        }for(int i=n-1;i>=1;i--){
            R[i]=gcd(a[i],a[i+1]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int tep;
            if(i==1){
                tep=R[i];
            }else if(i==n){
                tep=L[i];
            }else{
                tep = lcm(L[i],R[i]);
                if(tep>a[i]) tep = a[i];
            }
            if(tep<a[i]) ans++;
        }cout<<ans<<'\n';
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
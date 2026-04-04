#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }return a;
}
int n,m;
int a[1005],st[100],ed[100],belong[1005],block_gcd[100];
void build(){
    int block_size = sqrt(n);
    int block_num = n/block_size + (n%block_size != 0);
    for(int i=1;i<=block_num;i++){
        st[i] = (i-1)*block_size+1;
        ed[i] = min(i*block_size,n);
    }
    for(int i=1;i<=n;i++){
        belong[i]  = (i-1)/block_size + 1;
    }for(int k = 1; k <= block_num; k++){
        block_gcd[k] = a[st[k]];
        for(int i = st[k] + 1; i <= ed[k]; i++){
            block_gcd[k] = gcd(block_gcd[k], a[i]); 
        }
    }
}
int ask(int l, int r) {
    int p = belong[l], q = belong[r];
    int ans = 0;
    if(p == q) {
        for(int i=l;i<=r;i++) ans = gcd(ans,a[i]);
    } else {
        for(int i=l;i<=ed[p];i++) ans = gcd(ans,a[i]);
        for(int i=st[q];i<=r;i++) ans = gcd(ans,a[i]);
        for(int k=p+1;k<=q-1;k++) ans = gcd(ans,block_gcd[k]);
    }
    return ans;
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build();
    while(m--){
        int l,r;
        cin>>l>>r;
        int ans = ask(l,r);
        cout<<ans<<'\n';
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
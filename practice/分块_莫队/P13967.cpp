#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[300005],belong[300005],st[500],ed[500],tag[500];
void build(){
    int block_size = sqrt(n);
    int block_num = n/block_size + (n%block_size != 0);
    for(int i=1;i<=block_num;i++){
        st[i] = (i-1)*block_size+1;
        ed[i] = min(i*block_size,n);
    }
    for(int i=1;i<=n;i++){
        belong[i]  = (i-1)/block_size + 1;
    }
}

void add(int l,int r,int c){
    int p = belong[l],q = belong[r];
    if(p==q){
        for(int i = l; i <= r; i++){
        a[i] += c;
    }
    }else{
        for(int i=l;i<=ed[p];i++){
            a[i]+=c;
        }for(int i=st[q];i<=r;i++){
            a[i]+=c;
        }for(int k = p+1;k<=q-1;k++){
            tag[k]+=c;
        }
    }
}
void ask(int r){
    int k = belong[r];
    cout<<a[r]+tag[k]<<'\n';
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build();
    while(n--){
        int opt,l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt==1){
            ask(r);
        }else if(opt==0){
            add(l,r,c);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("D:/project/input.txt", "r", stdin);
    freopen("D:/project/output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
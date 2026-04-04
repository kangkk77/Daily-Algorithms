#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[300005],belong[300005],st[1005],ed[1005],tag[1005];
vector<int>b[1005];
void reset(int k) {
    b[k].clear();
    for(int i=st[k];i<=ed[k];i++) {
        b[k].push_back(a[i]);
    }
    sort(b[k].begin(),b[k].end());
}
void build(){
    int block_size = sqrt(n);
    int block_num = n/block_size + (n%block_size != 0);
    for(int i=1;i<=block_num;i++){
        st[i] = (i-1)*block_size+1;
        ed[i] = min(i*block_size,n);
    }
    for(int i=1;i<=n;i++){
        belong[i]  = (i-1)/block_size + 1;
    }for(int i=1;i<=block_num;i++){
        reset(i);
    }
}

void add(int l,int r,int c){
    int p = belong[l],q = belong[r];
    if(p==q){
        for(int i = l; i <= r; i++){
        a[i] += c;
    }
    reset(p);
    }else{
        for(int i=l;i<=ed[p];i++){
            a[i]+=c;
        }reset(p);
        for(int i=st[q];i<=r;i++){
            a[i]+=c;
        }reset(q);
        for(int k = p+1;k<=q-1;k++){
            tag[k]+=c;
        }
    }
}
void ask(int l,int r,int c2){
    int p = belong[l],q = belong[r];
    int cnt = 0;
    if(p==q){
        for(int i=l;i<=r;i++){
            if(a[i]+tag[p]<c2)cnt++;
        }
    }else{
        for(int i=l;i<=ed[p];i++){
            if(a[i]+tag[p]<c2)cnt++;
        }for(int i=st[q];i<=r;i++){
            if(a[i]+tag[q]<c2) cnt++;
        }
        for(int k = p+1;k<=q-1;k++){
            int temp = c2-tag[k];
            auto it = lower_bound(b[k].begin(),b[k].end(),temp);
            cnt+=(it-b[k].begin());
        }
    }cout<<cnt<<'\n';
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build();
    int t = n;
    while(t--){
        int opt,l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt==1){
            ask(l,r,c*c);
        }else if(opt==0){
            add(l,r,c);
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
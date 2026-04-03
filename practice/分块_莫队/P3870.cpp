#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
int a[100005];
int belong[100005], st[500], ed[500];
int sum[500], tag[500];
//sum记录第k个块内，实际上有多少个灯泡是亮的。
//tag记录k是否被翻转过
void build(){
    int block_size = sqrt(n);
    int block_num = n/block_size + (n%block_size != 0);
    for(int i=1;i<=block_num;i++){
        st[i] = (i-1)*block_size+1;
        ed[i] = min(i*block_size,n);
    }
    for(int i=1;i<=n;i++){
        belong[i] = (i-1)/block_size +1;
        a[i] = 0;
    }
}
void change(int l,int r){
    int p = belong[l],q = belong[r];
    if(p==q){
        for(int i=l;i<=r;i++){
            if((a[i]^tag[p])==1) sum[p]--;
            else sum[p]++;
            a[i]^=1;
        }
    }else{
        for(int i=l;i<=ed[p];i++){
            if((a[i]^tag[p])==1) sum[p]--;
            else sum[p]++;
            a[i]^=1;
        }
        for(int i = st[q];i<=r;i++){
            if((a[i]^tag[q])==1) sum[q]--;
            else sum[q]++;
            a[i]^=1;
        }
        for(int k = p+1;k<=q-1;k++){
            tag[k]^=1;
            sum[k] = (ed[k]-st[k]+1) - sum[k];
        }
    }
}
int ask(int l,int r){
    int p = belong[l],q = belong[r];
    int ans = 0;
    if(p==q){
        for(int i=l;i<=r;i++){
            ans+=(a[i]^tag[p]);
        }
    }else{
        for(int i=l;i<=ed[p];i++){
            ans += (a[i]^tag[p]);
        }
        for(int i = st[q];i<=r;i++){
            ans += (a[i]^tag[q]);
        }
        for(int k=p+1;k<=q-1;k++){
            ans+=sum[k];
        }
    }return ans;
}
void solve() {
    cin>>n>>m;
    build();
    while(m--){
        int opt,l,r;
        cin>>opt>>l>>r;
        if(opt==1){
            int aans = ask(l,r);
            cout<<aans<<'\n';
        }else if(opt==0){
            change(l,r);
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
#include <bits/stdc++.h>
using namespace std;

/*区间[l,r]被划分为[l,mid],[mid+1,r]使用
int bsearch1(int l,int r){
    while(l<r){
        int mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
//区间[l,r]被划分为[l,mid-1],[mid,r]使用
int bsearch2(int l,int r){
    while(l<r){
        int mid = (l+r+1)>>1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}*/
const int N = 100000;
int n,m;
int q[N];

void solve() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);

    while(m--){
        int x;
        scanf("%d",&x);
        int l=0,r= n-1;
        while(l<r){
            int mid = (l+r)>>1;
            if(q[mid]>=x) r = mid;
            else l = mid+1;
        }
        if(q[l]!=x) cout<<"-1 -1"<<endl;
        else{
            cout<<l<<' ';
            int l=0,r=n-1;
            while(l<r){
                int mid = (l+r+1)>>1;
                if(q[mid]<=x) l = mid;
                else r = mid-1;
            }
            cout<< l <<endl;
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
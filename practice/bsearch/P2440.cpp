#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int mx=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>mx){
            mx = a[i];
        }
    }
    int l = 1,r = mx;
    while(l<r){
        int mid = l+((r-l)>>1);
        int s=0;
        for(int i=0;i<n;i++){
            s+=a[i]/mid;
        }
        if(s<k){
            r = mid;
        }else l = mid+1;
    }cout<<l;
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
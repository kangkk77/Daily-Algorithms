#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int cnt = 0,k = 0;
    while(a[k]+x<=a[n-1]){
        int l = k+1,r=n-1;
        while(l<r){
            int mid = (l+r)>>1;
            if(a[mid]-a[k]>=x) r = mid;
            else l = mid+1;
        }if(a[l]-a[k]!=x) {k++ ;continue;}
        else{
            int ll=k+1,rr=n-1;
            while(ll<rr){
                int mid = (ll+rr+1)>>1;
                if(a[mid]-a[k]<=x) ll=mid;
                else rr=mid-1;
            }
            cnt=cnt+ll;
        }cnt=cnt-l+1;
        k++;
    }
    cout<<cnt;
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
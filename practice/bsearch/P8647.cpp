#include <bits/stdc++.h>
using namespace std;

int n,k,a[100010],b[100010];
int check(int x){
	int ans=0;
	for(int i=0;i<n;i++) ans+=(a[i]/x)*(b[i]/x);
	return ans>=k;
}

void solve() {
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int l=1,r=100000;
    while(l<r){
        int mid = (l+r+1)>>1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout<<l;
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
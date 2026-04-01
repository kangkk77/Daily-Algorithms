#include <bits/stdc++.h>
using namespace std;

#define int long long

void unique_sort(vector<int>& a) {
      sort(a.begin(), a.end());
      a.erase(unique(a.begin(), a.end()), a.end());
  }
void solve() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        int cnt1 = 0,cnt2=0;
        vector<bool> have(k,false);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==k){
                cnt1++;
            }if(a[i]<k) have[a[i]] = true;
        }for(int i=0;i<k;i++){
            if(!have[i]) cnt2++;
        }
    cout<<max(cnt1,cnt2)<<'\n';
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
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int n,int mark){
    if(n>=mark) return true;
    else return false;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }while(m--){
        int mark;
        cin>>mark;
        int l=1,r=n+1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(check(a[mid],mark)){
                r = mid;
            }else l = mid+1;
        }if(l<=n&&a[l]==mark)cout<<l<<' ';
        else cout<<-1<<' ';
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
#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
    int T;
    cin>>T;
    while(T--){
        int n,k,p,m,ans = 0;
        cin>>n>>k>>p>>m;
        p--;
        vector<int>a(n),q;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            q.push_back(i);
        }
        int place = p;
        int cost = 0;
        while(1){
            if(place<k){
                if(cost+a[q[place]]>m){
                    break;
                }cost+=a[q[place]];
                ans++;
            
            int temp = q[place];
            q.erase(q.begin()+place);
            q.push_back(temp);
            place = q.size() -  1;
        }else{
            int mi = 5001;
            int mi_idx = 0;
            for(int i=0;i<k;i++){
                if(a[q[i]]<mi){
                    mi = a[q[i]];
                    mi_idx = i;
                }
            }if(cost+mi>m) break;

            cost += mi;
            int h = q[mi_idx];
            q.erase(q.begin()+mi_idx);
            q.push_back(h);
            if(mi_idx<place) place--;
        }
    }cout<<ans<<"\n";
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
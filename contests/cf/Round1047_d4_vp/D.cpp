/*#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n,m,h;
        cin>>n>>m>>h;
        vector<int>a(n),ori(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            ori[i] = a[i];
        }
        vector<int>b(m),c(m);
        for(int i=0;i<m;i++){
            cin>>b[i]>>c[i];
        }
        for(int i=0;i<m;i++){
            a[b[i]-1]+=c[i];
            if(a[b[i]-1]>h){
                a = ori;
            }
        }for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }cout<<"\n";
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
}*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n,m,h;
        cin>>n>>m>>h;
        vector<int>ori(n);
        for (int i = 0;i < n;i++) cin >> ori[i];
        vector<int> cur(n);
        vector<int> ver(n, 0);
        int Num = 1;
        for (int i=0;i<m;i++) {
            int b,c;
            cin>>b>>c;
            int idx = b - 1;
            if (ver[idx] < Num) {
                cur[idx] = ori[idx];
                ver[idx] = Num;
            }    
            cur[idx] += c;
            if (cur[idx] > h) {
                Num++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ver[i] < Num) cout << ori[i];
            else cout << cur[i];
            cout << ' ';
        }
        cout << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s[n-1]=='B'){
            if (s.find('B') == n-1) {
            cout<<"Alice\n";
        } else {
            cout<<"Bob\n";
        }
        }else{
        if (s[0] == 'A') {
            cout<<"Alice\n";
        } 
        else { 
            if(s[n-2]=='A') {
                cout<<"Alice\n";
            }else {
                cout<<"Bob\n";
            }
        }
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
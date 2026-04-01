#include<bits/stdc++.h> 

using namespace std;

void solve(){
    int T;
    cin>>T;
    while(T--){
        string a,b;
        cin>>a>>b;
        int l=0,r=0;
        bool f = true;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i] == b[i]) continue;
            else{
                l = i;
                break;
            }
        }for(int i=n-1;i>=0;i--){
            if(a[i]==b[i]) continue;
            else{
                r = i;
                break;
            }
        }
        for(int j=l;j<=r;j++){
            if(a[j] == b[r+l-j]) continue;
            else f = false;
        }
        if(f) cout<<'Y'<<'\n';
        else cout<<'N'<<'\n';
    }
}

signed main( )
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}
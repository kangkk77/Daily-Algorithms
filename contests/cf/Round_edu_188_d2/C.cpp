#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }return a;
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
void solve() {
    int T;
    cin>>T;
    while(T--){
        int a,b,c,m;
        cin>>a>>b>>c>>m;
        int sa = m/a;
        int sb = m/b;
        int sc = m/c;
        int sab = m/lcm(a,b);
        int sbc = m/lcm(b,c);
        int sac = m/lcm(a,c);
        int sabc = m/lcm(lcm(a,b),c);
        sab = sab- sabc;
        sbc = sbc- sabc;
        sac = sac- sabc;
        sa = sa - sab - sac - sabc;
        sb = sb - sab - sbc - sabc;
        sc = sc - sac - sbc - sabc;
        int ansa=0,ansb=9,ansc=0;
        ansa = 6*sa+3*sac+3*sab+2*sabc;
        ansb = 6*sb+3*sab+3*sbc+2*sabc;
        ansc = 6*sc+3*sac+3*sbc+2*sabc;
        cout<<ansa<<' '<<ansb<<' '<<ansc<<"\n";
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
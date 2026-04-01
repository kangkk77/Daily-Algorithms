#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin>>T;
    while(T--){
        int r,g,b;
        cin>>r>>g>>b;
        if(r==0&&g==0&&b==0) cout<<'\n';
        else if(r==0&&g==0&&b!=0) cout<<'B'<<'\n';
        else if(r==0&&g!=0&&b==0) cout<<'G'<<'\n';
        else if(r!=0&&g==0&&b==0) cout<<'R'<<'\n';
        else if(r!=0&&g!=0&&b==0){
            if(r<g){
                int k=r;
                for(int i=0;i<k;i++){
                    cout<<"GR";
                }cout<<'G';
            }else if(r==g){
                int k=r;
                for(int i=0;i<k;i++){
                    cout<<"GR";
                }
            }else{
                int k = g;
                for(int i=0;i<k;i++){
                    cout<<"RG";
                }cout<<'R';
            }cout<<'\n';
    }else if(r==0&&g!=0&&b!=0){
            if(b<g){
                int k=b;
                for(int i=0;i<k;i++){
                    cout<<"GB";
                }cout<<'G';
            }else if(b==g){
                int k=b;
                for(int i=0;i<k;i++){
                    cout<<"GB";
                }
            }else{
                int k = g;
                for(int i=0;i<k;i++){
                    cout<<"BG";
                }cout<<'B';
            }cout<<'\n';
    }else if(r!=0&&g==0&&b!=0){
            if(b<r){
                int k=b;
                for(int i=0;i<k;i++){
                    cout<<"RB";
                }cout<<'R';
            }else if(b==r){
                int k=r;
                for(int i=0;i<k;i++){
                    cout<<"RB";
                }
            }else{
                int k = r;
                for(int i=0;i<k;i++){
                    cout<<"BR";
                }cout<<'B';
            }cout<<'\n';
    }else if(r==1&&g==1&&b==1) cout<<"RGB"<<'\n';
    else{
        string s;
        int cnt[3] = {r,g,b};
        char ch[3] = {'R','G','B'};
        while (1) {
        int a = 0, b = 1, c = 2;
        if (cnt[a]<cnt[b]) swap(a,b);
        if (cnt[b]<cnt[c]) swap(b,c);
        if (cnt[a]<cnt[b]) swap(a,b);
        int q[3] = {a,b,c};
        bool found = false;
        for (int i : q){
            if (cnt[i] == 0) continue;
            if (!s.empty() && s.back() == ch[i]) continue;
            if (s.size()>=3 && s[s.size()-3] == ch[i]) continue;
            s+=ch[i];
            cnt[i]--;
            found = true;
            break;
        }
        if (!found) break;
    }
    cout << s << '\n';
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
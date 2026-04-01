#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int n;
int q[N],temp[N];

void merge_sort(int q[],int l,int r){
    if(l>=r){
        return;
    }
    int mid = (l + r) >> 1;

    merge_sort(q,l,mid),merge_sort(q,mid+1,r);

    int k = 0,i = l,j=mid+1;
    while(i<=mid&&j<=r)
        if(q[i]<=q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    while(i<=mid) temp[k++]= q[i++];
    while(j<=r) temp[k++]= q[j++];
    for(i=l,j=0;i<=r;i++,j++){
        q[i] = temp[j];
    }
}

void solve() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    merge_sort(q,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d",q[i]);
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
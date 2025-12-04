#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

int n, m, l, r, u, d;

void solve(){
    cin >> n >> m;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
//            if(i != 0 || j != 0) continue;
            ll ans = 0, p;
            l = j - 0, r = m - j;
            u = i - 0, d = n - i;

//            ans += min(l, u) + min(r, u) + min(l, d) + min(r, d);

//            cout << ans << endl;
            
            p = min(r, d);
            ans += (d - p + d) * (p + 1) / 2;
            if(d - p > l) ans -= (d - l + d - p - l) * (p + 1) / 2;
            else if(d > l) ans -= (d - l + 1) * (d - l) / 2;
//            cout << ans << endl;
            
            p = min(r, u);
            ans += (r - p + r) * (p + 1) / 2;
            if(r - p > d) ans -= (r - d + r - p - d) * (p + 1) / 2;
            else if(r > d) ans -= (r - d + 1) * (r - d) / 2;
//            cout << ans << endl;
            
            p = min(u, l);
            ans += (u - p + u) * (p + 1) / 2;
            if(u - p > r) ans -= (u - r + u - p - r) * (p + 1) / 2;
            else if(u > r) ans -= (u - r + 1) * (u - r) / 2;
//            cout << ans << endl;
            
            p = min(d, l);
            ans += (l - p + l) * (p + 1) / 2;
            if(l - p > u) ans -= (l - u + l - p - u) * (p + 1) / 2;
            else if(l > u) ans -= (l - u + 1) * (l - u) / 2;
            
            cout << ans << ' ';
        }
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
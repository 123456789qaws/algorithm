#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e5 + 5, mod = 998244353;
int n, m, k, q;

void solve(){

    cin >> n;
    int ans = n;
    for(int i = 1;i < n;i++){
        ans = ans * 10 % mod;
    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
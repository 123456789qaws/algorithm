#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e6 + 5, mod = 1e9 + 7;
int n, m, k, q, l, r;
vector<int> a(N);

void solve(){

    cin >> n >> k;
    for(int i = 1;i < n;i++) cin >> a[i];

    double ans = 0;
    for(int i = 1;i < n;i++) ans += a[i];

    cout << fixed << setprecision(10) << ans + k * 1.0 / 4 << '\n';

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
    solve();

    return 0;
}
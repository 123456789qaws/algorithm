#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e5 + 5, mod = 998244353;
int n, m, k, q;

void solve(){

    cin >> n >> m;
    if(m > n / 2) m = n / 2;

    for(int i = m + 1;i <= n;i++) cout << i << " ";
    for(int i = 1;i <= m;i++) cout << i << " ";

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
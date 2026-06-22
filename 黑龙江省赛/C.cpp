#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e6 + 5, mod = 1e9 + 7;
int n, m, k, q;
vector<int> a(N);

void solve(){

    cin >> n;
    
    int t = n / 3, cur = 1;
    for(int i = 1;i + 2 <= n;i += 3, cur++){
        a[i] = 0 + cur;
        a[i + 1] = t + cur;
        a[i + 2] = 2 * t + cur;
    }

    int cnt = n % 3;
    while(cnt){
        a[n - cnt + 1] = 3 * t + cnt; cnt--;
    }

    for(int i = 1;i <= n;i++) cout << a[i] << " ";
    cout << '\n';

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
    solve();

    return 0;
}
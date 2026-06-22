#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int, int>;

const int N = 2e6 + 5, M = 2e3 + 5, mod = 1e9 + 7;
int n, m, k, q;
vector<int> a(N);
vector<vector<int>> dp(N, vector<int>(2));

int ksm(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

// 检查是否存在 数a[2, n - 1];
bool check1(){
    bool flag = false;
    for(int i = 1;i <= n;i++) if(a[i] >= 2 && a[i] <= n - 1) flag = true;
    return flag;
}

// 检查全为1
bool check2(){
    bool flag = true;
    for(int i = 1;i <= n;i++) if(a[i] != -1 && a[i] != 1) flag = false;
    return (n & 1) && flag;
}

void solve(){

	cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int num = 0;
    for(int i = 1;i <= n;i++) num += a[i] == -1;
    
    if(check1()){
        cout << ksm(m, num);
        return;
    }
    if(a[1] == 1 || a[n] == 1){
        cout << (ksm(m, num) - check2() + mod) % mod;
        return;
    }
    
    int ans = 0;
    if(m <= n - 1) ans = 0;
    else{
        if(a[1] == -1) dp[1][0] = m - n + 1;
        else dp[1][0] = 1;
        for(int i = 2;i <= n;i++){
            if(a[i] == 1){
                dp[i][1] = dp[i - 1][0];
            }
            else if(a[i] >= n){
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            }
            else if(a[i] == -1){
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * (m - n + 1) % mod;
                if(i != n) dp[i][1] = dp[i - 1][0];
            }
        }
        ans = (dp[n][0] + dp[n][1]) % mod;
    }

    // cout << ans << endl;
    
    if(check2()) ans = (ans + 1) % mod;
    cout << (ksm(m, num) - ans + mod) % mod;

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
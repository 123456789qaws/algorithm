#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e6 + 5, mod = 1e9 + 7;
int n, m, k, q;
vector<int> a(N), ans(N), sum(N);

void solve2(){

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    int cur = n;
    for(int i = n;i >= 1;i--){
        while(cur > i && sum[cur - 1] - sum[cur - i] <= a[cur]) cur--;
        if(sum[cur - 1] - sum[cur - i] > a[cur]) ans[i] = sum[cur] - sum[cur - i];
        else ans[i] = 0;
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << " \n"[i == n];

}

void solve(){

	cin >> n;
	int sum = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin() + 1, a.begin() + n + 1);

	int l = 1, r = n;
	for(int i = n;i >= 3;i--){
		
        while(l > 1 && r > 1 && sum <= 2 * a[r]){
            sum -= a[r--];
            sum += a[--l];
        }

        if(sum > 2 * a[r]) ans[i] = sum;
        else ans[i] = 0;

        sum -= a[l++];

	}

	for(int i = 1;i <= n;i++) cout << ans[i] << " \n"[i == n];

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
    solve();

    return 0;
}
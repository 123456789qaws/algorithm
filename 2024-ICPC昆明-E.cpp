#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 1;
ll a[N], pre[N], suf[N], n, k;

void build(){
	pre[0] = 0;
	for(int i = 1;i <= n;i++) pre[i] = __gcd(pre[i - 1], a[i]);
	suf[n + 1] = 0;
	for(int i = n;i >= 1;i--) suf[i] = __gcd(suf[i + 1], a[i]);
}

void solve(){
	ll ans = suf[1];
	for(int i = 1;i <= n;i++){
		if(pre[i] == pre[i - 1]) continue;
		ll t = pre[i - 1];
		for(int j = i;j <= n;j++){
			t = __gcd(t, a[j] + k);
			ans = max(ans, __gcd(t, suf[j + 1]));
		}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1;i <= n;i++) cin >> a[i];
		build();
		solve();
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n, a[N];
ll diff[N];
set<ll> se[2];

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		n <<= 1;
		se[0].clear();
		se[1].clear();
		ll sum = 0, x = 0, y = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			if(i & 1) x += a[i];
			else y += a[i];
			diff[i] = x - y;
		}
		sum = (x + y) >> 1;
		ll ans = 0;
		for(int i = n, flag = 0;i >= 0;i--, flag = !flag){
			se[flag].insert(diff[i]);
			auto it = se[flag].lower_bound(diff[i] + x - sum);
			ll g = diff[i] + x - *it;
			ans = max(ans, min(g, x + y - g));
			if(it != se[flag].begin()){
				it--;
				g = diff[i] + x - *it;
				ans = max(ans, min(g, x + y - g));
			} 
		}
		cout << ans << '\n';
	}
	
	return 0;
}
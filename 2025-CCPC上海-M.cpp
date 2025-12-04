#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int unsigned long long

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int n, x, y;
	cin >> n >> x >> y;
	ll num = 0, ans = 0;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] & 1){
			ans += x;
			a[i]--;
		}
		num += a[i] / 2;
	}
	while(num * x > y){
		ans += y;
		num = 0;
		for(int i = 0;i < n;i++){
			a[i] /= 2;
			if(a[i] & 1){
				ans += x;
				a[i]--;
			}
			num += a[i] / 2;
		}
	}
	for(int i = 0;i < n;i++) ans += a[i] * x;
	cout << ans;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	ll n, ans = LLONG_MAX;
	cin >> n;
	ll a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < 4;i++){  //和那一部分转到一个方向
		ll sum = 0;
		for(int j = 0;j < n;j++){
			sum += (a[j] - i + 4) % 4;	
		}
		int l = (i + sum) % 4;
		ans = min(ans, sum + (4 - l) % 4);
	}
	cout << ans;
	
	return 0;
}
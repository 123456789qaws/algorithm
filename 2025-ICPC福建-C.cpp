#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 1;
int a[N], b[N], n;

bool check(int p){ // 消除 <p 的数 
	for(int i = 0;i < n;i++) b[i] = a[i];
	ll t = 0;
	int tmax, tmin, ans = 0;
	int i = 0;
	for(;i < n - 2;){
		if(b[i] < p){
			t = b[i] + b[i + 1] + b[i + 2];
			tmax = max(b[i], max(b[i + 1], b[i + 2]));
			tmin = min(b[i], min(b[i + 1], b[i + 2]));
			b[i + 2] = t - tmax - tmin;
			i = i + 2;
//			ans += 2;
		}
		else{
			i++;
			ans++;
		}
	}
//	cout << p << " " << ans << endl;
//	ans = n - ans - (n - i + 1); // == i - 1 - ans
//	cout << ans << "   " << test << endl;
	int smal = 0;
	for(;i < n;i++){
		if(b[i] < p) smal++;
		else ans++;
	}
	
//	cout << ans << " " << p << endl;
	return ans >= smal + 1;	 
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int l = INT_MAX, r = INT_MIN, mid;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			l = min(l, a[i]);
			r = max(r, a[i]);
		}
		while(l <= r){
			mid = ((ll)l + r) >> 1;
			if(check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		cout << l - 1 << '\n';
	}
	
	return 0;
}
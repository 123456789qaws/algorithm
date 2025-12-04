#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
//using PII = pair<int, int>;
//#define fir first
//#define sec second 

const int N = 2e5 + 1;
int n, r = n - 1, l = 0, a[N];
ll sum, ans[N];

void solve(){
	
	cin >> n;
	sum = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		sum += a[i];
	} 
	sort(a, a + n);
	
	l = 0, r = n - 1;
	for(int i = n - 1;i >= 2;i--){
		
		while(l > 0 && r > 0 && sum <= 2 * a[r]){
			sum -= a[r--];
			sum += a[--l];
		}
		if(l == 0 && sum <= 2 * a[r]) ans[i] = 0;
		else ans[i] = sum;
		
		sum -= a[l++];
		
	}
	
	for(int i = 0;i < n;i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
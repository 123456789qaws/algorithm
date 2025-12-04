#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define double long double

double r, c, p, L, R, n, k;
const int N = 2e5 + 1;
pair<double, double> a[N];

void init(){
	for(int i = 1;i <= n;i++){
		a[i].second = a[i].first = 0;
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T, t;
	cin >> T;
	while(T--){
		cin >> n >> k;
		cin >> r >> c >> p >> L >> R;
		init();
		double ans = 0;
		for(int i = 0;i < k;i++){
			cin >> t;
			cin >> a[t].second;
		}
		a[0].first = c, a[0].second = r;
		for(int i = 1;i <= n;i++){
			a[i].first = p * a[i - 1].first + (1 - p) * a[i - 1].second;
			if(a[i].second == 0) a[i].second = L;
		}
		for(int i = 1;i <= n;i++) ans += a[i].first - a[i].second;
		cout << fixed << setprecision(10) << ans << '\n';
	}
	
	return 0;
}
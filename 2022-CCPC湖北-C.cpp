#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, x, y, t;
bool flag;

ll solve(ll x, ll y){
	if(flag) return 0;
	
	ll comp1 = min(x, y);
	ll comp2 = max(x, y);
	ll base1 = min(a, b);
	ll base2 = max(a, b);
	
	if(comp1 * base2 == comp2 * base1) return 2;
	
	if((x + y) % (a + b)){
		flag = true;
		return 0;
	}
	
	t = (x + y) / (a + b);
	if(!(comp1 % a)){
		comp1 /= a;
		comp2 = t - comp1;
	}
	else if(!(comp2 % a)){
		comp2 /= a;
		comp1 = t - comp2;
	}
	else{
		flag = true;
		return 0;
	}
	return solve(comp1, comp2) + 1;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	ll T;
	cin >> T;
	while(T--){
		cin >> x >> y >> a >> b;
		flag = false;
		ll g = __gcd(x, y), d = __gcd(a, b);
		x /= g, y /= g;
		a /= d, b /= d;
		ll ans = solve(x, y);
		if(flag) cout << "-1\n";
		else cout << ans << '\n';
	}
	
	return 0;
}
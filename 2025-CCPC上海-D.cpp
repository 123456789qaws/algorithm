#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solute(ll a, ll b, ll x, ll y){
	ll ta = a, tx = x;
	while(ta > 0 || tx > 0){
		if((ta & 1) == 0 && (tx & 1) == 1){
			return false;
		}
		ta >>= 1;
		tx >>= 1;
	}
	ll tb = b, ty = y;
	while(ty > 0 || tb > 0){
		if((tb & 1) == 1 && (ty & 1) == 0){
			return false;
		}
		tb >>= 1;
		ty >>= 1;
	}
	if(a == x || b == y) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	ll T, a, b, x, y;
	cin >> T;
	while(T--){
		cin >> a >> b >> x >> y;
		if(x > a || y < b) cout << "No\n";
		else if(x == a && y == b) cout << "Yes\n";
		else{
			if(solute(a, b, x, y)) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	
	return 0;
}
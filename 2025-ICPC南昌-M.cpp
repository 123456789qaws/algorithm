#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int x, y, a, b, c, yet;
	cin >> x >> y;
	if(y > x * 2500LL || y % 500){
		cout << -1;
		return 0;
	}
	c = y / 2500;
	yet = y % 2500;
	if(yet == 500 || yet == 1500){
		if(!c){
			cout << -1;
			return 0;
		}
		c--;
		yet += 2500;
	}
	b = yet / 1000;
	cout << x - b - c << " " << b << " " << c;
	
	return 0;
}
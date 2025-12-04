#include <bits/stdc++.h>
using namespace std;

int up(double n, double k){
	double t = k / 2;
	if(n < t) return n * 2;
	return k + (n - t);
}

int down(double n, double k){
	double t = k / 2;
	if(n < t) return 0;
	return (n - t) + 1;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	double n, k;
	cin >> T;
	while(T--){
		cin >> n >> k;
//		if(k == 1){
//			cout << n << " " << n << '\n';
//			continue;
//		}
		
		cout << down(n, k) << " ";
		
		cout << up(n, k);
		
		cout << '\n';
	}
	
	return 0;
}
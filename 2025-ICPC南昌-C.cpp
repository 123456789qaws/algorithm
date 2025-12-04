#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	cout << min(n, m) + ((abs(n - m) + 1) >> 1);
	
	return 0;
}
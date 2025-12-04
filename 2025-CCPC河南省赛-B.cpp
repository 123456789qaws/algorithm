#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int a[N], pre[N], nex[N], n;

void build(){
	pre[0] = a[0];
	for(int i = 1;i < n;i++) pre[i] = max(pre[i - 1], a[i]);
	nex[n] = INT_MAX;
	for(int i = n - 1;i >= 0;i--) nex[i] = min(nex[i + 1], a[i]);
}

bool check(int cur){
	for(int i = cur - 1;i < n;i += cur){
		if(pre[i] > nex[i + 1]) return false;
	}
	return true;
}

int solute(){
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(check(i)) ans++;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	build();
	cout << solute();
	
	return 0;
}
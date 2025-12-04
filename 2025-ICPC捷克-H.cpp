#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 1;
int a[N], cur = 0, help[N];
int b;
int n;
ll ans;

ll merge(int l, int m, int r){
	int i = l, j = m + 1, t = l, num = m + 1 - l;
	ll res = 0;
	for(;i <= m && j <= r;){
		if(a[i] > a[j]) res += num, help[t++] = a[j++];
		else num--, help[t++] = a[i++];
	}
	while(i <= m) help[t++] = a[i++];
	while(j <= r) help[t++] = a[j++];
	for(int i = l;i <= r;i++) a[i] = help[i];
	return res;
}

ll solve(int l, int r){
	if(l >= r) return 0;
	int mid = (l + r) >> 1;
	return solve(l, mid) + solve(mid + 1, r) + merge(l, mid, r);
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	 
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> b;
		int be = cur;
		for(int j = 0;j < b;j++){
			cin >> a[cur++];
		}
		sort(a + be, a + cur);
	}
	cout << solve(0, cur - 1);
	
	return 0;
}
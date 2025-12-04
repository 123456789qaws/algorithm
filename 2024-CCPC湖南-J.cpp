#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 1;
int a[N], b[N];
int tree[2][N];
int n, t;

void add(int p, int v, int op){
	while(p <= n){
		tree[op][p] += v;
		p += p & -p;
	}
}

int query(int p, int op){
	int ans = 0;
	while(p >= 1){
		ans += tree[op][p];
		p -= p & -p;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> t;
		a[t] = i;
	}
	for(int i = 1;i <= n;i++){
		cin >> t;
		b[t] = i;
	}
	int ans = 0;
	for(int l = 1, r = 1;r <= n;r++){
		add(a[r], 1, 0);
		add(b[r], 1, 1);
		int sum1 = query(a[r], 0), sum2 = query(b[r], 1);
		while(l < r && sum1 != sum2){
			add(a[l], -1, 0);
			add(b[l++], -1, 1);
			sum1 = query(a[r], 0);
			sum2 = query(b[r], 1);
		}
		ans += r - l + 1;
	}
	cout << ans;
	      
	return 0;
}
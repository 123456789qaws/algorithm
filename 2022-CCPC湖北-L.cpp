#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 1;
ll sum[N << 2], num[N << 2], addn[N << 2], a[N], s[N];
ll pl, pr, op, n, m, p, pv;

void build(int l, int r, int cur){
	if(l == r){
		sum[cur] = a[l];
		num[cur] = s[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, cur << 1);
	build(mid + 1, r, cur << 1 | 1);
	sum[cur] = sum[cur << 1 | 1] + sum[cur << 1];
	num[cur] = num[cur << 1 | 1] + num[cur << 1];
}

void lazy(int cur, ll v){
	addn[cur] += v;
	sum[cur] += num[cur] * v;
}

void down(int cur){
	lazy(cur << 1, addn[cur]);
	lazy(cur << 1 | 1, addn[cur]);
	addn[cur] = 0;
}

void update(int l, int r, int cur){
	if(l == r){
		num[cur] = !num[cur];
		return;
	}
	int mid = (l + r) >> 1;
	if(addn[cur]) down(cur);
	if(p <= mid) update(l, mid, cur << 1);
	else update(mid + 1, r, cur << 1 | 1);
	num[cur] = num[cur << 1 | 1] + num[cur << 1];
}

void add(int l, int r, int cur){
	if(pl <= l && pr >= r){
		lazy(cur, pv);
		return;
	}
	int mid = (l + r) >> 1;
	if(addn[cur]) down(cur);
	if(pl <= mid) add(l, mid, cur << 1);
	if(pr > mid) add(mid + 1, r, cur << 1 | 1);
	sum[cur] = sum[cur << 1 | 1] + sum[cur << 1];
}

ll query(int l, int r, int cur){
	if(pl <= l && pr >= r) return sum[cur];
	int mid = (l + r) >> 1;
	if(addn[cur]) down(cur);
	ll ans = 0;
	if(pl <= mid) ans += query(l, mid, cur << 1);
	if(pr > mid) ans += query(mid + 1, r, cur << 1 | 1);
	return ans;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> s[i];
	build(1, n, 1);
	while(m--){
		cin >> op;
		if(op == 1){
			cin >> p;
			update(1, n, 1);
		}
		else if(op == 2){
			cin >> p;
			update(1, n, 1);
		}
		else if(op == 3){
			cin >> pl >> pr >> pv;
			add(1, n, 1);
		}
		else{
			cin >> pl >> pr;
			cout << query(1, n, 1) << '\n';
		}
	}
	
	return 0;
}
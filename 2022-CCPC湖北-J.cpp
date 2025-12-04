#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int N = 1e5 + 5, base = 399;
ll a[N], sum[N], b[N];

void init(string &s){
	int n = s.size();
	//   be->
	sum[0] = 1;
	a[0] = s[0];
	for(int i = 1;i < n;i++){
		sum[i] = sum[i - 1] * base;
		a[i] = a[i - 1] * base + s[i];
	}
	//   <-en
	b[n - 1] = s[n - 1];
	for(int i = n - 2;i >= 0;i--){
		b[i] = b[i + 1] * base + s[i];
	}
	
}

ll get_hash(int l, int r){
	return a[r] - (l ? a[l - 1] : 0) * sum[r - l + 1];
}

ll rget_hash(int l, int r){  // 逆向 / 反转
	return b[l] - b[r + 1] * sum[r - l + 1];
}


void solve(string &s, int l, int r){
	for(int i = l + 1;i < r;i++){
		ll t1 = get_hash(i + 1, r) + rget_hash(l, i) * sum[r - i];
		ll t2 = rget_hash(i + 1, r) * sum[i - l + 1] + get_hash(l, i);
		if(t1 == t2){
			cout << l + 1 << " " << i + 1;
			return;
		}
	}
	for(int i = r - 1;i > l;i--){
		ll t1 = get_hash(l, i - 1) * sum[r - i + 1] + rget_hash(i, r);
		ll t2 = rget_hash(l, i - 1) + get_hash(i, r) * sum[i - l];
		if(t1 == t2){
			cout << i + 1 << " " << r + 1;
			return;
		}
	}
	cout << "-1 -1";
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	string s;
	cin >> s;
	init(s);
	int be = 0, en = s.size() - 1;
	for(;s[be] == s[en] && be < en;be++, en--);
	if(be >= en){
		cout << "1 1";
		return 0;
	}
	solve(s, be, en);
	
	return 0;
}
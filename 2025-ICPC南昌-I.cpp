#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 1, mod = 998244353;
int n, k;
ll fac[N], ksm[N];
string s;

ll num(int len, int p){
	if(len <= p) return len == p;
	return ((fac[len] * ksm[len - p] % mod) * ksm[p]) % mod;
}

int solve(){
	int n = s.size();
	ll ans = 0;
	vector<int> pos;
	pos.push_back(-1);
	for(int i = 0;i < n;i++) if(s[i] == '1') pos.push_back(i);
	pos.push_back(n);
	for(int i = 0;i + k + 1 < pos.size();i++){
		ans = (ans + num(pos[i + k + 1] - pos[i] - 1, k)) % mod;
	}
	for(int i = 1;i + k + 1 < pos.size();i++){
		ans = (ans - num(pos[i + k] - pos[i] - 1, k - 1) + mod) % mod;
	}
	return ans;
}

ll qsm(ll a, int n){
	ll ans = 1;
	while(n > 0){
		if(n & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}

void build(){
	fac[0] = 1;
	for(int i = 1;i < N;i++){
		fac[i] = (fac[i - 1] * i) % mod;
	}
	ksm[N - 1] = qsm(fac[N - 1], mod - 2);
	for(int i = N - 2;i >= 0;i--){
		ksm[i] = (ksm[i + 1] * (i + 1)) % mod;
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	build();
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		cin >> s;
		cout << solve() << '\n';
	}
	
	return 0;
}
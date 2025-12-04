#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 1, mod = 998244353;
int n, m, a, b;
ll cnt[N];
unordered_map<ll, ll> ma;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		cnt[a]++, cnt[b]++;
	}
	for(int i = 1;i <= n;i++) ma[cnt[i]]++;
	ll ans = 0;
	for(auto i = ma.begin();i != ma.end();i++){
		for(auto j = next(i);j != ma.end();j++){
			ans = (ans + (i->second * j->second) * (i->first ^ j->first) * (i->first & j->first) * (i->first | j->first)) % mod;
		}
	}
	cout << ans;
	
	return 0;
}
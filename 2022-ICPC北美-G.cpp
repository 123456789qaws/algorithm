#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int N = 1e5 + 1, mod = 1e9 + 7;
ll dp[N], ans = 1;
int pre[N], in[N], n;
vector<int> son[N];
bool c[N];

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> pre[i];
		son[pre[i]].push_back(i);
		in[pre[i]]++;
		dp[i] = 1;
	}
	queue<int> q;
	for(int i = 1;i <= n;i++) if(!in[i]) q.push(i); 
	while(!q.empty()){
		int t = q.front(); q.pop();
		dp[pre[t]] = (dp[pre[t]] + dp[pre[t]] * dp[t]) % mod;
		if(--in[pre[t]] == 0) q.push(pre[t]);
	}
	for(int i = 1;i <= n;i++) if(in[i]) q.push(i);
	while(!q.empty()){
		int t = q.front(); q.pop();
		if(c[t]) continue;
		ll res = 1;
		while(!c[t]){
			c[t] = true;
			for(int i : son[t]){
				if(!in[i]) res = (res * (1 + dp[i])) % mod; 
			}
			t = pre[t];
		}
		ans = (ans + ans * res) % mod;
	}
	cout << (ans - 1 + mod) % mod;

	return 0;
}
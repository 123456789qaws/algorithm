#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
using PII = pair<ll, int>;
#define fir first
#define sec second 

const int N = 5e5 + 1;
int n, pre[N], p[N], s[N];
ll ans[N];
bool vis[N], ent[N];
vector<int> g[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> pre[i];
		g[pre[i]].push_back(i);
	} 
	for(int i = 1;i <= n;i++) cin >> p[i];
	for(int i = 1;i <= n;i++){
		if(p[pre[i]] > p[i]) s[i] = 1;
		else s[i] = -1;
	}
	
	priority_queue<PII, vector<PII>, greater<PII>> q;
	for(int i = 1;i <= n;i++){
		if(s[pre[i]] != s[i]) q.push({ abs(p[i] - p[pre[i]]), i });
	}
	
	while(!q.empty()){
		auto [dis, t] = q.top(); q.pop();
		if(vis[t]) continue;
		
		int fa = pre[t];	
		if(!ent[t] && s[t] != s[fa] && vis[fa]){
			ent[t] = true;
			continue;
		}
		
		ans[t] = dis;
		vis[t] = true;
//		p[t] += (s[t] * dis) / 2;
		
		for(int i : g[t]){
			if(vis[i]) continue;
			if(s[i] == s[t]) q.push({ dis + abs(p[i] - p[t]) * 2, i });
			else q.push({ abs(p[i] - p[t]) * 2 - dis, i });
		}
		
	}
	
	for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
	
	return 0;
}
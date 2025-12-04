#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
using PII = pair<int, int>;
#define fir first
#define sec second 

const int N = 3e5 + 5;
int n, m, q, a, b, x, y, pre[N];
ll val[N], dp[N], sum[N], cmp[N];
vector<PII> p, fi[N];

int head[N], nxt[N << 1], to[N << 1], cur = 1;
void add(int a, int b){
	to[cur] = b;
	nxt[cur] = head[a];
	head[a] = cur++;
}

ll dfs(int cur, int fa){
	pre[cur] = fa;
	
	ll a1 = LLONG_MAX, a2 = LLONG_MAX;
	for(int ei = head[cur];ei;ei = nxt[ei]){
		if(to[ei] == fa) continue;
		ll t = dfs(to[ei], cur);
		if(t <= a1){
			a2 = a1;
			a1 = t;
		}
		else if(t < a2) a2 = t;
	}
	
	if(a1 == LLONG_MAX) return dp[cur] = val[cur];
	
	return dp[cur] = min(val[cur], a1 + a2);
}

void find(int x, int fa){
	ll t = LLONG_MAX;
	for(int ei = head[fa];ei;ei = nxt[ei]){
		if(to[ei] == x || to[ei] == pre[fa]) continue;
		t = min(t, dp[to[ei]]);
	}
	sum[x] = sum[fa] + (t == LLONG_MAX ? 0 : t);
	for(int ei = head[x];ei;ei = nxt[ei]){
		if(to[ei] == fa) continue;
		find(to[ei], x);
	}
}

int fat[N];
bool vis[N];

int root(int x){
	return fat[x] == x ? x : fat[x] = root(fat[x]);
}

void lca(int cur, int fa){
	vis[cur] = true;
	for(int ei = head[cur];ei;ei = nxt[ei]){
		int i = to[ei];
		if(i == fa) continue;
		if(!vis[i]){
			lca(i, cur);
			fat[i] = cur; 
		}
	}
	for(PII &i : fi[cur]){
		if(vis[i.fir]) cmp[i.sec] = root(i.fir);
	}
}

void clear(){
	cur = 1;
	memset(head, 0, sizeof(int) * (n + 1));
	memset(vis, 0, sizeof(bool) * (n + 1));
	for(int i = 1;i <= n;i++) fi[i].clear();
	for(int i = 1;i <= n;i++) fat[i] = i;
}

void solve(){
	
	cin >> n >> q;
	m = n - 1;
	clear();
	p.resize(q);
	
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int i = 1;i <= m;i++){
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	dfs(1, 0);
	find(1, 0);
	
	for(int i = 0;i < q;i++){
		cin >> x >> y;
		p[i] = {x, y};
		fi[x].push_back({y, i});
		fi[y].push_back({x, i});
	}
	
	lca(1, 0);
	
	for(int i = 0;i < q;i++){
		if(!cmp[i]) cmp[i] = 1;
		x = p[i].fir, y = p[i].sec;
		if(cmp[i] != y){
			cout << -1 << '\n';
		}
		else if(x == y){
			cout << 0 << '\n';
		}
		else{
			ll t = sum[x] - sum[y];
			cout << t << '\n';
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int n, m;
const int N = 1e5 + 5, M = 1e6 + 1e5 + 5;
ll dp[N][2];
int head[N], mnext[M], val[M], to[M], cur = 1;
ll nmin = LLONG_MAX, nmax = LLONG_MIN, p;
vector<pair<ll, int>> ve(N);

bool vis[N][2];
int a, b, c;

void add(int a, int b, int v){
	mnext[cur] = head[a];
	head[a] = cur;
	to[cur] = b;
	val[cur++] = v;
}

struct node{
	ll v;
	int a;
	int op;
};

void solve(){
	auto cmp = [](const node &a, const node &b){
		return a.v > b.v;
	};
	priority_queue<node, vector<node>, decltype(cmp)> q(cmp);
	for(int i = 1;i <= n;i++) add(0, i, ve[i].first);
	dp[0][0] = dp[0][1] = 0;
	q.push({0, 0, 1});
	while(!q.empty()){
		node a = q.top(); q.pop();
		if(vis[a.a][a.op]) continue;
		vis[a.a][a.op] = true;
		for(int ei = head[a.a];ei;ei = mnext[ei]){	
			int t = to[ei];
			if(a.a && a.op && !vis[t][0] && a.v < dp[t][0]){
				dp[t][0] = a.v;
				q.push({ a.v, t, 0 });
			}
			if(!vis[t][a.op] && a.v + val[ei] < dp[t][a.op]){
				dp[t][a.op] = a.v + val[ei];
				q.push({ dp[t][a.op], t, a.op });
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
//		cout << i << " : " << dp[i][0] << " " << dp[i][1] << endl;
		ans = max(ans, min(dp[i][1], dp[i][0]));
	}
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	for(int i = 1;i <= n;i++){
		cin >> ve[i].first;
		ve[i].second = i;
		dp[i][0] = dp[i][1] = LLONG_MAX;
		if(nmin > ve[i].first){
			nmin = ve[i].first;
			p = i;
		}
	}
	solve();
	      
	return 0;
}
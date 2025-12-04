#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 301;
ll dis[N][N];
int n, m, k, t, a, b, c, p[N], pre[N];
ll ans = 0;

void floyd(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				if(dis[j][i] != LLONG_MAX && dis[i][k] != LLONG_MAX){
					dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
				}
			}
		}
	}
}

bool unA_num(){
	int cur = 0;
	for(int i = 1;i <= n;i++){
		if(p[cur] == i){
			cur++;
			continue;
		}
		ll t = LLONG_MAX;
		for(int j = 0;j < k;j++){
			if(dis[i][p[j]] != LLONG_MAX){
				t = min(t, dis[i][p[j]]);
			}
		}
		if(t == LLONG_MAX) return false;
		ans = max(ans, t << 1);
	}
	return true;
}

int root(int x){
	return pre[x] == x ? x : pre[x] = root(pre[x]);
}

bool merge(int x, int y){
	x = root(x), y = root(y);
	if(x == y) return false;
	pre[x] = y;
	return true;
}

bool A_num(){
	for(int i = 0;i < k;i++) pre[i] = i;
	vector<tuple<int, int, ll>> edge;
	for(int i = 0;i < k;i++){
		for(int j = i + 1;j < k;j++){
			if(dis[p[i]][p[j]] != LLONG_MAX) edge.push_back({i, j, dis[p[i]][p[j]]});
		}
	}
	sort(edge.begin(), edge.end(), [](tuple<int, int, ll> &a, tuple<int, int, ll> & b){
		return get<2>(a) < get<2>(b);	 
	});
	int cnt = 0;
	for(tuple<int, int, ll> &i : edge){
		if(merge(get<0>(i), get<1>(i))) ans = max(ans, get<2>(i)), cnt++;
	}
	return cnt == k - 1;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> k >> t;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			dis[i][j] = LLONG_MAX;
		}
	}
	while(m--){
		cin >> a >> b >> c;
		dis[a][b] = dis[b][a] = c;
	}
	for(int i = 0;i < k;i++) cin >> p[i];
	if(!t){
		if(n > 1){
			cout << -1;
			return 0;	
		}
		else{
			cout << 0;
			return 0;
		}
	}
	p[k] = n + 1;
	sort(p, p + k);
	floyd();
	bool can1 = unA_num();
	bool can2 = A_num();
	if(can1 && can2) cout << (ans + t - 1) / t;
	else cout << -1;
	
	return 0;
}
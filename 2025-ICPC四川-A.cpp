#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fa first
#define sb second

const int N = 310, M = 1010, MAXP = N * 210;
int head[N], mnext[M], to[M], cur = 1;
pair<int, int> val[M];
int n, m, maxp, u, v, a, b;
ll dp[MAXP][N];

void add(int x, int y, int a, int b){
	mnext[cur] = head[x];
	to[cur] = y;
	head[x] = cur;
	val[cur++] = make_pair(a, b); 
}

void init(){
	for(int i = 0;i < MAXP;i++) for(int j = 1;j <= n;j++) dp[i][j] = INT_MAX;
	dp[0][1] = 0;
	memset(head, 0, sizeof(int) * (n + 1));
	cur = 1;
}

void solve(){
	for(int i = 0;i <= maxp;i++){
		for(int j = 1;j <= n;j++){
			for(int ei = head[j];ei;ei = mnext[ei]){
				if(i + val[ei].fa <= maxp) dp[i + val[ei].fa][to[ei]] = min(dp[i + val[ei].fa][to[ei]], dp[i][j] + val[ei].sb);
			}
		}
	}
	ll ans = LLONG_MAX, res = 0;
//	for(int i = 0;i <= maxp;i++){
//		for(int j = 1;j <= n;j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << '\n';
//	}
	for(int i = 1;i <= maxp;i++){
		if((ll)dp[i][n] * i < ans){
			ans = (ll)dp[i][n] * i;
			res = i;
		}
	}
	cout << res << " " << dp[res][n] << '\n';
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		init();
		maxp = 0;
		for(int i = 0;i < m;i++){
			cin >> u >> v >> a >> b;
			add(u, v, a, b);
			maxp = max(maxp, a);
		}
		maxp *= n;
		solve();
	}
	
	return 0;
}
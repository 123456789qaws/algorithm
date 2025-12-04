#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 1, M = 5e5 + 1;
int head[N], mnext[M], to[M], val[M], cur = 1;
int dp[33][N];
int n, m, q, a, b, c, p, x;

void add(int x, int y, int v){
	mnext[cur] = head[x];
	head[x] = cur;
	to[cur] = y;
	val[cur++] = v;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> q;
	for(int i = 0;i < m;i++){
		cin >> a >> b >> c;
		add(a, b, c);
	}
	for(int i = 1;i <= n;i++) dp[0][i] = 1;
	for(int i = 1;i <= 32;i++){
		for(int j = 1;j <= n;j++){
			for(int ei = head[j];ei;ei = mnext[ei]){
				if(dp[i - 1][to[ei]] >= INT_MAX / val[ei]) dp[i][j] = INT_MAX;
				else dp[i][j] = max(dp[i][j], dp[i - 1][to[ei]] * val[ei]);
			}
		}
	}
	int l, r, mid;
	while(q--){
		cin >> p >> x;
		l = 1, r = 30;
		while(l <= r){
			mid = (l + r) >> 1;
			if(dp[mid][p] > x) r = mid - 1;
			else l = mid + 1;
		}
		cout << r + 1 << '\n';
	}
	
	return 0;
}
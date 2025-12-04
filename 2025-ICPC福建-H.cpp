#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 1;
char g[N][N];
ll l, r;
ll dp[N][N][2];
queue<tuple<int, int, int>> q;
int xx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int yy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int nx, ny, x, y, t, n, m;

void solute(){
	dp[1][1][0] = 0;
	q.push(make_tuple(1, 1, 0));
	while(!q.empty()){
		x = get<0>(q.front()), y = get<1>(q.front()), t = get<2>(q.front()); q.pop();
		for(int i = 0;i < 8;i++){
			nx = x + xx[i], ny = y + yy[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny] == '0') continue;
			if(dp[nx][ny][t ^ 1] > dp[x][y][t] + 1){
				dp[nx][ny][t ^ 1] = dp[x][y][t] + 1;
				q.push(make_tuple(nx, ny, t ^ 1));
			}
		}
	}
	if(dp[n][m][0] == 2e15 && dp[n][m][1] == 2e15){
		cout << "-1\n";
		return;
	}
	int p = n * m;
	ll ans;
	for(int i = 1;i <= p;i++){
		ans = LLONG_MAX;
		if(dp[n][m][0] <= i * r){
			if(dp[n][m][0] >= i * l) ans = min(ans, dp[n][m][0]);
			else ans = min(ans, /*(i * l + 1) / 2 * 2*/ i * l + ((i * l) & 1 ? 1 : 0));
		}
		if(dp[n][m][1] <= i * r){
			if(dp[n][m][1] >= i * l) ans = min(ans, dp[n][m][1]);
			else ans = min(ans, /*(i * l) / 2 * 2 + 1*/ i * l + ((i * l) & 1 ? 0 : 1));
		}
		if(ans <= i * r && ans >= i * l){
			cout << i << '\n';
			return;
		}
	}
	cout << "-1\n";
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> l >> r;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> g[i][j];
				dp[i][j][0] = dp[i][j][1] = 2e15;
			}
		}
		solute();
//		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) dp[i][j][0] = dp[i][j][1] = 0;  //不需要 
	}
	
	return 0;
}
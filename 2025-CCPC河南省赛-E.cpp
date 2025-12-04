#include <bits/stdc++.h>
using namespace std;

const int N = 505, X = 1e3 + 5;
int dp[N][X];
char g[N][N];

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T, n, m, x;
	cin >> T;
	while(T--){
//		memset(dp, 0, sizeof(dp));
		cin >> n >> m >> x;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> g[i][j];
			}
		}
		for(int i = 0;i <= m;i++) for(int j = 0;j <= x;j++) dp[i][j] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				for(int k = 0, pre = dp[j][k - 1], t;k <= x;k++){
					t = dp[j][k];
					dp[j][k] = max(dp[j][k], dp[j - 1][k]);
					if(g[i][j] == '?' && k > 0) dp[j][k] = max(dp[j][k], max(pre + 1, dp[j - 1][k - 1] + 1));
					if(g[i][j] == '1') dp[j][k]++;
					pre = t;
				}
			}
		}
		int ans = 0;
		for(int i = 0;i <= x;i++) ans = max(ans, dp[m][i]);
		cout << ans << '\n';
	}
	
	return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 505, X = 1e3 + 5;
//int dp[2][N][X];
//char g[N][N];
//
//int main(){
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//	
//	int T, n, m, x;
//	cin >> T;
//	while(T--){
//		cin >> n >> m >> x;
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= m;j++){
//				cin >> g[i][j];
//			}
//		}
//		for(int i = 0;i <= m;i++) for(int j = 0;j <= m;j++) dp[0][i][j] = dp[1][i][j] = 0;
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= m;j++){
//				for(int k = 0;k <= x;k++){
//					if(g[i][j] == '0') dp[i & 1][j][k] = max(dp[(i - 1) & 1][j][k], dp[i & 1][j - 1][k]);
//					else if(g[i][j] == '1') dp[i & 1][j][k] = max(dp[(i - 1) & 1][j][k], dp[i & 1][j - 1][k]) + 1;
//					else{
//						if(k > 0) dp[i & 1][j][k] = max(dp[(i - 1) & 1][j][k - 1], dp[i & 1][j - 1][k - 1]) + 1;
//						else dp[i & 1][j][k] = max(dp[(i - 1) & 1][j][k], dp[i & 1][j - 1][k]);
//					} 
//				}
//			}
//		}
//		int ans = dp[n & 1][m][x];
//		cout << ans << '\n';
//	}
//	
//	return 0;
//}
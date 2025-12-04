#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5010, mod = 998244353;
int head[N], mnext[2 * N], to[2 * N], a[N], cur = 1;
int dp[N][N], f[N][N], msize[N];
int n, c, b;

void add(int a, int b){
	mnext[cur] = head[a];
	to[cur] = b;
	head[a] = cur++;
}

void hdp(int root, int fa){
	msize[root] = 1;
	f[root][0] = 1;
	for(int ei = head[root], t;ei;ei = mnext[ei]){
		t = to[ei];
		if(t == fa) continue;
		hdp(t, root);
		msize[root] += msize[t];
		for(int i = n;i >= 0;i--){
			if(f[root][i]){
				int p = f[root][i];
				for(int j = 0;j <= msize[t] && i + j <= n;j++){
					f[root][i + j] = ((ll)p * dp[t][j] + f[root][i + j]) % mod;
				}
			}
		}
	}
	for(int i = 0;i <= msize[root];i++){
		if(i == a[root]) dp[root][i] = f[root][i - 1];
		else dp[root][i] = f[root][i];
	}
}

void solve(){
	cin >> n;
	cur = 1;
	for(int i = 0;i <= n;i++){
		head[i] = 0;
		msize[i] = 0;
		for(int j = 0;j <= n;j++) dp[i][j] = f[i][j] = 0;
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i < n;i++){
		cin >> c >> b;
		add(c, b);
		add(b, c);
	}
	hdp(1, 0);
	int ans = 0;
	for(int i = 0;i <= n;i++) ans = (ans + dp[1][i]) % mod;
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
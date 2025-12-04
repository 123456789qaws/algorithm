#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 1;
int head[N], mnext[N], to[N], val[N], cur = 1;
int n, a, b, c, p = INT_MAX;
int l[N], r[N], ans[N];

void add(int a, int b, int c){
	mnext[cur] = head[a];
	head[a] = cur;
	to[cur] = b;
	val[cur++] = c;
}

void dfs(int cur, int fa){
	l[cur] = 1;
	int t, w;
	for(int i = head[cur];i;i = mnext[i]){
		t = to[i];
		if(t == fa) continue;
		w = val[i];
		r[t] = w - 1;
		dfs(t, cur);
		r[cur] = min(r[cur], w - l[t]);
		l[cur] = max(l[cur], w - r[t]);
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i = 1;i < n;i++){
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
		p = min(p, c);
	}
	r[1] = INT_MAX;
	dfs(1, 0);
	for(int i = 1;i < cur;i += 2){
		int u = to[i] , v = to[i + 1] , w = val[i];
		if(r[u] + r[v] < w || l[u] > r[u] || l[v] > r[v]) { 
            cout << "NO";
			return 0;
		}
	}
	ans[1] = l[1];
	queue<int> q;
	q.push(1);
	while(!q.empty()){ 
		int t = q.front(); q.pop();
		for(int i = head[t];i; i = mnext[i]) {
			int v = to[i], w = val[i];
			if(ans[v]) continue;
			ans[v] = w - ans[t];
			q.push(v);
		}
	}
	cout << "YES\n";
	for(int i = 1;i <= n;i ++) cout << ans[i] << " ";
	
	return 0;
}
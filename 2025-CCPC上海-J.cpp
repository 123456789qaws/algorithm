#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define PII pair<int, int>

const int N = 2e5 + 1;
int n, m, u, v, w;
vector<PII> e;
int pre[N];

int root(int x){
	return pre[x] == x ? x : pre[x] = root(pre[x]);
}
void merge(int a, int b){
	a = root(a), b = root(b);
	pre[a] = b;
}

void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) pre[i] = i;
	int ans = 0;
	e.clear();
	while(m--){
		cin >> u >> v >> w;
		if(w == 1) merge(u, v);
		else e.push_back(make_pair(u, v));
	}
	for(PII &a : e){
		if(root(a.fir) == root(a.sec)) ans++;
		merge(a.fir, a.sec);
	}
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
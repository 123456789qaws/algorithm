#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 1, M = 2e5 + 1;
int fa[N], pre[N], a[N], head[N], mnext[M], to[M], cur = 1;
bool vis[N];
int n, u, v;

void add(int a, int b){
	mnext[cur] = head[a];
	head[a] = cur;
	to[cur++] = b;
}

int root(int x){
	return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void merge(int x, int y){
	int prex = root(x), prey = root(y);
	if(prex == prey) return;
	pre[prex] = prey;
	fa[prex] = y;
}

void clear(){
	cur = 1;
	memset(vis, 0, sizeof(bool) * (n + 1));
	memset(head, 0, sizeof(int) * (n + 1));
	memset(fa, 0, sizeof(int) * (n + 1));
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++) pre[i] = i;
		for(int i = 0;i < n;i++) cin >> a[i];
		for(int i = 1;i < n;i++){
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		for(int i = n - 1;i >= 0;i--){
			vis[a[i]] = true;
			for(int ei = head[a[i]];ei;ei = mnext[ei]){
				if(vis[to[ei]]){
					merge(to[ei], a[i]);
				}
			}
		}
		for(int i = 1;i <= n;i++) cout << fa[i] << " ";
		cout << '\n';
		clear();
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5, M = 2e6 + 5;
int head[N], mnext[M], to[M], cur = 1;
char s[N];
ll n, a, b, ans;
string p = "SCCPC";

struct node{
	ll a[4] = {0};  //前->后 
	ll b[4] = {0};  //后->前 
};

void add(int a, int b){
	mnext[cur] = head[a];
	head[a] = cur;
	to[cur++] = b;
}

void clear(){
	ans = 0;
	cur = 1;
	memset(head, 0, sizeof(int) * (n + 1));
}

node dfs(int root, int fa){
//	if(root > n) return;
	node t;
	ll a[4] = {0};
	ll b[4] = {0};
	for(int i = head[root];i;i = mnext[i]){
		if(to[i] == fa) continue;
		t = dfs(to[i], root);
		for(int j = 0;j < 4;j++){
			a[j] += t.a[j];
			b[j] += t.b[j];
		}
	}
	if(s[root] == 'S'){
		ans += b[3];
		return { {1, 0, 0, 0}, {0, 0, 0, 0} };
	}
	else if(s[root] == 'P'){
		if(b[0]) ans += a[2] * (b[0] - 1);
		return { {0, 0, 0, a[2]}, {0, b[0], 0, 0} };
	}
	else if(s[root] == 'C'){
		ans += a[0] * b[2] + a[1] * b[1] + a[3];
		return { {0, a[0], a[1], 0}, {1, 0, b[1], b[2]} };
	}
	return { {0, 0, 0, 0}, {0, 0, 0, 0} };
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> s[i];
//		cout << s + 1 << endl;
		for(int i = 1;i < n;i++){
			cin >> a >> b;
			add(a, b);
			add(b, a);
		}
		if(n < 5) cout << "0\n";
		else{
			dfs(1, 0);
			cout << ans << '\n';
		}
		clear();
		
	}
	
	return 0;
}
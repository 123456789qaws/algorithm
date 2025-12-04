#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 1;
int t, n, m, k;
struct edge{
	int a, b;
	int v;
	int id;	
}e[N];
int pre[N];

int root(int x){
	return pre[x] == x ? x : pre[x] = root(pre[x]);
}

bool merge(int a, int b){
	a = root(a), b = root(b);
	if(a == b) return false;
	pre[a] = b;
	return true;
}

void in(){
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) pre[i] = i;
	for(int i = 0;i < m;i++){
		cin >> e[i].a >> e[i].b >> e[i].v;
		e[i].id = i + 1;
	}
}

void out(int result, int cnt, vector<int> &bh){
	cout << result << '\n';
	int cur = m + 1;
	for(int i = 2;i <= n;i++){
		if(merge(i, i - 1)){
			cout << i - 1 << " " << i << '\n';
			bh.push_back(cur++);
		}
	}
	cout << cnt << '\n';
	for(int i = 0;i < bh.size();i++) cout << bh[i] << " ";
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> t;
	while(t--){
		//读入
		in();
		//排序 + 预处理
		vector<edge> ans;
		vector<int> bh;
		sort(e, e + m, [](edge &a, edge &b){
			return a.v < b.v;
		});
		//最小生成树
		ll num = 0, result = 0, cnt = 0;
		for(int i = 0;i < m && num < n - 1;i++){
			if(merge(e[i].a, e[i].b)){
				ans.push_back(e[i]);
				num++;
				cnt += e[i].v;
			}
		}
		//删边 + 加边
		for(int i = 1;i <= n;i++) pre[i] = i;
		while(!ans.empty() && k > 0){
			if(ans.back().v <= 1) break;
			cnt -= ans.back().v - 1;
			result++;
			ans.pop_back();
			k--;
		}
		for(int i = 0;i < ans.size();i++){
			merge(ans[i].a, ans[i].b);
			bh.push_back(ans[i].id);
		}
		//输出
		out(result, cnt, bh);
	}
	
	return 0;
}
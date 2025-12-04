#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//vector<int> ans;
//bool vis[100];
//bool yet;
//
//void dfs(int cur, int n){
//	if(yet) return;
//	if(cur == n){
//		int b = 0;
//		for(int i = 0;i < n;i++){
//			b ^= ans[i];
//			if(b <= 0) break;
//		} 
//		if(b > 0) yet = true;
//		return;
//	}
//	for(int i = 0;i < n;i++){
//		if(vis[i]) continue;
//		ans.push_back(i);
//		vis[i] = true;
//		dfs(cur + 1, n);
//		if(yet) return;
//		ans.pop_back();
//		vis[i] = false;
//	}
//}

//void solve(int n){
//	dfs(0, n);
//	if(yet){
//		for(int i = 0;i < ans.size();i++) cout << ans[i] <<' ';
//		cout << endl;
//	}
//	else cout << "IMPOSSBLE\n";
//}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		if(!(n % 4) || n == 1){
			cout << "impossible\n";
			continue;
		}
		if(n == 2) cout << "1 0\n";
		else{
			cout << "1 0 2 ";
			int i = 3, op = 1;
			for(;i + 1 < n;i += 2){
				if(op) cout << i + 1 << " " << i << " ";
				else cout << i << " " << i + 1 << " ";
				op = !op;
			}
			if(i < n) cout << i;
			cout << '\n';
		}
	}
//	for(int i = 1;i < 12;i++){
//		solve(i);
//		memset(vis, 0, sizeof(vis));
//		yet = false;
//		ans.clear();
//	}
	
	
	return 0;
}
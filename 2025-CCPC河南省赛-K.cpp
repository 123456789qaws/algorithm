#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
//bool isp[N];
//void build(){
//	isp[0] = isp[1] = true;
//	int en = sqrt(n);
//	for(int i = 2;i <= en;i++){
//		if(isp[i]) continue;
//		for(int j = i * i;j <= n;j += i){
//			isp[j] = true;
//		}
//	}
//}
//
//bool vis[N];
//bool efind = false;
//vector<int> ans;
//void solute(int cur){
//	if(efind) return;
//	if(cur == n){
//		bool flag = true;
//		for(int i = 1;i <= ans.size();i++){
//			if(isp[abs(ans[i % ans.size()] - ans[i - 1])]){
//				flag = false;
//				break;
//			}
//		}
//		if(flag){
//			efind = true;
//			for(int i = 0;i < ans.size();i++) cout << ans[i] << " ";
//			cout << '\n';
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		if(vis[i]) continue;
//		vis[i] = true;
//		ans.push_back(i);
//		solute(cur + 1);
//		ans.pop_back();
//		vis[i] = false;
//	}
//}
//
//void test(){
//	for(int i = 1;i <= 12;i++){
//		n = i;
//		cout << i << "  :   \n";
//		efind = false;
//		solute(0);
//		if(!efind) cout << -1 << '\n';
//	}
//}

unordered_map<int, vector<int>> ma = { {5, {1, 3, 5, 2, 4}}, {6, {1, 3, 5, 2, 4, 6}}, {7, {1, 3, 5, 7, 2, 4, 6}}, {8, {1, 3, 5, 7, 2, 4, 6, 8}}, {9, {1, 3, 5, 7, 9, 2, 4, 6, 8}}, {10, {1, 3, 10, 5, 7, 9, 2, 4, 6, 8}}, {11, {1, 3, 10, 5, 2, 7, 9, 11, 8, 6, 4}} };

vector<int> solute(){
	vector<int> ans;
	int st = 0, sm = 2;
	if(n & 1) st = 1;
	else st = 4;
	for(;st <= n;st += 2) ans.push_back(st);
	int newp = st - 3, en = (n & 1 ? 2 : 0);
	for(st -= 5;st > en;st -= 2) ans.push_back(st);
	int in;
	if(n & 1) in = (newp - 5 - 1) / 2 + 1;
	else in = (newp - 5) / 2 - 1;
	ans.insert(ans.begin() + in, newp);
	if(n & 1) ans.insert(ans.begin() + 3, sm);
	else ans.insert(ans.end() - 3, sm);
	return ans;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
//	build();
//	test();
	vector<int> ans;
	if(n <= 4) cout << -1;
	else if(n <= 11) ans = ma[n];
	else ans = solute();
	for(int i = 0;i < ans.size();i++) cout << ans[i] << " ";
		
	
	return 0;
}
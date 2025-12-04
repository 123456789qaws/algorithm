#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string num;
int ans = 0;

bool is_p(int p){
	if(!(p & 1) || p < 2) return false;
	int t = sqrt(p);
	for(int i = 3;i <= t;i += 2){
		if(p % i == 0) return false;
	}
	return true;
}

void solve(string s, int cnt){
	while(s.size() && s[0] == '0') s.erase(s.begin());
	if(!s.size() || !is_p(stoi(s))) return;
	ans = max(ans, cnt);
	for(int i = 0;i < s.size();i++){
		solve(s.substr(0, i) + s.substr(i + 1), cnt + 1);
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	 
	cin >> num;
	solve(num, 1);
	cout << ans;
	
	return 0;
}
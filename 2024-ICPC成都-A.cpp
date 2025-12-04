#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
using PII = pair<int, int>;
#define fir first
#define sec second

const int N = 5e5 + 1;
int n, cnt, en, t;
string s;
PII ans[N];

bool check(){
	if(s[0] == '-') return true;
	en = n - 1;
	while(en >= 0 && s[en] == '>') en--;
	if(en >= n - 3 || en == -1) return true;
	return false;
}

void solve(){
	
	cin >> s;
	cnt = 0;
	n = s.size();
	
	if(check()){
		cout << "No\n";
		return;
	}
	
	for(int i = 0;i <= en;i++){
		if(s[i] == '>'){
			ans[cnt++] = {i + 1, n - i};
			t = i + 1;
		}
	}
	for(int i = n - 4;i > en;i--){
		ans[cnt++] = {t, i - t + 4};
	}
	
	cout << "Yes " << cnt << endl;
	for(int i = 0;i < cnt;i++){
		cout << ans[i].fir << ' ' << ans[i].sec << '\n';
	}
	
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
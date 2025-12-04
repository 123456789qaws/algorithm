#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
ll a[N]/*0*/, b[N]/*1*/, c[N]/*前往后?*/, d[N]/*后往前?*/, e[N], f[N];
int n;
vector<int> k;

void build(string &s){
	if(s[0] == '1') b[0] = 1;
	else if(s[0] == '?') c[0] = 1, k.push_back(0), b[0] = 0;
	else c[0] = 0, b[0] = 0;
	for(int i = 1;i < n;i++){
		b[i] = b[i - 1];
		c[i] = c[i - 1];
		if(s[i] == '1') b[i]++;
		if(s[i] == '?') k.push_back(i), c[i]++;
	}
	if(s[n - 1] == '0') a[n - 1] = 1;
	else if(s[n - 1] == '?') d[n - 1] = 1, a[n - 1] = 0;
	else d[n - 1] = 0, a[n - 1] = 0;
	for(int i = n - 2;i >= 0;i--){
		a[i] = a[i + 1];
		d[i] = d[i + 1];
		if(s[i] == '0') a[i]++;
		if(s[i] == '?') d[i]++;
	}
//	for(int i = 0;i < n;i++) cout << b[i] << " ";
}

ll solute(){
	e[0] = a[k[0]];
	for(int i = 1;i < k.size();i++){
		e[i] = e[i - 1] + a[k[i]];
	}
	for(int i = 0;i < k.size();i++){
		e[i] += ((i + 1) * (k.size() - i - 1LL));
	}
	f[k.size() - 1] = b[k.back()];
	for(int i = k.size() - 2;i >= 0;i--){
		f[i] = f[i + 1] + b[k[i]];
	}
	ll ans = max(e[k.size() - 1], f[0]);
//	for(int i = 0;i < k.size();i++) cout << e[i] << " ";
	for(int i = 0;i < k.size() - 1;i++){
		ans = max(ans, e[i] + f[i + 1]);
	}
//	cout << ans << endl;
	return ans;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	string s;
	ll ans;
	while(T--){
		ans = 0;
		k.clear();
		cin >> n >> s;
		build(s);
		
		if(k.size()) ans += solute();	
		for(int i = 0;i < n;i++){
//			cout << ans << ' ' << b[i] << " " << a[i] << endl;
			if(s[i] == '1') ans += a[i];
		}
		cout << ans << '\n';
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	ll n;
	int T;
	vector<ll> ans;
	cin >> T;
	while(T--){
		cin >> n;
		ans.clear();
		double t = sqrt(n);
		if(t == (int)t){
			cout << "0\n\n";
			continue;
		}
		int h = 62;
		for(;h >= 0 && !(n & (1LL << h));h--);
		h++;
//		cout << h << endl;
		if(h & 1) h++;
		for(int i = 0;i < h;i++){
			if(n & (1LL << i)){
				n += (1LL << i);
				ans.push_back(1LL << i);
			}
		}
		cout << ans.size() << '\n';
		for(ll &i : ans) cout << i << " ";
		cout << '\n';
	}
	
	return 0;
}
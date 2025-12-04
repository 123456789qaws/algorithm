#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	
	int T;
	string s;
	cin >> T;
	while(T--){
		cin >> s;
		int n = s.size();
		if(s[0] == s[n - 1]){
			int len1 = 1, be = 1, len2 = 1, en = n - 2;
			while(be < n && s[be] == s[0]){
				be++;
				len1++;
			}
			if(len1 == n){
				cout << n / 2 << '\n';
				continue;
			}
			while(en >= 0 && s[en] == s[0]){
				en--;
				len2++;
			}
			int len = len1 + len2;
			int cur = 1, ans = 0;
			bool flag = false;
			for(int i = be + 1;i <= en;i++){
				if(s[i] == s[i - 1]) cur++;
				else{
					if(!(cur & 1)) flag = true;
					ans += cur >> 1;
					cur = 1;
				}
			}
			if(!(cur & 1)) flag = true;
			ans += cur >> 1;
			if(!(len1 & 1) && !(len2 & 1)){
				cout << ans + len / 2 - 1 << '\n';
			}
			else if((len1 & 1) && (len2 & 1)){
				cout << ans + len1 / 2 + len2 / 2 << '\n';
			}
			else{
				if(flag){
					cout << ans + len / 2 - 1 << '\n';
				}
				else{
					cout << ans + len / 2 << '\n';
				}
			}		
		}
		else{
			int cur = 1, ans = 0;
			bool flag = false;
			for(int i = 1;i < n;i++){
				if(s[i] == s[i - 1]) cur++;
				else{
					if(!(cur & 1)) flag = true;
					ans += cur >> 1;
					cur = 1;
				}
			}
			if(!(cur & 1)) flag = true;
			ans += cur >> 1;
			cout << ans - flag << '\n';
		}	
	}
	
	
	return 0;
}
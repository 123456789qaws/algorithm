#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
int a[N], b[N], n;
char t;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		
		cin >> n;
		int aind = 0, bind = 0;
		for(int i = 2;i < n;i++){
			cin >> t;
			if(t == '1') a[aind++] = i;
			else b[bind++] = i;
		}
		
		if(bind == 0 || (bind == 1 && b[0] != n - 1)){
			cout << "-1\n";
			continue;
		}
		
		if(bind == 1) cout << n - 1 << '\n';
		else cout << n << '\n';
		
		cout << "1 " << b[0] << '\n';
		for(int i = 1;i < bind;i++){
			cout << b[i - 1] << " " << b[i] << '\n';
		}
		if(bind > 1) cout << "1 " << b[bind - 1] << '\n';
		if(aind){
			cout << "1 " << a[0] << '\n';
			for(int i = 1;i < aind;i++){
				cout << a[i - 1] << " " << a[i] << '\n';
			}
			cout << a[aind - 1] << " " << n << '\n';
		}
		else{
			cout << "1 " << n << '\n';
		}
		
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int n;
	cin >> n;
	if(n <= 3){
		if(n == 1){
			cout << "1\n1";
			return 0;
		}
		else if(n == 2){
			cout << "2\n1 1";
			return 0;
		}
		else if(n == 3){
			cout << "2\n2 2";
			return 0;
		}
	}
	cout << 2 * (n - 2) << endl;
	for(int i = 2;i < n;i++) cout << i << " ";
	for(int i = n - 1;i >= 2;i--) cout << i << " ";
	
	return 0;
}
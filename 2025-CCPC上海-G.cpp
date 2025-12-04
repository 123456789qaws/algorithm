#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, cur = 1;
//int build(){
//	bool is[3000];
//	memset(is, 1, sizeof(is));
//	is[0] = is[1] = false;
//	for(int i = 2;i < 3000;i++){
//		if(!is[i]) continue;
//		if(i > n) return i;
//		for(int j = i * i;j < 3000;j += i) is[j] = false;
//	}
//	return -1;
//}

//void test(int n){
//	int a[n][n];
//	for(int i = 0;i < n;i++){
//		for(int j = 0;j < n;j++){
//			int nx = i - 1 >= 0 ? a[i - 1][j] : 1, ny = j - 1 >= 0 ? a[i][j - 1] : 1;
//			while(__gcd(cur, nx) != 1 || __gcd(cur, ny) != 1) cur++;
//			a[i][j] = cur++;
//		}
//	}
//	for(int i = 0;i < n;i++){
//		for(int j = 0;j < n;j++){
//			cout << a[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	int p = build();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout << i * p + j + 1 << " ";
		}
		cout << '\n';
	}
	
//		int a[n][n];
//		for(int i = 0;i < n;i++){
//			if(i & 1){
//				for(int j = n - 1;j >= 0;j--){
//					int nx = i - 1 >= 0 ? a[i - 1][j] : 1, ny = j + 1 < n ? a[i][j + 1] : 1;
//					while(__gcd(cur, nx) != 1 || __gcd(cur, ny) != 1) cur++;
//					a[i][j] = cur++;
//				}
//			}
//			else{
//				for(int j = 0;j < n;j++){
//					int nx = i - 1 >= 0 ? a[i - 1][j] : 1, ny = j - 1 >= 0 ? a[i][j - 1] : 1;
//					while(__gcd(cur, nx) != 1 || __gcd(cur, ny) != 1) cur++;
//					a[i][j] = cur++;
//				}
//			}	
//		}
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				cout << a[i][j] << ' ';
//			}
//			cout << '\n';
//		}
	
//	for(int k = 1;k <= 10;k++){
//		cur = 1;
//		test(k);
//		cout << endl;
//	}
	
	return 0;
}
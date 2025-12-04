#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 1;
int a[N], n;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	map<int, int> ma;
	while(T--){
		cin >> n;
		ma.clear();
		int mmin = INT_MAX, mmax = INT_MIN;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			ma[a[i]]++;
			if(mmin > a[i]){
				mmin = a[i];
			}
			if(mmax < a[i]){
				mmax = a[i];
			}
			if(ma[mmax] == i - 1) cout << mmax * 2LL << " ";
			else cout << (long long)mmax + mmin << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
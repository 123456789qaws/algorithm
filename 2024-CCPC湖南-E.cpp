#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 1, M = (1 << 18);
int a[N], n;
int ma[N];

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 1;i <= n;i++){	
		for(int j = i, status = 0;j <= n && !((status >> (a[j] - 1)) & 1);j++){
			status |= (1 << (a[j] - 1));
			ma[status] = max(ma[status], j - i + 1);
			ans = max(ma[status], ans);
		}
	}
	
	for(int i = 0;i < M;i++){
		for(int j = i;j > 0;j = i & (j - 1)){
			ans = max(ans, ma[j] + ma[j ^ i]);
		}
	}
	
	cout << ans;
	      
	return 0;
}
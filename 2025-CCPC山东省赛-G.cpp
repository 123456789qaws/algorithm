#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int t, w, d;	
};
const int N = 2e5 + 1;
node a[N];

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0;i < n;i++){
			cin >> a[i].w >> a[i].t;
			a[i].d = a[i].t + k - a[i].w;
		}
		sort(a, a + n, [](node &a, node &b){
			return a.d < b.d;
		});
		for(int i = 1;i < n;i++){
			a[i].d = max(a[i].d, a[i - 1].d + 1);
		}
		cout << a[n - 1].d << '\n';
	}
	
	return 0;
}
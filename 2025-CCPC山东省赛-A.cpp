#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 1;
struct node{
	int a, b;
	int id;
};
node x[N];
int t, n;
vector<int> ans, t_ans;

bool check(int p){
	t_ans.clear();
	int sc = 0;
	for(int cur = 0;cur < n && sc < p;){	
	
		int i = cur + 1;
		while(i < n && x[i].a == x[i - 1].a) i++;
		int best = 0, large = min(i - cur, p - sc);
		
		for(int j = large;j >= 1;j--){
			int next = p - sc - j;
			if(next < 0) next = 0;
			if(next <= x[cur + j - 1].b){
				best = j;
				break;
			}
		}
		
		for(int j = 0;j < best;j++){
			t_ans.push_back(x[cur + j].id);
		}
		
		sc += best;
		cur = i;
	}
	return sc == p;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> t;
	while(t--){
		cin >> n;
		ans.clear();
		for(int i = 0;i < n;i++){
			cin >> x[i].a >> x[i].b;
			x[i].id = i + 1;
		} 
		sort(x, x + n, [](node &a, node &b){
			if(a.a == b.a) return a.b > b.b;
			return a.a < b.a;
		});
		int l = 1, r = n, mid;
		while(l <= r){
			mid = (l + r) >> 1;
			if(check(mid)){
				ans = t_ans;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << l - 1 << '\n';
		for(int i = 0;i < ans.size();i++){
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
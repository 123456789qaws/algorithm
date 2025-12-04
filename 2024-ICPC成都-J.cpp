#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
//using PII = pair<int, int>;
//#define fir first
//#define sec second

const int N = 1e5 + 1;
int n, m, q, op, id, x;
bool vis[N];
struct node{
	int id;
	ll cnt;
}a[N];

void clear(){
	for(int i = 1;i <= m;i++){
		a[i].id = i;
		a[i].cnt = 0;
	}
}

void solve(){
	
	cin >> n >> m >> q;
	clear();
	
	int lev = 0, val = m;
	while(q--){
		cin >> op;
		if(op == 1){
			cin >> lev;
			val = m;
			memset(vis, 0, sizeof(bool) * (m + 1));
		}
		else if(op == 2){
			cin >> id >> x;
			if(x != lev || vis[id]) continue;
			vis[id] = true;
			a[id].cnt += val--;
		}
		else{
			cin >> id >> x;
			if(x != lev || vis[id]) continue;
			vis[id] = true;
		}
	}
	
	sort(a + 1, a + 1 + m, [](node &a, node &b){
		if(a.cnt == b.cnt) return a.id < b.id;
		else return a.cnt > b.cnt;
	});
	
	for(int i = 1;i <= m;i++){
		cout << a[i].id << ' ' << a[i].cnt << '\n';
	}
	
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
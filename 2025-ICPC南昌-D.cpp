#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int x1, y1, z1;
	int x2, y2, z2;
};

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int n, ans = 0, f, g, h;
	cin >> n >> f >> g >> h;
	node a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i].x1 >> a[i].y1 >> a[i].z1 >> a[i].x2 >> a[i].y2 >> a[i].z2;
		if(a[i].x1 > a[i].x2) swap(a[i].x1, a[i].x2);
		if(a[i].y1 > a[i].y2) swap(a[i].y1, a[i].y2);
		if(a[i].z1 > a[i].z2) swap(a[i].z1, a[i].z2);
	}
	
	sort(a, a + n, [](node &a, node &b){
		return a.x1 < b.x1;
	});
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 0;i < n;i++){
		while(!q.empty() && q.top() < a[i].x1) q.pop();
		q.push(a[i].x2);
		ans = max((int)q.size(), ans);
	}
	while(!q.empty()) q.pop();
	
	sort(a, a + n, [](node &a, node &b){
		return a.y1 < b.y1;
	});
	for(int i = 0;i < n;i++){
		while(!q.empty() && q.top() < a[i].y1) q.pop();
		q.push(a[i].y2);
		ans = max((int)q.size(), ans);
	}
	while(!q.empty()) q.pop();
	
	sort(a, a + n, [](node &a, node &b){
		return a.z1 < b.z1;
	});
	for(int i = 0;i < n;i++){
		while(!q.empty() && q.top() < a[i].z1) q.pop();
		q.push(a[i].z2);
		ans = max((int)q.size(), ans);
	}

	cout << ans;
	
	return 0;
}
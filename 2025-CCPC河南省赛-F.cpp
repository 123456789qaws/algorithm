#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	//有序表
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a, a + n);
	multiset<ll> m;
	int i = 1;
	for(;i < k;i++){
		m.insert(a[i] - a[i - 1]);
	}
	m.insert(a[k - 1] - a[0]);
	ll ans = *m.rbegin() * *m.begin();
	for(i = k;i < n;i++){
		m.erase(m.find(a[i + 1 - k] - a[i - k]));
		m.erase(m.find(a[i - 1] - a[i - k]));  //原首尾
		m.insert(a[i] - a[i + 1 - k]);  //新首尾
		m.insert(a[i] - a[i - 1]);
		ans = min(ans, *m.rbegin() * *m.begin());
	}
	cout << ans;
	
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	//单调队列
	int n, k;
	cin >> n >> k;
	int a[n], b[n];
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a, a + n);
	deque<ll> q;
	for(int i = 1;i < n;i++) b[i] = a[i] - a[i - 1];
	int i = 1;
	for(;i < k;i++){
		while(!q.empty() && b[q.back()] >= b[i]) q.pop_back();
		q.push_back(i);
	}
	ll ans = (ll)(a[i - 1] - a[0]) * b[q.front()];
	for(i = k;i < n;i++){
		while(!q.empty() && b[q.back()] >= b[i]) q.pop_back();
		q.push_back(i);
		if(q.front() == i - k) q.pop_front();
		ans = min(ans, (long long)(a[i] - a[i - k + 1]) * b[q.front()]);
	}
	cout << ans;
	
	return 0;
}
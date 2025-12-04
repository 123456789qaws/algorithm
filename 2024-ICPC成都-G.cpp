#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
//using PII = pair<int, int>;
//#define fir first
//#define sec second

const int N = 1e5 + 1;
int n, t[N], a, b, c;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	set<int> se;
	
	for(int i = 0;i < n;i++){
		cin >> t[i];
		se.insert(t[i]);
	}
	for(int i = 1;i < n;i++){
		a = t[i] | t[i - 1];
		b = t[i] & t[i - 1];
		c = t[i] ^ t[i - 1];
		se.insert(a);
		se.insert(b);
		se.insert(c);
		se.insert(t[i] | c);
		se.insert(t[i] & c);
		se.insert(c | t[i - 1]);
		se.insert(c & t[i - 1]);
		se.insert(a | c);
		se.insert(a & c);
		se.insert(c | b);
		se.insert(c & b);
	}
	
	cout << se.size();
	
	return 0;
}
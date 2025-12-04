#include <bits/stdc++.h>
using namespace std;

bool findnext(string &s, int next[], int n){
	next[0] = 0;
	for(int i = 1, j = 0;i < n;i++){
		while(j && s[j] != s[i]) j = next[j - 1];
		if(s[i] == s[j]) j++;
		next[i] = j;
		if(j >= 1000) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	string s;
	cin >> s;
	int st = 1e3, en = 1e4, n = s.size();
	int next[n];
	if(findnext(s, next, n)) cout << "No";
	else cout << "Yes";
	
	return 0;
}
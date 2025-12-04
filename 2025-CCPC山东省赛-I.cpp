#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string, int> ma;
string stg = "012345678", eng = "012345678";
int t, cur = 1;
char nextchar;
queue<string> q;

void stand(){
	string next = "012345678";
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			if(stg[i] == eng[j]){
				next[j] = i + '0';
				break;
			}
		}
	}
	eng = next;
}

//void step1(string tg, int line){
//	int a = line * 3, b = a + 2;
//	char k = tg[a];
//	tg[a] = tg[b], tg[b] = tg[b - 1], tg[b - 1] = k;
//	if(ma.find(tg) != ma.end()) return;
//	ma[tg] = cur;
//	q.push(tg);
//}
//
//void step2(string tg, int row){
//	int a = row, b = 6 + a;
//	char k = tg[a];
//	tg[a] = tg[b], tg[b] = tg[b - 3], tg[b - 3] = k;
//	if(ma.find(tg) != ma.end()) return;
//	ma[tg] = cur;
//	q.push(tg);
//
//}

void step3(string tg){
	int a = tg[0];
	tg[0] = tg[6], tg[6] = tg[8], tg[8] = tg[2], tg[2] = a;
	int b = tg[1];
	tg[1] = tg[3], tg[3] = tg[7], tg[7] = tg[5], tg[5] = b;
	if(ma.find(tg) != ma.end()) return;
	ma[tg] = cur;
	q.push(tg);
}

void step(string tg, int lineorrow, int flag){
	int a, b;
	if(flag == 1) a = lineorrow * 3, b = a + 2;
	else a = lineorrow, b = 6 + a;
	char k = tg[a];
	tg[a] = tg[b], tg[b] = tg[b - flag], tg[b - flag] = k;
	if(ma.find(tg) != ma.end()) return;
	ma[tg] = cur;
	q.push(tg);
}

void bfs(){
	q.push(stg);
	string tg;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			tg = q.front(); q.pop();
			for(int i = 0;i < 3;i++) step(tg, i, 1);
			for(int i = 0;i < 3;i++) step(tg, i, 3);
			step3(tg);
		}	
		cur++;
	}
}

void build(){
	ma[stg] = 0;
	bfs();
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	build();
	cin >> t;
	while(t--){
		for(int i = 0;i < 9;i++){
			cin >> nextchar;
			stg[i] = nextchar - 1;
		} 
		for(int i = 0;i < 9;i++){
			cin >> nextchar;
			eng[i] = nextchar - 1;
		}
		stand();
		if(ma.find(eng) == ma.end()) cout << "-1\n";
		else cout << ma[eng] << '\n';
	}
	
	return 0;
}
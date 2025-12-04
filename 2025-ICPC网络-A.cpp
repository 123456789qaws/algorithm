#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
//using PII = pair<int, int>;
#define fir first
#define sec second

const int N = 1e5 + 1;
unordered_map<string, int> bh;
bool isac[N][26], isuk[N][26];
int isun[N][26], uktime[N][26], pay[N], numac[N], n, p, cur = 1;
string name, mapname[N];

struct node{
	string res;
	char th;
	int time, name;	
}a[N];


void clear(){
	for(int i = 1;i < cur;i++){
		pay[i] = numac[i] = 0;
		mapname[i] = "";
		for(int j = 0;j < 26;j++){
			isac[i][j] = isuk[i][j] = isun[i][j] = uktime[i][j] = 0;
		}
	}
	bh.clear();
	cur = 1;
}

void solve(){
	vector<string> ans;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> name >> a[i].th >> a[i].time >> a[i].res;
		a[i].th -= 'A';
		if(bh[name] == 0){
			mapname[cur] = name;
			bh[name] = cur++;
		}
		a[i].name = bh[name];
	}
	sort(a, a + n, [](node &i, node &j){
		return i.time < j.time;
	});
	
	for(int i = 0;i < n;i++){
		int tname = a[i].name;
		if(a[i].res == "Accepted"){
			if(isac[tname][a[i].th]) continue;
			isac[tname][a[i].th] = true;
			pay[tname] += isun[tname][a[i].th] * 20 + a[i].time;
			numac[tname]++;
		}
		else if(a[i].res == "Rejected"){
			if(isac[tname][a[i].th]) continue;
			isun[tname][a[i].th]++;
		}
		else{
			if(isac[tname][a[i].th] || isuk[tname][a[i].th]) continue;
			isuk[tname][a[i].th] = true;
			uktime[tname][a[i].th] = a[i].time;
		}
	}
	
	int best = 1;
//	cout << mapname[best] << endl;
	for(int i = 2;i < cur;i++){
		if(numac[i] > numac[best]) best = i;
		else if(numac[i] == numac[best] && pay[i] < pay[best]) best = i;
	}
	for(int i = 1;i < cur;i++){
		int ttime = 0, tac = 0;
		for(int j = 0;j < 26;j++){
			if(isuk[i][j] && !isac[i][j]){
				tac++;
				ttime += isun[i][j] * 20 + uktime[i][j];
			}
		}
		if(numac[i] + tac > numac[best]) ans.push_back(mapname[i]);
		else if(numac[i] + tac == numac[best] && pay[i] + ttime <= pay[best]) ans.push_back(mapname[i]);
	}
	sort(ans.begin(), ans.end());
	for(string &s : ans){
		cout << s << " ";
	}
	cout << '\n';
	
	clear();
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
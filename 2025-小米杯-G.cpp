#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
int n, spf[N], w[N], c[N];
vector<int> pr, tpr;
int dpc[N][2], dpl[N][2];

void build(){
	for(int i = 0;i < N;i++) dpc[i][0] = -1;
    for(int i = 2;i < N;i++) { 
        if(!spf[i]){
            spf[i] = i;
            pr.push_back(i);
        }
        for(int p : pr){
            ll v = 1LL * p * i;
            if(p > spf[i] || v >= N) break;
            spf[v] = p;
        }
    }
}

void find(int x) { 
    while(x > 1){
        int p = spf[x];
        tpr.push_back(p);
        while(x % p == 0) x /= p;
    }
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	 
	cin >> n;
	build();
	int ans = 0;
	for(int i = 0;i < n;i++) cin >> w[i];
	for(int i = 0;i < n;i++) cin >> c[i];
	for(int i = 0;i < n;i++){
		find(w[i]);
		
		int best = 0;
		for(int p : tpr){
			if(dpc[p][0] != c[i]) best = max(best, dpl[p][0]);
			else best = max(best, dpl[p][1]);
		}
		best++;
		for(int p : tpr){
			if(dpc[p][0] == c[i]) dpl[p][0] = max(dpl[p][0], best);
			else{
				if(best > dpl[p][0]){
//					dpc[p][1] = dpc[p][0];
					dpl[p][1] = dpl[p][0];
					dpc[p][0] = c[i];
					dpl[p][0] = best;
				}
				else if(best > dpl[p][1]){
//					dpc[p][1] = c[i];
					dpl[p][1] = best;
				}
			}
		}
		ans = max(best, ans);
		
		tpr.clear();
	}
	cout << ans << '\n';
	 
	return 0;
}
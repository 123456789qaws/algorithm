#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 4e5 + 1;
pair<int, int> a[N];  // 评级 
ll z[N]/*总得分*/, cnt[N]/*-1个数*/;
int n, k, m;

void clear(){
	for(int i = 0;i < n;i++) z[i] = cnt[i] = 0;
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		clear();
		int p[n][m];
		for(int i = 0;i < n;i++){
			cin >> a[i].first;
			a[i].second = i;
			for(int j = 0;j < m;j++){
				cin >> p[i][j];
				if(p[i][j] == -1) cnt[i]++;
				else z[i] += p[i][j];
			}
		}
		sort(a, a + n);
		ll last = 0, kl = a[0].first;
		int gg = 0;
		for(;gg < n;gg++){
			if(a[gg].first == a[0].first){
				for(int i = 0;i < m;i++) if(p[a[gg].second][i] == -1) p[a[gg].second][i] = 0;
				last = max(z[a[gg].second], last);
			}
			else break;
		}
		bool flag = true;
		ll nexth = 0;
		for(int i = gg;i < n;i++){
			int cur = a[i].second;
			ll ne = z[cur] - last;
			ne = ne > 0 ? 0 : 1 - ne;
			if(cnt[cur] * k < ne){
				flag = false;
				cout << "No\n";
				break;
			}
			ll d, t;
			if(cnt[cur]) d = ne / cnt[cur], t = ne % cnt[cur];
			else d = t = 0;
			for(int j = 0;j < m;j++){
				if(p[cur][j] == -1){
					p[cur][j] = d + (t > 0 ? 1 : 0);
					t--;
					z[cur] += p[cur][j];
				}
			}
			nexth = max(nexth, z[cur]);
			if(i + 1 < n && a[i + 1].first != a[i].first){
				last = nexth;
			}
		}
		if(!flag) continue;
		cout << "Yes\n";
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cout << p[i][j] << " ";
			}
			cout << '\n';
		}
	}
	
	
	return 0;
}
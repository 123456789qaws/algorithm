#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int, int>;

const int N = 5e5 + 5, M = 2e3 + 5, mod = 1e9 + 7;
int n, m, k, q;
vector<vector<int>> a(M, vector<int>(M));
vector<vector<int>> g(M);
vector<int> cnt(M), vis(M);

void solve(){

	cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            cin >> a[i][j];
        }
    }

    cnt[0] = INT_MAX;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            int lca = a[i][j] ^ (a[1][i] ^ a[1][j]);
            if(lca == i){
                g[j].push_back(i);
                cnt[i]++;
            }
            if(lca == j){
                g[i].push_back(j);
                cnt[j]++;
            }
        }
    }

    queue<int> q;
    for(int i = 1;i <= n;i++) if(!cnt[i]) q.push(i);

    while(!q.empty()){

        int x = q.front(); q.pop();
        if(x == 1) break;

        int px = 0;
        for(int nx : g[x]){
            if(cnt[nx] < cnt[px]) px = nx;
        }
        cout << px << ' ' << x << '\n';

        for(int nx : g[x]){
            if(--cnt[nx] == 0) q.push(nx);
        }

    }

    /**
     * 题解思路 : 利用 拓扑排序 + dp 求深度, 再根据 深度和祖先关系 找边
     */
    

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
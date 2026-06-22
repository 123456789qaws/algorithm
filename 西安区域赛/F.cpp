#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int, int>;

const int N = 5e5 + 5, mod = 1e9 + 7;
int n, m, k, q, u, v;
vector<int> a(N), t(N), op(N), stop(N), vis(N);
vector<int> s[N];

void solve(){

	cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t[i];
        s[t[i]].push_back(i);
        vis[i] = -1;
    }
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        if(t[i] == i) op[i] = 0;
        else if(a[t[i]] > a[i]) op[i] = 1;
        else op[i] = -1;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1;i <= n;i++){
        int x = i, nx = t[x];
        if(nx == x) pq.push({0, x});
        else if(op[nx] == -op[x]) pq.push({abs(a[x] - a[nx]), x});
    }

    while(!pq.empty()){
        auto [time, x] = pq.top(); pq.pop();
        if(vis[x] != -1){
            pq.push({(abs(a[x] - a[t[x]]) - vis[x]) * 2 + vis[x], x});
            vis[x] = -1;
            continue;
        }
        for(int ex : s[x]){
            if(op[ex] != -op[x]) pq.push({abs(a[ex] - a[x]) * 2 + time, ex});
            else vis[ex] = time;
        }
        stop[x] = time;
    }

    for(int i = 1;i <= n;i++) cout << stop[i] << " ";

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int, int>;

const int N = 3e5 + 5, mod = 1e9 + 7;
int n, m, k, q, u, v;
vector<int> a(N), vis(N), pre(N), lca(N), sum(N), x(N), y(N);
vector<int> tree[N];
vector<pii> query[N];

void clear(){
    for(int i = 1;i <= n;i++){
        tree[i].clear();
        query[i].clear();
    }
    fill(vis.begin() + 1, vis.begin() + n + 1, 0);
    fill(sum.begin() + 1, sum.begin() + n + 1, 0);
}

int root(int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void dfs(int cur, int fa, int psum){

    vis[cur] = true;
    sum[cur] += psum;

    // 初始化前缀和数组
    int minx = 0, min1 = INT_MAX, min2 = INT_MAX;
    for(int nx : tree[cur]){
        if(nx == fa) continue;
        if(a[nx] <= min1){
            min2 = min1;
            min1 = a[nx];
            minx = nx;
        }
        else if(a[nx] < min2) min2 = a[nx];
    }
    for(int nx : tree[cur]){
        if(nx == fa) continue;
        if(nx == minx) sum[nx] = min2;
        else sum[nx] = min1;
    }

    // tarjan 求 lca
    for(int nx : tree[cur]){
        if(nx == fa) continue;
        dfs(nx, cur, sum[cur]);
        pre[nx] = cur;
    }
    for(pii &t : query[cur]){
        if(vis[t.first]) lca[t.second] = root(t.first);
    }

}

void dfs(int cur, int fa){
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int nx : tree[cur]){
        if(nx == fa) continue;
        dfs(nx, cur);
        if(a[nx] <= min1){
            min2 = min1;
            min1 = a[nx];
        }
        else if(a[nx] < min2) min2 = a[nx];
    }
    a[cur] = min(a[cur], min1 + min2);
}

void solve(){

	cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        pre[i] = i;
    }
    for(int i = 1;i < n;i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i = 1;i <= m;i++){
        cin >> x[i] >> y[i];
        query[x[i]].push_back({y[i], i});
        query[y[i]].push_back({x[i], i});
    }
    
    dfs(1, 0);
    dfs(1, 0, 0);

    for(int i = 1;i <= m;i++){
        if(lca[i] != y[i]) cout << "-1\n";
        else cout << sum[x[i]] - sum[y[i]] << '\n';
    }

    clear();

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
    solve();

    return 0;
}
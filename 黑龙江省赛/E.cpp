#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e5 + 5, mod = 1e9 + 7, MAXN = 2LL * INT_MAX + 1LL;
int n, m, k, q, x, y, op, a, b, v;
vector<vector<int>> g(N);
vector<bool> is(N);
vector<int> dfn(N), dep(N), siz(N, 1);
// 线段树
vector<int> minv(N << 2, MAXN), x1(N << 2, MAXN), add(N << 2);

void build(int l, int r, int cur){
    if(l == r){
        add[cur] = dep[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur << 1), build(mid + 1, r, cur << 1 | 1);
}

void lazy(int cur, ll v){
    add[cur] += v;
    minv[cur] += v;
}

void down(int cur){
    if(add[cur]){
        lazy(cur << 1, add[cur]);
        lazy(cur << 1 | 1, add[cur]);
        add[cur] = 0;
    }
}

void addn(int l, int r, int cur){

    if(l >= a && r <= b){
        lazy(cur, v);
        return;
    }

    int mid = (l + r) >> 1;
    down(cur);

    if(a <= mid) addn(l, mid, cur << 1);
    if(b > mid) addn(mid + 1, r, cur << 1 | 1);

    minv[cur] = min(minv[cur << 1], minv[cur << 1 | 1]);

}

void update(int l, int r, int cur){

    if(l == r){
        if(x1[cur] == MAXN) x1[cur] = add[cur];
        else x1[cur] = MAXN;
        minv[cur] = x1[cur];
        return;
    }

    int mid = (l + r) >> 1;
    down(cur);

    if(a <= mid) update(l, mid, cur << 1);
    else update(mid + 1, r, cur << 1 | 1);

    minv[cur] = min(minv[cur << 1], minv[cur << 1 | 1]);

}


int dfnid = 1;
void dfs(int root, int fa, int depth){
    dfn[root] = dfnid++;
    dep[dfn[root]] = depth;
    for(int nx : g[root]){
        if(nx == fa) continue;
        dfs(nx, root, depth + 1);
        siz[root] += siz[nx];
    }
}

void solve(){

    cin >> n >> m;
    for(int i = 1;i < n;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0, 0);
    build(1, n, 1);

    int cur = 1;
    while(m--){
        cin >> op >> x;
        if(op == 1){
            a = dfn[x], update(1, n, 1);
        }
        else{
            if(dfn[x] > dfn[cur] && dfn[x] < dfn[cur] + siz[cur]){
                v = 1, a = 1, b = n, addn(1, n, 1);
                v = -2, a = dfn[x], b = dfn[x] + siz[x] - 1, addn(1, n, 1);
            }
            else{
                v = -1, a = 1, b = n, addn(1, n, 1);
                v = 2, a = dfn[cur], b = dfn[cur] + siz[cur] - 1, addn(1, n, 1);
            }
            cur = x;
        }
        cout << min(minv[1], INT_MAX + 1LL) << '\n';
    }

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
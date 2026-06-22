#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 3e3 + 5, mod = 1e9 + 7;
int n, m, k, q, u, v;
vector<int> tree[N], path[N];
struct node{
    int op;
    int tim;
    int s, t;
};
vector<node> a(N);
vector<bool> alive(N, true);
vector<int> cur(N);
vector< vector<array<vector<int>, 5>> > tn(2, vector< array<vector<int>, 5> >(N));

bool dfs(int root, int fa, int x){
    if(root == a[x].t) return true;
    for(int nx : tree[root]){
        if(nx == fa) continue;
        path[x].push_back(nx);
        if(dfs(nx, root, x)) return true;
        path[x].pop_back();
    }
    return false;
}

void solve(){

    cin >> n >> m;
    for(int i = 1;i < n;i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int kk = 0; bool kkd = false;
    for(int i = 1;i <= m;i++){
        cin >> a[i].op >> a[i].tim >> a[i].s >> a[i].t;
        if(a[i].op == 1) kk = i;
    }

    for(int i = 1;i <= m;i++) path[i].push_back(a[i].s), dfs(a[i].s, 0, i);

    vector<int> ans;
    for(int i = 1;i <= m;i++) if(a[i].s == a[i].t) alive[i] = false, ans.push_back(i);
    for(int ti = 1;ti <= n;ti++){
        for(int i = 1;i <= n;i++) for(int j = 1;j <= 4;j++) tn[ti & 1][i][j].clear();
        for(int i = 1;i <= m;i++){
            if(!alive[i]) continue;
            cur[i]++;
            if(cur[i] + 1 >= path[i].size()){
                alive[i] = false;
                ans.push_back(i);
            }
            else{
                tn[ti & 1][path[i][cur[i]]][a[i].op].push_back(i);
            }
        }
        // auto ttn = tn[ti & 1];
        for(int i = 1;i <= n;i++){
            if(tn[ti & 1][i][2].size()){
                for(int check : tn[ti & 1][i][2]){
                    if(ti % a[check].tim == 0){
                        if(tn[ti & 1][i][1].size()){
                            alive[kk] = false;
                            kkd = true;
                        }
                        break;
                    }
                }
            }
            if(tn[ti & 1][i][3].size()){
                for(int check : tn[ti & 1][i][3]){
                    if(ti % a[check].tim == 0){
                        for(int dead : tn[ti & 1][i][2]) alive[dead] = false;
                        break;
                    }
                }
            }
            if(tn[ti & 1][i][4].size()){
                int cnt = 0; int tjl = 0;
                for(int check : tn[ti & 1][i][4]){
                    if(ti % a[check].tim == 0){
                        cnt++;
                        tjl = check;
                    }
                }
                if(cnt) for(int dead : tn[ti & 1][i][2]) alive[dead] = false;
                if(cnt) for(int dead : tn[ti & 1][i][3]) alive[dead] = false;
                if(cnt >= 2) for(int dead : tn[ti & 1][i][4]) alive[dead] = false;
                else if(cnt){
                    for(int dead : tn[ti & 1][i][4]){
                        if(dead == tjl) continue;
                        alive[dead] = false;
                    }
                }
            }
            if(!kkd && ti % a[kk].tim == 0 && tn[ti & 1][i][1].size()){
                for(int dead : tn[ti & 1][i][2]) alive[dead] = false;
                for(int dead : tn[ti & 1][i][3]) alive[dead] = false;
                for(int dead : tn[ti & 1][i][4]) alive[dead] = false;
            }
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int x : ans) cout << x << '\n';

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int, int>;

const int N = 2e6 + 5, M = 2e3 + 5, mod = 1e9 + 7;
int n, m, k, q;
vector<vector<int>> a(N, vector<int>(5));
string s;

int sum(int l, int r, int op){
    return a[r][op] - a[l - 1][op];
}

int myfind(int l, int r, int i){
    char c = i == 1 ? 'C' : (i == 2 ? 'W' : 'P');
    int t = 2 * sum(l, r, i) - (sum(l, r, 1) + sum(l, r, 2) + sum(l, r, 3));
    t += (int)(s[l - 1] == c) + (int)(s[r + 1] == c);
    return t;
}

int myfind2(int v[], int l, int r, int i){
    char c = i == 1 ? 'C' : (i == 2 ? 'W' : 'P');
    int t = 2 * v[i] - (v[1] + v[2] + v[3]);
    t += (int)(s[l - 1] == c) + (int)(s[r + 1] == c);
    return t;
}

bool check(int l, int r){
    int res = -100;
    for(int i = 1;i <= 3;i++){
        res = max(res, myfind(l, r, i));
    }
    return res <= 1;
}

void put(int l, int r){
    int v[5] = {0, myfind(l, r, 1), myfind(l, r, 2), myfind(l, r, 3)};
    int c[5] = {0, 'C', 'W', 'P'}; map<char, int> mp = {{'C', 1}, {'W', 2}, {'P', 3}};
    int num[5] = {0, sum(l, r, 1), sum(l, r, 2), sum(l, r, 3)};
    for(int i = l;i <= r;i++){
        v[1] = myfind2(num, i, r, 1), v[2] = myfind2(num, i, r, 2), v[3] = myfind2(num, i, r, 3);
        sort(c + 1, c + 4, [&](int a, int b){
            return v[mp[a]] > v[mp[b]];
        });
        for(int j = 1;j <= 3;j++){
            char nc = c[j];
            if(num[mp[nc]] && s[i - 1] != nc && (i != r || s[r + 1] != nc)){
                s[i] = nc;
                num[mp[nc]]--;
                break;
            }
        }
    }
}

void solve(){

	cin >> n >> s; s = " " + s;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 3;j++) a[i][j] = a[i - 1][j];
        if(s[i] == 'C') a[i][1]++;
        if(s[i] == 'W') a[i][2]++;
        if(s[i] == 'P') a[i][3]++;
        if(s[i] == s[i - 1]) flag = false;
    }
    if(flag){
        cout << "Beautiful\n";
        return;
    }
    if(max({a[n][1], a[n][2], a[n][3]}) > (n + 1) / 2){
        cout << "Impossible\n";
        return;
    }

    int l = 2, r = n - 1;
    for(;l <= n && s[l - 1] != s[l];l++);
    for(;r >= 1 && s[r + 1] != s[r];r--);
    // if(r == l - 1) r = l + 1;
    // cout << l << " " << r << endl;

    int ansl = 1, ansr = n;
    for(int i = 1, j = r;i <= l;i++){
        while(j < n && (j <= i || !check(i, j))) j++;
        if(i < j && check(i, j)){
            if(j - i + 1 < ansr - ansl + 1){
                ansl = i, ansr = j;
            }
        }
    }

    cout << "Possible\n";
    cout << ansl << " " << ansr << '\n';
    put(ansl, ansr);
    cout << s.substr(1) << '\n';

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
    solve();

    return 0;
}

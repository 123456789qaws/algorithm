#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e5 + 5, mod = 998244353;
int n, m, k, q;

void solve(){

    string x;
    cin >> x;

    string l = x.substr(0, x.find("."));
    string r = x.substr(x.find(".") + 1);
    // cout << l << endl << r << endl << endl;
    // return;
    int zs = stoll(l);
    int xs = stoll(r);

    zs = zs * 2 - 1;
    zs = zs * 2 - 1;
    xs *= 4;
    zs += xs / 100;

    // cout << zs << " . " << xs << endl;
    cout << zs << "." << (xs % 100 < 10 ? "0" : "") << xs % 100 << '\n';

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
    solve();

    return 0;
}
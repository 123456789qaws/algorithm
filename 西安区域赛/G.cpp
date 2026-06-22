#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e6 + 5, mod = 1e9 + 7;
int n, m, k, q;
vector<int> a(N);

void solve(){

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    m  = 0;
    sort(a.begin() + 1, a.begin() + n + 1);
    for(int i = 1;i <= n;i++){
        if(m >= a[i]) m++;
        else m--;
    }
    cout << m << " ";

    m  = 0;
    for(int i = n;i >= 1;i--){
        if(m >= a[i]) m++;
        else m--;
    }
    cout << m << "\n";

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int T; cin >> T;
    // while(T--)
    solve();

    return 0;
}
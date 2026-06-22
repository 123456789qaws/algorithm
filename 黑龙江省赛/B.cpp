#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e6 + 5, mod = 1e9 + 7;
int n, m, k, q, l, r;
string sl, sr;

int ksm(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve(){

    cin >> l >> r;
    sl = to_string(l), sr = to_string(r);
    
    int res = 0;
    if(r - l >= 10) res = 9;
    else{
        for(int i = l;i <= r;i++){
            string t = to_string(i);
            for(char c : t) res = max(res, c - '0' + 0LL);
        }
    }

    cout << res << " ";

    while(sr.size() > sl.size()){
        if(r - ksm(10, sr.size() - 1) >= res){
            cout << 1 << string(sr.size() - 2, '0') << res << '\n';
            return;
        }
        else{
            sr = sr.substr(1);
            for(char &c : sr) c = '9';
            r = stoll(sr);
        }
    }

    for(int i = l;i <= r;i++){
        string t = to_string(i);
        for(char c : t) if(c - '0' == res){
            cout << t << '\n';
            return;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
    solve();

    return 0;
}
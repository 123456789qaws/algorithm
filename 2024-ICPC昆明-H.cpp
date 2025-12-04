#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define double long double
const int N = 2e5 + 1; 

const double pi = 3.1415926546, pi2 = 6.2831853072;
int n, k, x, y;
double a[N];

void solve() {
	
    cin >> n >> k;
    if(n == k){
	    for (int i = 0; i < n; i++) cin >> x >> y;
	    cout << pi2 << '\n';
	    return;
    }
    
    for (int i = 0; i < n; i++){
    	cin >> x >> y;
    	a[i] = atan2(y, x);
    	if(a[i] < 0) a[i] += pi2;
	}
    sort(a, a + n);
    
    double ans = -1000;
    for(int i = 0;i < n;i++){
        double t = a[(k + i) % n] - a[i];
        if(t < 0) t += pi2;
        else if(t == 0 && k + i >= n) t += pi2;
        ans = max(ans, t);
    }
    
    cout << ans << '\n';
    
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	
    int _ = 1;
    cin >> _;
    while(_--){
        solve();
    }
    
    return 0;
}
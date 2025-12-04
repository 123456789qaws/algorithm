#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define double long double

const int N = 1e5 + 1;
const double eps = 1e-8;
pair<int, int> point[N];
int n;
double a, b, c, base1, base2;

double dis(pair<int, int> &i){
	return fabs(a * i.x + b * i.y + c) / base1;
}

double findy(double x, double y) {
    return y - ( b * (a * x + b * y + c) / base2 );
}

double findx(double x, double y) {
    return x - ( a * (a * x + b * y + c) / base2 );
}

bool check(double m){
	double l = -1e18, r = 1e18;
	for(int i = 0;i < n;i++){
		double h = dis(point[i]);
		if(h > m + eps) return false;
		double p = b ? findx(point[i].x, point[i].y) : findy(point[i].x, point[i].y);
		double len = b ? sqrt( (m * m - h * h) / ( 1 + (a * a) / (b * b) ) ) : sqrt( (m * m - h * h) / ( 1 + (b * b) / (a * a) ) );
		l = max(l, p - len);
		r = min(r, p + len);
		if(l >= r + eps) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(12);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0;i < n;i++) cin >> point[i].x >> point[i].y;
		cin >> a >> b >> c;
		base1 = sqrt(a * a + b * b);
		base2 = (a * a + b * b);
		double l = 0, r = 1e5, mid;
		while(l <= r - eps){
			mid = (l + r) / 2;
			if(check(mid)) r = mid - eps;
			else l = mid + eps;
		}
		cout << r + eps << '\n';
	}
	
	return 0;
}
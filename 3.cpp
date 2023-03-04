#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int , int>
#define PLI pair<LL  , int>
#define PLL pair<LL , LL>
#define bit(x) (1<<x)
#define bitl(x) (1LL<<x)
#define cnti(x) (__builtin_ctz(x))
#define cntl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzll(x) (__builtin_clzll(x))

#define Error(x) cerr<<#x<<" = "<<x<<endl;

#define mx 200010
int cnt[mx];

int main() {
	int n;	cin >> n;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n / i; j ++) {
			cnt[i * j] ++;
		}
	}
	LL ans = 0;
	for (int i = 1; i < n; i ++) ans += 1LL * cnt[i] * cnt[n - i];
	cout << ans << endl;
}

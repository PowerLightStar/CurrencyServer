#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
#pragma GCC optimize("O2")
void init() {
	
}
const int mxN = 501;
int a[mxN];
int dp[2][mxN][mxN][2];
inline void chmin(int &lhs, int rhs) {
	lhs = min(lhs, rhs);
}
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	// dp[position][current value][took how many subarrays][taking now]
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= n; k++) {
			dp[0][j][k][0] = dp[0][j][k][1] = n + 1;
			dp[1][j][k][0] = dp[1][j][k][1] = n + 1;
		}
	}
	dp[0][0][0][0] = 0;
	for (int pos = 1; pos <= n; pos++) {
		for (int val = 0; val <= n; val++) {
			if (val == a[pos]) continue;
			// must take now
			for (int took = 1; took <= n; took++) {
				chmin(dp[1][val][took][1], dp[0][val][took][1] + 1);
				chmin(dp[1][val][took][1], dp[0][val][took - 1][0] + 1);
			}
		}
		// must not take now
		for (int took = 0; took <= n; took++) {
			for (int prev = 0; prev < a[pos]; prev++) {
				chmin(dp[1][a[pos]][took][0], dp[0][prev][took][0]);
				chmin(dp[1][a[pos]][took][0], dp[0][prev][took][1]);
			}
		}
		// update
		for (int val = 1; val <= n; val++) {
			for (int took = 0; took <= n; took++) {
				chmin(dp[1][val][took][0], dp[1][val - 1][took][0]);
				chmin(dp[1][val][took][1], dp[1][val - 1][took][1]);
			}
		}
		for (int val = 0; val <= n; val++) {
			for (int took = 0; took <= n; took++) {
				dp[0][val][took][0] = dp[1][val][took][0];
				dp[0][val][took][1] = dp[1][val][took][1];
 
				dp[1][val][took][0] = n + 1;
				dp[1][val][took][1] = n + 1;
			}
		}
	}
	int ans = n + 1;
	for (int val = 1; val <= n; val++) {
		chmin(ans, dp[0][val][0][0]);
		chmin(ans, dp[0][val][0][1]);
	}
	for (int took = 1; took <= n; took++) {
		for (int val = 1; val <= n; val++) {
			chmin(ans, dp[0][val][took][0]);
			chmin(ans, dp[0][val][took][1]);
		}
		cout << ans << ' ';
	}
	cout << endl;
}
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t = 1;
	cin >> t;
	while (t--) solve();
}
//BOJ 27519 소수의 합
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int n;
	long long int dp[100001] = { 0 };
	bool isVisited[100001] = { false };

	for (int i = 2; i <= sqrt(100000); i++) {
		if (!isVisited[i]) {
			for (int j = i + i; j <= 100000; j += i) {
				isVisited[j] = true;
			}
		}
	}

	for (int i = 2; i <= 100000; i++) {
		if (!isVisited[i]) {
			dp[i] += 1;
			for (int j = 2; j + i <= 100000; j++) {
				if (j + i <= 100000) {
					dp[j + i] += dp[j];
					dp[j + i] %= 1000000007;
				}
			}
		}
	}
	cin >> T;
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}
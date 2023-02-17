// BOJ 11066 파일 합치기
#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, K;
	vector<vector<int>> dp;
	vector<int> intervalSum;

	cin >> T;
	while (T--) {
		cin >> K;
		dp = vector<vector<int>>(K + 1, vector<int>(K + 1, 999999999));
		intervalSum = vector<int>(K + 1);
		cin >> intervalSum[1];
		dp[1][1] = 0;
		for (int i = 2; i <= K; i++) {
			cin >> intervalSum[i];
			dp[i][i] = 0;
			intervalSum[i] += intervalSum[i - 1];
		}
		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= K - i; j++) {
				for (int k = j; k < j + i; k++) {
					dp[j][j + i] = min(dp[j][j+i], dp[j][k] + dp[k + 1][j + i] + intervalSum[j + i] - intervalSum[j - 1]);
				}
			}
		}
		cout << dp[1][K] << '\n';
	}
}
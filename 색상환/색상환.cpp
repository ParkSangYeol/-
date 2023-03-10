//BOJ 2482 »ö»óÈ¯
#include <iostream>
#define DIV_NUM 1000000003
using namespace std;

int main() {
	int N, K;
	long long int dp[1001][1001];

	cin >> N >> K;
	if (K > N / 2) {
		cout << 0;
	}
	else {
		dp[0][0] = dp[1][0] = dp[1][1] = 1;
		for (int i = 2; i < N; i++) {
			dp[i][0] = 1;
			dp[i][i] = 0;
			for (int j = 1; j < i; j++) {
				dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % DIV_NUM;
			}
		}
		cout << (dp[N - 3][K - 1] + dp[N - 1][K])%DIV_NUM;
	}
}
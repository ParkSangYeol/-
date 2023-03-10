//BOJ 14002 가장 긴 증가하는 부분 수열 4
#include <iostream>
using namespace std;

int main() {
	int N, maxSIze = 1, maxIndex = 0;
	int indexArr[1000];
	int valueArr[1000];
	int dp[1000];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> valueArr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		dp[i] = 1;
		indexArr[i] = i;
		for (int j = i; j < N; j++) {
			if (valueArr[i] < valueArr[j] && dp[i] < dp[j] + 1) {
				indexArr[i] = j;
				dp[i] = dp[j] + 1;
				if (maxSIze < dp[i]) {
					maxSIze = dp[i];
					maxIndex = i;
				}
			}
		}
	}

	cout << maxSIze << '\n';
	while (true) {
		cout << valueArr[maxIndex] << ' ';
		if (indexArr[maxIndex] == maxIndex) {
			break;
		}
		maxIndex = indexArr[maxIndex];
	}
}
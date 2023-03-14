#include <iostream>
using namespace std;

int main() {
	int N;
	int numOfDigits = 0;
	int digit[10];
	long long int ans[10] = { 0 };
	int dp[10][10] = { 0 }; // 0부터 10^(첫번째 인수)-1 까지 에서 (두번째 인수)의 등장횟수

	int num = 1;
	
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] += num;
		}

		for (int j = 0; j < 10; j++) {
			dp[i][j] += (num / 10) * (i - 1) * 9;
		}
		for (int j = 0; j < 10; j++) {
			dp[i][j] += dp[i - 1][j];
		}

		num *= 10;
	}

	cin >> N;
	int temp = N;
	while (temp) {
		digit[numOfDigits] = temp % 10;
		temp /= 10;
		numOfDigits++;
	}
	if (numOfDigits == 1) {
		for (int i = 1; i <= digit[0]; i++) {
			ans[i] = 1;
		}
	}
	else {
		num = 1;
		for (int i = 0; i < 10; i++) {
			ans[i] += dp[numOfDigits - 1][i];
		}

		for (int i = 0; i <= digit[0]; i++) {
			ans[i] += 1;
		}
		for (int i = 1; i < numOfDigits - 1; i++) {
			for (int j = 0; j < 10; j++) {
				ans[j] += (long long int)num * i * digit[i];
			}
			for (int j = 0; j < digit[i]; j++) {
				ans[j] += (long long int)num * 10;
			}
			num *= 10;
			ans[digit[i]] += (long long int) (N % num) + 1;
		}

		for (int i = 0; i < 10; i++) {
			ans[i] += (long long int)num * (numOfDigits - 1) * (digit[numOfDigits-1] -1);
		}
		for (int j = 1; j < digit[numOfDigits - 1]; j++) {
			ans[j] += (long long int)num * 10;
		}
		num *= 10;
		ans[digit[numOfDigits - 1]] += (long long int) (N % num) + 1;
	}

	for (int i = 0; i < 10; i++) {
		cout << ans[i] << ' ';
	}

}
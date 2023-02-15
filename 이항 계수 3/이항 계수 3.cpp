//BOJ 11401 이항 계수 3
#include <iostream>
#include <vector>
#define DIVIDE_NUM 1000000007
using namespace std;

long long int square(long long int n, int s) {
	if (s == 1) {
		return n;
	}
	long long int temp = square(n, s / 2);
	if (s & 1) {
		temp = temp * temp % DIVIDE_NUM;
		return temp * n % DIVIDE_NUM;
	}
	else {
		return temp * temp % DIVIDE_NUM;
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	if (N / 2 < K) {
		K = N - K;
	}

	long long int numerator = 1;
	long long int denominator = 1;
	for (int i = N - K + 1; i <= N ; i++) {
		numerator *= i;
		numerator %= DIVIDE_NUM;
	}
	for (int i = 1; i <= K; i++) {
		denominator *= i;
		denominator %= DIVIDE_NUM;
	}
	denominator = square(denominator, DIVIDE_NUM - 2);
	cout << numerator * denominator % DIVIDE_NUM;
}
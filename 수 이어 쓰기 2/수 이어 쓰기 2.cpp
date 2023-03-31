//BOJ 1790 수 이어 쓰기 2
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, K, digit = 1;
	int current = 0;

	cin >> N >> K;
	while (K - (digit * pow(10, digit - 1) * 9) >= 0) {
		K -= (digit * pow(10, digit - 1) * 9);
		current += pow(10, digit++ - 1) * 9;
	}
	current += K / digit;
	if (digit != 1) {
		if (K % digit) {
			current += 1;
			K = digit - K % digit;
			if (current > N)
				cout << -1;
			else {
				while (K--) {
					current /= 10;
				}
				cout << current % 10;
			}
		}
		else {
			cout << current % 10;
		}
	}
	else {
		if (current > N)
			cout << -1;
		else {
			cout << current % 10;
		}
	}

}
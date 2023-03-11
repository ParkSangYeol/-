//A¹ø ÆËÇÉ ¼Ò´Ù
#include <iostream>
using namespace std;

int main() {
	int N, M, K, maxCount = 0, ans = 0;
	cin >> N >> M >> K;

	while (N != 1) {
		N = N >> 1;
		maxCount++;
	}
	K--;
	while (true) {
		if (ans == maxCount || (M == 0 && K == 0))
			break;
		if (K != 0) {
			K--;
			K /= 2;
		}
		else {
			M--;
		}
		ans++;
	}
	cout << ans;
}
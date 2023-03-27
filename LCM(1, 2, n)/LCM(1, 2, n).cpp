//BOJ 11690 LCM(1, 2, ..., n)
#include <iostream>
#include <vector>
#define DIV_NUM 4294967296
using namespace std;

int main() {
	int n;
	long long int ans = 1;
	cin >> n;
	vector<bool> isChecked(n + 1, false);
	
	for (int i = 2; i <= n; i++) {
		if (!isChecked[i]) {
			int temp = i;
			for (int j = i; j <= n; j += i) {
				isChecked[j] = true;
				if (temp == j) {
					ans *= i;
					ans %= DIV_NUM;
					temp *= i;
				}
			}
		}
	}

	cout << ans;
}
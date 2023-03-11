//B 지수를 더하자
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	long long int K;
	long long int ans = 0;
	vector<long long int> P(200000);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	cin >> K;

	for (int i = 0; i < N; i++) {
		long long int temp = K;
		while (temp != 0) {
			temp = temp / P[i];
			ans += temp;
		}
	}
	cout << ans;
}
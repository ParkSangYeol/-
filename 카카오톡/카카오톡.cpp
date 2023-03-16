#include <iostream>
#include <map>
using namespace std;

int getGCD(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int a, b, c;
	long long int ans = 0;
	map<pair<int, int>, int> mp;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		pair<int, int> p;
		if (a == 0) {
			p = { 0,1 };
		}
		else if (b == 0) {
			p = { 1,0 };
		}
		else {
			int gcd = getGCD(a, b);
			a /= gcd;
			b /= gcd;
			p = { a, b };
		}

		auto iter = mp.find(p);
		if (iter != mp.end()) {
			ans += i - (iter->second)++;
		}
		else {
			mp[p] = 1;
			ans += i;
		}
	}

	cout << ans;
}
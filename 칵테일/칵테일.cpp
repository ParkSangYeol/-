//BOJ 1033 Ä¬Å×ÀÏ
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int N;
	long long int a, b, p, q;
	long long int ans[10];

	cin >> N;
	vector<vector<long long int>> edges(N, vector<long long int>());
	for (int i = 0; i < N; i++) {
		ans[i] = 1;
	}

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> p >> q;
		if (p < q) {
			swap(a, b);
			swap(p, q);
		}

		long long int tempGCD = gcd(p, q);
		p /= tempGCD;
		q /= tempGCD;

		tempGCD = gcd(ans[b], q);
		long long int tempLCM = ans[b] * p / tempGCD;
		tempGCD = gcd(tempLCM, ans[a]);

		long long int tempA = ans[a];
		long long int tempB = ans[b];
		ans[a] = ans[a] * tempLCM / tempGCD;
		ans[b] = ans[a] * q / p;

		long long int temp = ans[a] / tempA;
		vector<bool> visited(N, false);
		visited[a] = visited[b] = true;
		queue<int> que;
		que.push(a);
		while (!que.empty()) {
			int current = que.front();
			que.pop();
			for (auto n : edges[current]) {
				if (!visited[n]) {
					que.push(n);
					visited[n] = true;
					ans[n] *= temp;
				}
			}
		}
		temp = ans[b] / tempB;
		que.push(b);
		while (!que.empty()) {
			int current = que.front();
			que.pop();
			for (auto n : edges[current]) {
				if (!visited[n]) {
					que.push(n);
					visited[n] = true;
					ans[n] *= temp;
				}
			}
		}
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
}
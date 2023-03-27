//BOJ 14622 소수 게임
#include <iostream>
#include <unordered_set>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int a, b;
	long long int score1 = 0, score2 = 0;
	unordered_set<int> primeSet;
	priority_queue<int> pq1;
	priority_queue<int> pq2;

	bool isPrime[5000001] = { false };
	isPrime[0] = isPrime[1] = true;
	for (int i = 2; i <= sqrt(5000000); i++) {
		if (!isPrime[i]) {
			for (int j = i + i; j <= 5000000; j += i) {
				isPrime[j] = true;
			}
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (!isPrime[a] && primeSet.find(a) == primeSet.end()) {
			pq1.push(a);
			primeSet.insert(a);
		}
		else {
			if (isPrime[a]) {
				if (pq2.size() < 3) {
					score2 += 1000;
				}
				else {
					int temp[2];
					temp[0] = pq2.top();
					pq2.pop();
					temp[1] = pq2.top();
					pq2.pop();
					score2 += pq2.top();
					pq2.push(temp[1]);
					pq2.push(temp[0]);
				}
			}
			else {
				score1 -= 1000;
			}
		}

		cin >> b;
		if (!isPrime[b] && primeSet.find(b) == primeSet.end()) {
			pq2.push(b);
			primeSet.insert(b);
		}
		else {
			if (isPrime[b]) {
				if (pq1.size() < 3) {
					score1 += 1000;
				}
				else {
					int temp[2];
					temp[0] = pq1.top();
					pq1.pop();
					temp[1] = pq1.top();
					pq1.pop();
					score1 += pq1.top();
					pq1.push(temp[1]);
					pq1.push(temp[0]);
				}
			}
			else {
				score2 -= 1000;
			}
		}
	}
	if (score1 > score2) {
		cout << "소수의 신 갓대웅";
	}
	else if (score1 < score2) {
		cout << "소수 마스터 갓규성";
	}
	else {
		cout << "우열을 가릴 수 없음";
	}
}
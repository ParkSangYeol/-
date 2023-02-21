#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#define MAX_NUM 1000000
#define MAX_INDEX (MAX_NUM/32 + 1) * 11
using namespace std;

int visited[MAX_INDEX];
struct number {
	int num, k;
};

bool checkVisited(int num, int k) {
	int index = ((k - 1) * MAX_NUM) + num;
	int i = index % 32;
	index = index / 32;
	if (visited[index] & (1 << i)) {
		return false;
	} 
	else {
		visited[index] |= (1 << i);
		return true;
	}
}

int main() {
	int N, K, M = 0, ans = -1;
	queue<number> q;

	cin >> N >> K;
	q.push({ N, 0 });
	while (N) {
		N /= 10;
		M++;
	}
	while (!q.empty()) {
		number current = q.front();
		q.pop();

		if (current.k == K) {
			ans = max(ans, current.num);
			continue;
		}
		vector<int> numOfDigits(M + 1);
		int tempNum = current.num;
		for (int i = 1; i <= M; i++) {
			numOfDigits[i] = tempNum % 10;
			tempNum /= 10;
		}
		for (int i = 1; i <= M - 1; i++) {
			for (int j = i + 1; j <= M; j++) {
				if (numOfDigits[i] == 0 && j == M) {
					continue;
				}
				int num = current.num - numOfDigits[i] * pow(10,i-1) -numOfDigits[j] * pow(10,j-1);
				num += numOfDigits[i] * pow(10, j - 1) + numOfDigits[j] * pow(10, i - 1);
				if (checkVisited(num, current.k + 1)) {
					q.push({ num,current.k + 1 });
				}
			}
		}
	}
	cout << ans;
}
//BOJ 11657 타임머신
#include <iostream>
#include <vector>
#define INF 9876543210123
using namespace std;

struct edge {
	long long int start, end, cost;
};

int main() {
	int N, M, A, B, C;
	bool negativeCycle = false;
	vector<edge> edgeVec;
	cin >> N >> M;
	vector<long long int> leastCostVec(N + 1, INF);
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		edgeVec.push_back({ A,B,C });
	}
	leastCostVec[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (edge& e : edgeVec) {
			if (leastCostVec[e.start] != INF) {
				leastCostVec[e.end] = min(leastCostVec[e.end], leastCostVec[e.start] + e.cost);
			}
		}
	}
	for (edge& e : edgeVec) {
		if (leastCostVec[e.start] != INF && leastCostVec[e.end] > leastCostVec[e.start] + e.cost) {
			negativeCycle = true;
			break;
		}
	}

	if (negativeCycle) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (leastCostVec[i] == INF)
				cout << -1 << '\n';
			else
				cout << leastCostVec[i] << '\n';
		}
	}
}
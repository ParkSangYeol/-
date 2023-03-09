//BOJ 3108 ·Î°í
#include <iostream>
#include <vector>
using namespace std;
int parent[1000] = { -1 };

int findParent(int n) {
	if (n == -1) return -1;
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = findParent(parent[n]);
}

void unionParent(int a, int b) {
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}

int main() {
	int N, ans = 0;
	int x1, x2, y1, y2;
	vector<vector<int>> parentMap(1001, vector<int>(1001, -1)); // x, y
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 500;
		x2 += 500;
		y1 += 500;
		y2 += 500;

		parent[i] = i;
		if (x1 > x2) {
			swap(x1, x2);
		}
		if (y1 > y2) {
			swap(y1, y2);
		}

		for (int j = x1; j <= x2; j++) {
			if (parentMap[j][y1] == -1) {
				parentMap[j][y1] = i;
			}
			else {
				if (parentMap[j][y1] != i && findParent(parentMap[j][y1]) != findParent(i)) {
					unionParent(findParent(parentMap[j][y1]), findParent(i));
				}
			}
			if (parentMap[j][y2] == -1) {
				parentMap[j][y2] = i;
			}
			else {
				if (parentMap[j][y2] != i && findParent(parentMap[j][y2]) != findParent(i)) {
					unionParent(findParent(parentMap[j][y2]), findParent(i));
				}
			}
		}

		for (int j = y1; j <= y2; j++) {
			if (parentMap[x1][j] == -1) {
				parentMap[x1][j] = i;
			}
			else {
				if (parentMap[x1][j] != i && findParent(parentMap[x1][j]) != findParent(i)) {
					unionParent(findParent(parentMap[x1][j]), findParent(i));
				}
			}
			if (parentMap[x2][j] == -1) {
				parentMap[x2][j] = i;
			}
			else {
				if (parentMap[x2][j] != i && findParent(parentMap[x2][j]) != findParent(i)) {
					unionParent(findParent(parentMap[x2][j]), findParent(i));
				}
			}
		}
	}
	if (parentMap[500][500] != -1) {
		parent[findParent(parentMap[500][500])] = -1;
	}

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (parentMap[i][j] != -1) {
				if (findParent(parentMap[i][j]) != -1) {
					parent[findParent(parentMap[i][j])] = -1;
					ans++;
				}
			}
		}
	}

	cout << ans;
}
//BOJ 2142 Á¤µ·µÈ ¹è¿­
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	while (T--) {
		bool isPossible = true;
		cin >> N >> M;
		vector<vector<int>> vec(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> vec[i][j];
				if (i != 0 && j != 0) {
					if (vec[i][j] + vec[i-1][j-1] > vec[i-1][j] + vec[i][j-1])
						isPossible = false;
				}
			}
		}
		if (isPossible) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}
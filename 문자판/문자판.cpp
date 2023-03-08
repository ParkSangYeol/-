//BOJ 2186 ¹®ÀÚÆÇ
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Point {
	int x, y, index;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K, ans = 0;
	int dX[4] = { 0, 1, 0, -1 };
	int dY[4] = { -1, 0, 1, 0 };
	char map[100][100];
	int dpMap[100][100][80] = { 0 };
	string str;
	queue<Point> q;

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> str;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == str[0]) {
				q.push({ j, i, 0 });
				dpMap[i][j][0] = 1;
			}
		}
	}
	while (!q.empty()) {
		Point current = q.front();
		q.pop();

		if (str.size() - 1 == current.index) {
			ans += dpMap[current.y][current.x][current.index];
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nX = current.x + dX[i];
				int nY = current.y + dY[i];
				for (int j = 0; j < K; j++) {
					if (nX >= 0 && nX < M && nY >= 0 && nY < N 
						&& map[nY][nX] == str[current.index + 1]) {
						if (dpMap[nY][nX][current.index + 1] == 0) {
							dpMap[nY][nX][current.index + 1] += dpMap[current.y][current.x][current.index];
							q.push({ nX,nY,current.index + 1 });
						}
						else {
							dpMap[nY][nX][current.index + 1] += dpMap[current.y][current.x][current.index];
						}
					}
					nX = nX + dX[i];
					nY = nY + dY[i];
				}
			}
		}
	}

	cout << ans;
}
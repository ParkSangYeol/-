//BOJ 2933 미네랄
#include <iostream>
#include <queue>
using namespace std;

struct point {
	int x, y;
};

int main() {
	int R, C, N;
	int dX[4] = { -1, 1, 0, 0 };
	int dY[4] = { 0, 0, 1, -1 };
	bool turnOfChang = true;
	char map[100][100];

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> N;
	while (N--) {
		int height, breakY, breakX;
		bool isBreak = false;
		cin >> height;
		if (turnOfChang) {
			for (int i = 0; i < C; i++) {
				if (map[R - height][i] == 'x') {
					breakX = i;
					breakY = R - height;
					map[R - height][i] = '.';
					isBreak = true;
					break;
				}
			}
		}
		else {
			for (int i = C - 1; i >= 0; i--) {
				if (map[R - height][i] == 'x') {
					breakX = i;
					breakY = R - height;
					map[R - height][i] = '.';
					isBreak = true;
					break;
				}
			}
		}

		if (isBreak) {
			bool isDirFall[4] = { true, true, true, true };
			vector<vector<point>> vec(4);
			int intVisitMap[100][100];

			for (int a = 0; a < R; a++) {
				for (int b = 0; b < C; b++) {
					intVisitMap[a][b] = -1;
				}
			}

			for (int i = 0; i < 4; i++) {
				int nX = breakX + dX[i];
				int nY = breakY + dY[i];

				if (nX >= 0 && nX < C && nY >= 0 && nY < R && map[nY][nX] == 'x') {
					queue<point> q;
					vec[i].push_back({ nX,nY });
					q.push({ nX,nY });
					while (!q.empty()) {
						point currentPoint = q.front();
						q.pop();

						for (int j = 0; j < 4; j++) {
							int nextX = currentPoint.x + dX[j];
							int nextY = currentPoint.y + dY[j];
							if (nextX >= 0 && nextX < C && nextY >= 0 && nextY < R && map[nextY][nextX] == 'x') {
								if (intVisitMap[nextY][nextX] != -1 && intVisitMap[nextY][nextX] != i) {
									isDirFall[i] = false;
								}
								if (intVisitMap[nextY][nextX] == -1) {
									intVisitMap[nextY][nextX] = i;
									if (nextY == R - 1) {
										isDirFall[i] = false;
									}
									vec[i].push_back({ nextX,nextY });
									q.push({ nextX, nextY });
								}
							}
						}
					}
				}
				else {
					isDirFall[i] = false;
				}
			}
			for (int i = 0; i < 4; i++) {
				if (isDirFall[i]) {
					int fallCount = R;
					bool visitMap[100][100] = { 0 };

					for (point p : vec[i]) {
						visitMap[p.y][p.x] = true;
					}

					for (point p : vec[i]) {
						int x = p.x;
						int y = p.y;
						int tempFallCount = 0;
						while ((y + 1 != R && map[y + 1][x] != 'x' )|| visitMap[y + 1][x]) {
							tempFallCount++;
							y++;
						}
						fallCount = min(fallCount, tempFallCount);
					}

					for (point p : vec[i]) {
						map[p.y][p.x] = '.';
					}

					for (point p : vec[i]) {
						map[p.y + fallCount][p.x] = 'x';
					}
				}
			}
		}
		turnOfChang = !turnOfChang;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}
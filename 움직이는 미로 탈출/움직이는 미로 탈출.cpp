//BOJ 16954 움직이는 미로 탈출
#include <iostream>
#include <queue>
using namespace std;

struct point {
	int x, y, time;
};
int main() {
	char map[8][8];
	bool visited[8][8][8] = { false };
	bool isMoveable = false;
	int dX[9] = { 0,0,1,1,1,0,-1,-1,-1 };
	int dY[9] = { 0, -1,-1,0,1,1,1,0,-1 };
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = getchar();
		}
		getchar();
	}

	queue<point> q;
	q.push({ 0,7,0 });
	while (!q.empty()) {
		point current = q.front();
		q.pop();

		for (int i = 0; i < 9; i++) {
			int nX = current.x + dX[i];
			int nY = current.y + dY[i];
			if (nX >= 0 && nX < 8 && nY >= 0 && nY < 8 && !visited[nY][nX][current.time + 1]) {
				if ( nY - current.time < 0 || (map[nY - current.time][nX] != '#' && map[nY - current.time - 1][nX] != '#')) {
					if (current.time + 1 == 8 ||(nX == 7 && nY == 0)) {
						isMoveable = true;
						break;
					}
					visited[nY][nX][current.time + 1] = true;
					q.push({ nX,nY, current.time + 1 });
				}
			}
		}
	}
	
	if (isMoveable) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}
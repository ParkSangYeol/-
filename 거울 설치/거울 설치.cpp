// BOj 2151 거울 설치
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct point {
	int x, y, dir, cost;
};

struct compare {
	bool operator()(point& a, point& b) {
		return a.cost > b.cost;
	}
};

int main() {
	int N;
	int dX[4] = { 0,1,0,-1 };
	int dY[4] = { -1,0,1,0 };
	point door;
	char house[50][50];
	int dist[50][50][4];
	priority_queue<point, vector<point>, compare> pq;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
			dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = dist[i][j][3] = 987654321;
			if (house[i][j] == '#') {
				door.x = j;
				door.y = i;
			}
		}
	}

	dist[door.y][door.x][0] = dist[door.y][door.x][1] = dist[door.y][door.x][2] = dist[door.y][door.x][3] = 0;
	for (int i = 0; i < 4; i++) {
		int nX = door.x + dX[i];
		int nY = door.y + dY[i];
		if (nX >= 0 && nX < N && nY >= 0 && nY < N && house[nY][nX] != '*') {
			pq.push({ nX,nY,i,0 });
			dist[nY][nX][i%2] = 0;
		}
	}

	while (!pq.empty()) {
		point current = pq.top();
		pq.pop();
		if (house[current.y][current.x] == '#' && (current.x != door.x || current.y != door.y)) {
			cout << current.cost;
			break;
		}
		if (house[current.y][current.x] == '!') {
			for (int i = 0; i < 4; i++) {
				if ((current.dir + 2) % 4 == i)
					continue;
				int nX = current.x + dX[i];
				int nY = current.y + dY[i];
				if (nX >= 0 && nX < N && nY >= 0 && nY < N && house[nY][nX] != '*') {
					if (current.dir % 2 == i % 2) {
						if (dist[nY][nX][i] > current.cost) {
							dist[nY][nX][i] = current.cost;
							pq.push({ nX, nY, i, current.cost });
						}
					}
					else {
						if (dist[nY][nX][i] > current.cost + 1) {
							dist[nY][nX][i] = current.cost + 1;
							pq.push({ nX, nY, i, current.cost + 1});
						}
					}
				}
			}
		}
		else {
			int nX = current.x + dX[current.dir];
			int nY = current.y + dY[current.dir];
			if (nX >= 0 && nX < N && nY >= 0 && nY < N && house[nY][nX] != '*') {
				if (dist[nY][nX][current.dir] > current.cost) {
					dist[nY][nX][current.dir] = current.cost;
					pq.push({ nX, nY, current.dir, current.cost });
				}
			}
		}
	}
}
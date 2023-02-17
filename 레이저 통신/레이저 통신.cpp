//BOJ 6087 레이저 통신
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int x, y, cost, dir;
};

struct compare {
	bool operator()(point& a, point& b) {
		return a.cost > b.cost;
	}
};

int main() {
	int W, H;
	char map[100][100];
	int leastCost[100][100][4];
	int dX[4] = { 0,1,0,-1 };
	int dY[4] = { -1,0,1,0 };
	priority_queue<point, vector<point>, compare> pq;
	point C;

	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			for (int k = 0; k < 4; k++) 
				leastCost[i][j][k] = 987654321;
			if (map[i][j] == 'C') {
				C.x = j;
				C.y = i;
			}
		}
	}

	C.cost = 0;
	C.dir = -1;
	pq.push(C);
	while (!pq.empty()) {
		point current = pq.top();
		pq.pop();
		if (map[current.y][current.x] == 'C' && (current.x != C.x || current.y != C.y)) {
			cout << current.cost;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nX = current.x + dX[i];
			int nY = current.y + dY[i];
			if (nX < 0 || nX >= W || nY < 0 || nY >= H) {
				continue;
			}
			else if (map[nY][nX] == '*') {
				continue;
			}

			if (current.dir == -1) {
				leastCost[nY][nX][i] = 0;
				pq.push({ nX,nY,0,i });
			}
			else if (current.dir == i) {
				if (leastCost[nY][nX][i] > current.cost) {
					leastCost[nY][nX][i] = current.cost;
					pq.push({ nX,nY,current.cost,i });
				}
			}
			else if ((current.dir + 2) % 4 == i) {
				continue;
			}
			else {
				if (leastCost[nY][nX][i] > current.cost + 1) {
					leastCost[nY][nX][i] = current.cost + 1;
					pq.push({ nX,nY,current.cost + 1,i });
				}
			}
		}
	}

}
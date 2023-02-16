//BOJ 9376 Å»¿Á
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int T, h, w;
int dX[4] = { 0,1,0,-1 };
int dY[4] = { -1,0,1,0 };

struct point {
	int x = -1, y = -1, cost;
};

struct compare {
	bool operator()(point& a, point& b) {
		return a.cost > b.cost;
	}
};

void dijkstra(point startPoint, vector<vector<char>>& map, vector<vector<int>>& dijkstraMap) {
	vector<vector<bool>> visitedMap(h + 2, vector<bool>(w + 2, false));
	priority_queue<point, vector<point>, compare> pq;
	pq.push(startPoint);
	dijkstraMap[startPoint.y][startPoint.x] = 0;
	visitedMap[startPoint.y][startPoint.x] = true;

	while (!pq.empty()) {
		point current = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nX = current.x + dX[i];
			int nY = current.y + dY[i];
			if (nX >= 0 && nX < w + 2 && nY >= 0 && nY < h + 2 && !visitedMap[nY][nX] && map[nY][nX] != '*') {
				if (map[nY][nX] == '#') {
					if (dijkstraMap[nY][nX] > current.cost + 1) {
						dijkstraMap[nY][nX] = current.cost + 1;
						pq.push({ nX,nY, current.cost + 1 });
						visitedMap[nY][nX] = true;
					}
				}
				else {
					if (dijkstraMap[nY][nX] > current.cost) {
						dijkstraMap[nY][nX] = current.cost;
						pq.push({ nX,nY, current.cost});
						visitedMap[nY][nX] = true;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> h >> w;
		vector<vector<char>> map(h + 2, vector<char>(w + 2, '.'));
		point prisonerA, prisonerB;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					if (prisonerA.x == -1) {
						prisonerA = { j,i,0 };
					}
					else {
						prisonerB = { j,i,0 };
					}
				}
			}
		}

		vector<vector<int>> dijkstraA(h + 2, vector<int>(w + 2, 9876543));
		vector<vector<int>> dijkstraB(h + 2, vector<int>(w + 2, 9876543));
		vector<vector<int>> dijkstraC(h + 2, vector<int>(w + 2, 9876543));

		dijkstra(prisonerA, map, dijkstraA);
		dijkstra(prisonerB, map, dijkstraB);
		dijkstra({ 0,0 }, map, dijkstraC);

		int ans = 9876543;
		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (map[i][j] == '#')
					ans = min(ans, dijkstraA[i][j] + dijkstraB[i][j] + dijkstraC[i][j] - 2);
				else
					ans = min(ans, dijkstraA[i][j] + dijkstraB[i][j] + dijkstraC[i][j]);
			}
		}
		cout << ans << '\n';
	}
}
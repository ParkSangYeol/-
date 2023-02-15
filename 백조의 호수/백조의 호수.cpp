//BOJ 3197 백조의 호수
#include <iostream>
#include <queue>
using namespace std;

struct point {
	int x, y;
};

int R, C;
point swan;
char map[1500][1500];
bool swanVisitedMap[1500][1500] = { false };
int dX[4] = { 0,1,0,-1 };
int dY[4] = { -1,0,1,0 };

bool processTurn(queue<point>& queueToProcess, queue<point>& queueToStore,
	queue<point>& swanQueueToProcess, queue<point>& swanQueueToStore);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	bool turn = false, isFindAns = false;
	queue<point> q1, q2, swanQueue1, swanQueue2;

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] != 'X') {
				q1.push({ j,i });
				if (map[i][j] == 'L' && swanQueue1.empty()) {
					swan = { j, i };
					swanQueue1.push({ j,i });
					swanVisitedMap[i][j] = true;
				}
			}
		}
	}

	while (true) {
		if (turn) {
			isFindAns = processTurn(q2, q1, swanQueue2, swanQueue1);
		}
		else {
			isFindAns = processTurn(q1, q2, swanQueue1, swanQueue2);
		}
		
		if (isFindAns)
			break;
		turn = !turn;
		ans++;
	}

	cout << ans;
}

bool processTurn(queue<point>& queueToProcess, queue<point>& queueToStore, 
	queue<point>& swanQueueToProcess, queue<point>& swanQueueToStore) {
	while (!swanQueueToProcess.empty()) {
		point current = swanQueueToProcess.front();
		swanQueueToProcess.pop();

		if (map[current.y][current.x] == 'L' && (current.x != swan.x || current.y != swan.y))
			return true;

		for (int i = 0; i < 4; i++) {
			int nX = current.x + dX[i];
			int nY = current.y + dY[i];
			if (nX >= 0 && nX < C && nY >= 0 && nY < R && !swanVisitedMap[nY][nX]) {
				if (map[nY][nX] == 'X') {
					swanQueueToStore.push({ nX, nY });
					swanVisitedMap[nY][nX] = true;
				}
				else {
					swanQueueToProcess.push({ nX, nY });
					swanVisitedMap[nY][nX] = true;
				}
			}
		}
	}
	while (!queueToProcess.empty()) {
		point current = queueToProcess.front();
		queueToProcess.pop();

		for (int i = 0; i < 4; i++) {
			int nX = current.x + dX[i];
			int nY = current.y + dY[i];
			if (nX >= 0 && nX < C && nY >= 0 && nY < R && map[nY][nX] == 'X') {
				queueToStore.push({ nX, nY });
				map[nY][nX] = '.';
			}
		}
	}

	return false;
}
// BOJ 2931 °¡½º°ü
#include <iostream>
using namespace std;

struct point {
	int x, y;
};

int main() {
	int R, C;
	char map[25][25];
	int dX[4] = { 0, 1, 0, -1 };
	int dY[4] = { -1,0,1,0 };
	point current;
	int dir;

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') {
				current.y = i;
				current.x = j;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		int nX = current.x + dX[i];
		int nY = current.y + dY[i];
		if (nX >= 0 && nX < C && nY >= 0 && nY < R && map[nY][nX] != '.' && map[nY][nX] != 'Z') {
			current.x = nX;
			current.y = nY;
			dir = i;
			break;
		}
	}

	while (true) {
		if (map[current.y][current.x] == '.') {
			int connect = 0;
			int connectDir;

			int nX = current.x + dX[0];
			int nY = current.y + dY[0];
			if (nX >= 0 && nX < C && nY >= 0 && nY < R && map[nY][nX] != '.' && map[nY][nX] != 'Z' && map[nY][nX] != 'M' && dir != 2) {
				if (map[nY][nX] != '-' && map[nY][nX] != '2' && map[nY][nX] != '3') {
					connect++;
					connectDir = 0;
				}
			}
			nX = current.x + dX[1];
			nY = current.y + dY[1];
			if (nX >= 0 && nX < C && nY >= 0 && nY < R && map[nY][nX] != '.' && map[nY][nX] != 'Z' && map[nY][nX] != 'M' && dir != 3) {
				if (map[nY][nX] != '|' && map[nY][nX] != '1' && map[nY][nX] != '2') {
					connect++;
					connectDir = 1;
				}
			}
			nX = current.x + dX[2];
			nY = current.y + dY[2];
			if (nX >= 0 && nX < C && nY >= 0 && nY < R && map[nY][nX] != '.' && map[nY][nX] != 'Z' && map[nY][nX] != 'M' && dir != 0) {
				if (map[nY][nX] != '-' && map[nY][nX] != '1' && map[nY][nX] != '4') {
					connect++;
					connectDir = 2;
				}
			}
			nX = current.x + dX[3];
			nY = current.y + dY[3];
			if (nX >= 0 && nX < C && nY >= 0 && nY < R && map[nY][nX] != '.' && map[nY][nX] != 'Z' && map[nY][nX] != 'M' && dir != 1) {
				if (map[nY][nX] != '|' && map[nY][nX] != '3' && map[nY][nX] != '4') {
					connect++;
					connectDir = 3;
				}
			}
			if (connect == 1) {
				if ((dir == 0 || dir == 2) && (connectDir == 0 || connectDir == 2)) {
					cout << current.y + 1 << ' ' << current.x + 1 << ' ' << '|';
				}
				else if ((dir == 1 || dir == 3) && (connectDir == 1 || connectDir == 3)) {
					cout << current.y + 1 << ' ' << current.x + 1 << ' ' << '-';

				}
				else if ((dir == 0 && connectDir == 1) || (dir == 3 && connectDir == 2)) {
					cout << current.y + 1 << ' ' << current.x + 1 << ' ' << '1';
				}
				else if ((dir == 2 && connectDir == 1) || (dir == 3 && connectDir == 0)) {
					cout << current.y + 1 << ' ' << current.x + 1 << ' ' << '2';
				}
				else if ((dir == 2 && connectDir == 3) || (dir == 1 && connectDir == 0)) {
					cout << current.y + 1 << ' ' << current.x + 1 << ' ' << '3';
				}
				else if ((dir == 0 && connectDir == 3) || (dir == 1 && connectDir == 2)) {
					cout << current.y + 1 << ' ' << current.x + 1 << ' ' << '4';
				}
			}
			else {
				cout << current.y + 1 << ' ' << current.x + 1 << ' ' << '+';
			}
			break;
		}
		switch (map[current.y][current.x])
		{
			case '1':
				if (dir == 3)
					dir = 2;
				else
					dir = 1;
				break;
			case '2':
				if (dir == 2)
					dir = 1;
				else
					dir = 0;
				break;
			case '3':
				if (dir == 2)
					dir = 3;
				else
					dir = 0;
				break;
			case '4':
				if (dir == 0)
					dir = 3;
				else
					dir = 2;
				break;
			default:
				break;
		}
		current.x = current.x + dX[dir];
		current.y = current.y + dY[dir];
	}
}
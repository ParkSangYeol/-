// BOJ 1891 »çºÐ¸é
#include <iostream>
using namespace std;

int main() {
	int d;
	int num[50];
	bool isBroke = false;
	long long int x, y;

	cin >> d;
	getchar();
	for (int i = d-1; i >= 0; i--) {
		char temp = getchar();
		num[i] = temp - '0';
	}

	cin >> x >> y;
	int index = 0;
	if (x > 0) {
		while (x) {
			if (x & 1) {
				int temp = index;
				while (num[temp] == 1 || num[temp] == 4) {
					if (num[temp] == 1)
						num[temp] = 2;
					else
						num[temp] = 3;
					temp++;
					if (temp >= d) {
						isBroke = true;
						break;
					}
				}
				if (temp >= d) {
					isBroke = true;
					break;
				}
				if (num[temp] == 2)
					num[temp] = 1;
				else
					num[temp] = 4;
			}
			x >>= 1;
			index++;
		}
	}
	else {
		while (-x) {
			if (x % 2) {
				int temp = index;
				while (num[temp] == 2 || num[temp] == 3) {
					if (num[temp] == 2)
						num[temp] = 1;
					else
						num[temp] = 4;
					temp++;
					if (temp >= d) {
						isBroke = true;
						break;
					}
				}
				if (temp >= d) {
					isBroke = true;
					break;
				}
				if (num[temp] == 1)
					num[temp] = 2;
				else
					num[temp] = 3;
			}
			x /= 2;
			index++;
		}
	}

	index = 0;
	if (!isBroke && y > 0) {
		while (y) {
			if (y & 1) {
				int temp = index;
				while (num[temp] == 2 || num[temp] == 1) {
					if (num[temp] == 2)
						num[temp] = 3;
					else
						num[temp] = 4;
					temp++;
					if (temp >= d) {
						isBroke = true;
						break;
					}
				}
				if (temp >= d) {
					isBroke = true;
					break;
				}
				if (num[temp] == 3)
					num[temp] = 2;
				else
					num[temp] = 1;
			}
			y >>= 1;
			index++;
		}
	}
	else {
		while (-y) {
			if (y % 2) {
				int temp = index;
				while (num[temp] == 3 || num[temp] == 4) {
					if (num[temp] == 3)
						num[temp] = 2;
					else
						num[temp] = 1;
					temp++;
					if (temp >= d) {
						isBroke = true;
						break;
					}
				}
				if (temp >= d) {
					isBroke = true;
					break;
				}
				if (num[temp] == 2)
					num[temp] = 3;
				else
					num[temp] = 4;
			}
			y /= 2;
			index++;
		}
	}

	if (isBroke) {
		cout << -1;
	}
	else {
		for (int i = d - 1; i >= 0; i--) {
			cout << num[i];
		}
	}
}
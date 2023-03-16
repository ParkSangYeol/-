//BOJ 1338 알 수 없는 번호
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long int start, end;
	long long int x, y, count = 0, ans;
	cin >> start >> end;
	if (start > end) {
		swap(start, end);
	}
	cin >> x >> y;

	if (x == 0 || y >= abs(x) || y < 0) {
		count = -1;
	}
	else {
		long long int temp = start / x;
		if (x > 0) {
			temp = x * (temp - 1);
			while (temp + y <= end) {
				if (temp + y >= start) {
					count++;
					ans = temp + y;
				}
				if (count > 1) {
					break;
				}
				temp += x;
			}
		}
		else {
			temp = x * (temp + 1);
			while (temp + y <= end) {
				if (temp + y >= start) {
					count++;
					ans = temp + y;
				}
				if (count > 1) {
					break;
				}
				temp -= x;
			}
		}
	}
	if (count == 1) {
		cout << ans;
	}
	else {
		cout << "Unknwon Number";
	}
}
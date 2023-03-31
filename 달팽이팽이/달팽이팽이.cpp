//BOJ ´ÞÆØÀÌ ÆØÀÌ
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int R, x = 1;
	cin >> R;
	while (x * x < 2 * R - 1)
		x++;
	cout << x - 1 << ' ' << R - 1;
}
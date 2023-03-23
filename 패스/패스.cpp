//BOJ 25559 ÆÐ½º
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 1)
		cout << 1;
	else if (N & 1)
		cout << -1;
	else 
		for (int front = 1, back = N; front <= N; front += 2, back -=2)
			cout << back << ' ' << front << ' ';
}
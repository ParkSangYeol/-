//BOJ 24229 모두싸인 출근길
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Board {
	int L, R;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int L, R;
	int ans = 0, jumpCount = 0;
	vector<Board> vec;

	cin >> N;
	while (N--) {
		cin >> L >> R;
		vec.push_back({ L, R });
	}
	sort(vec.begin(), vec.end(), [](Board& a, Board& b) -> bool {
		return a.L < b.L;
	});

	for (auto& board : vec) {
		if (ans >= board.L) {
			if (ans < board.R) {
				jumpCount += board.R - ans;
				ans = board.R;
			}
		}
		else if (ans + jumpCount >= board.L){
			jumpCount = max(jumpCount - (board.R - ans), board.R - board.L);
			ans = board.R;
		}
		else {
			break;
		}
	}
	cout << ans;
}
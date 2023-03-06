//BOJ 24230 트리 색칠하기
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int nodeNum, color;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C, a, b;
	int ans = 0;
	cin >> N;

	vector<int> colorVec(N + 1);
	vector<int> visitVec(N + 1);
	vector<vector<int>> edgeVec(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> colorVec[i];
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		edgeVec[a].push_back(b);
		edgeVec[b].push_back(a);
	}

	stack<Node> st;
	st.push({ 1,0 });
	visitVec[1] = true;

	while (!st.empty()) {
		Node current = st.top();
		st.pop();

		if (colorVec[current.nodeNum] != current.color) {
			current.color = colorVec[current.nodeNum];
			ans++;
		}
		for (auto& node : edgeVec[current.nodeNum]) {
			if (!visitVec[node]) {
				visitVec[node] = true;
				st.push({ node,current.color });
			}
		}
	}

	cout << ans;
}
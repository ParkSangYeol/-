//BOJ 26146 즉흥 여행 (Easy)
// 타잔 알고리즘을 이용한 풀이
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int sccCount = 0, label = 0;
vector<vector<int>> edgeVec;
vector<int> sccVec, parentVec, labelVec;
stack<int> st;

int makeScc(int currentNode);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int v, w;
	cin >> N >> M;

	edgeVec = vector<vector<int>>(N + 1);
	sccVec = vector<int>(N + 1, -1);
	labelVec = vector<int>(N + 1, -1);
	parentVec = vector<int>(N + 1, -1);

	for (int i = 0; i < M; i++) {
		cin >> v >> w;
		edgeVec[v].push_back(w);
	}
	for (int i = 1; i <= N; i++) {
		if (parentVec[i] == -1)
			makeScc(i);
	}
	if (sccCount == 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

int makeScc(int currentNode) {
	parentVec[currentNode] = labelVec[currentNode] =  label++;
	st.push(currentNode);

	for (auto i : edgeVec[currentNode]) {
		if (parentVec[i] == -1) {
			parentVec[currentNode] = min(parentVec[currentNode], makeScc(i));
		}
		else if (sccVec[i] == -1) {
			parentVec[currentNode] = min(parentVec[currentNode], parentVec[i]);
		}
	}

	if (parentVec[currentNode] == labelVec[currentNode]) {
		while (st.top() != currentNode) {
			sccVec[st.top()] = sccCount;
			st.pop();
		}
		st.pop();
		sccVec[currentNode] = sccCount++;
	}

	return parentVec[currentNode];
}
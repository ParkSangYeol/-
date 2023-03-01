//BOJ 26146 즉흥 여행 (Easy)
// 코사라주 알고리즘을 이용한 풀이
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void makeNumVec(vector<int>& numVec, vector<vector<int>>& edgeVec, int current, vector<bool>& visitTable);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int v, w;
	bool isTrue = false;
	cin >> N >> M;
	vector<vector<int>> normalEdge(N + 1);
	vector<vector<int>> flipEdge(N + 1);
	vector<bool> visitTable(N + 1, false);
	vector<int> numVec;

	for (int i = 0; i < M; i++) {
		cin >> v >> w;
		normalEdge[v].push_back(w);
		flipEdge[w].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		if (!visitTable[i]) {
			visitTable[i] = true;
			makeNumVec(numVec, normalEdge, i, visitTable);
		}
	}
	
	visitTable = vector<bool>(N + 1, false);
	for (auto i = numVec.rbegin(); i != numVec.rend(); i++) {
		if (!visitTable[(*i)]) {
			if (isTrue) {
				isTrue = false;
				break;
			}
			stack<int> st;
			isTrue = true;
			st.push((*i));
			visitTable[*i] = true;
			while (!st.empty()) {
				int current = st.top();
				st.pop();
				for (auto j : flipEdge[current]) {
					if (!visitTable[j]) {
						visitTable[j] = true;
						st.push(j);
					}
				}
			}
		}
	}

	if (isTrue) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

void makeNumVec(vector<int>& numVec, vector<vector<int>>& edgeVec, int current, vector<bool>& visitTable) {
	for (auto i : edgeVec[current]) {
		if (!visitTable[i]) {
			visitTable[i] = true;
			makeNumVec(numVec, edgeVec, i, visitTable);
		}
	}
	numVec.push_back(current);
}
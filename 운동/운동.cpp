// BOJ 1956 ¿îµ¿
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E, ans = INF;
	int a, b, c;
	
	cin >> V >> E;
	vector<vector<int>> adjTable(V + 1, vector<int>(V + 1, INF));
	
	while (E--) {
		cin >> a >> b >> c;
		adjTable[a][b] = c;
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				adjTable[j][k] = min(adjTable[j][k], adjTable[j][i] + adjTable[i][k]);
			}
		}
	}

	for (int i = 1; i < V; i++) {
		for (int j = i + 1; j <= V; j++) {
			ans = min(ans, adjTable[i][j] + adjTable[j][i]);
		}
	}
	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}
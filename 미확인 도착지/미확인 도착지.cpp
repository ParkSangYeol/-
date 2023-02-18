//BOJ 9370 미확인 도착지
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct edge {
	int node, cost;
};

struct compare {
	bool operator()(edge& a, edge& b) {
		return a.cost > b.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, m, t, s, g, h, a, b, d;
		cin >> n >> m >> t >> s >> g >> h;
		priority_queue<edge, vector<edge>, compare> pq;
		vector<vector<edge>> edgeVec(n + 1);
		vector<int> dist(n + 1, INF);
		vector<int> distG(n + 1, INF);
		vector<int> distH(n + 1, INF);
		vector<int> possibleDest;
		vector<bool> visited(n + 1, false);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			edgeVec[a].push_back({ b,d});
			edgeVec[b].push_back({ a,d});
		}
		for (int i = 0; i < t; i++) {
			int temp;
			cin >> temp;
			possibleDest.push_back(temp);
		}
		sort(possibleDest.begin(), possibleDest.end());
		pq.push({ s,0});
		dist[s] = 0;
		while(!pq.empty()) {
			edge current = pq.top();
			pq.pop();
			if (dist[current.node] < current.cost)
				continue;
			visited[current.node] = true;
			for (edge& e : edgeVec[current.node]) {
				if (!visited[e.node] && dist[e.node] > current.cost + e.cost) {
					dist[e.node] = current.cost + e.cost;
					pq.push({ e.node,current.cost + e.cost});
				}
			}
		}
		pq.push({ g,0 });
		distG[g] = 0;
		visited = vector<bool>(n + 1, false);
		while (!pq.empty()) {
			edge current = pq.top();
			pq.pop();
			if (distG[current.node] < current.cost)
				continue;
			visited[current.node] = true;
			for (edge& e : edgeVec[current.node]) {
				if (!visited[e.node] && distG[e.node] > current.cost + e.cost) {
					distG[e.node] = current.cost + e.cost;
					pq.push({ e.node,current.cost + e.cost });
				}
			}
		}
		pq.push({ h,0 });
		distH[h] = 0;
		visited = vector<bool>(n + 1, false);
		while (!pq.empty()) {
			edge current = pq.top();
			pq.pop();
			if (distH[current.node] < current.cost)
				continue;
			visited[current.node] = true;
			for (edge& e : edgeVec[current.node]) {
				if (!visited[e.node] && distH[e.node] > current.cost + e.cost) {
					distH[e.node] = current.cost + e.cost;
					pq.push({ e.node,current.cost + e.cost });
				}
			}
		}
		for (int& i : possibleDest) {
			if (dist[i] == dist[g] + distG[h] + distH[i] || dist[i] == dist[h] + distH[g] + distG[i]) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}
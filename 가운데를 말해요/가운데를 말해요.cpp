//BOJ 1655 가운데를 말해요
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, temp;
	priority_queue<int, vector<int>, greater<>> minHeap;
	priority_queue<int> maxHeap;

	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (maxHeap.empty() || temp <= maxHeap.top()) {
			maxHeap.push(temp);
		}
		else {
			minHeap.push(temp);
		}
		if (maxHeap.size() == minHeap.size()
			|| maxHeap.size() == minHeap.size() + 1) {

		}
		else if (maxHeap.size() < minHeap.size()) {
			while (maxHeap.size() != minHeap.size()
				&& maxHeap.size() != minHeap.size() + 1) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
		}
		else {
			while (maxHeap.size() != minHeap.size()
				&& maxHeap.size() != minHeap.size() + 1) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
		}
		cout << maxHeap.top() << '\n';
	}
}
//BOJ 1275 Ä¿ÇÇ¼ó
#include <iostream>
#define MAX_LEN 100001
using namespace std;

long long int segTree[MAX_LEN * 4];
int arr[MAX_LEN];

long long int initTree(int start, int end, int node);
long long int getSum(int start, int end, int startRange, int endRange, int node);
void updateNode(int start, int end, int targetIndex, int node, long long int changeValue);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	long long int x, y, a, b;

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	initTree(1, N, 1);

	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		if (x > y)
			cout << getSum(1, N, y, x, 1) << '\n';
		else
			cout << getSum(1, N, x, y, 1) << '\n';
		long long int changeValue = b - arr[a];
		arr[a] = b;
		updateNode(1, N, a, 1, changeValue);
	}
}

long long int initTree(int start, int end, int node) {
	if (start == end) return segTree[node] = arr[start];
	int mid = (start + end) / 2;
	return segTree[node] = initTree(start, mid, node * 2) + initTree(mid + 1, end, node * 2 + 1);
}

long long int getSum(int start, int end, int startRange, int endRange, int node) {
	if (start > endRange || end < startRange)
		return 0;
	if (startRange <= start && endRange >= end)
		return segTree[node];
	int mid = (start + end) / 2;
	return getSum(start, mid, startRange, endRange, node * 2) + getSum(mid + 1, end, startRange, endRange, node * 2 + 1);
}
void updateNode(int start, int end, int targetIndex, int node, long long int changeValue) {
	if (targetIndex < start || targetIndex > end)
		return;
	segTree[node] += changeValue;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	updateNode(start, mid, targetIndex, node * 2, changeValue);
	updateNode(mid + 1, end, targetIndex, node * 2 + 1, changeValue);

}
//BOJ 12886 µ¹±×·ì
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct state {
	int A, B, C;
};

bool visited[1502][1502] = { 0 };
bool isVisited(int A, int B) {
	if (visited[A][B]) {
		return false;
	}
	visited[A][B] = true;
	return true;
}

int main() {
	int A, B, C;
	bool isAble = false;
	queue<state> q;
	cin >> A >> B >> C;

	vector<int> vec;
	vec.push_back(A);
	vec.push_back(B);
	vec.push_back(C);
	sort(vec.begin(), vec.end());
	isVisited(vec[0],vec[1]);
	q.push({ vec[0],vec[1],vec[2] });
	while (!q.empty()) {
		state current = q.front();
		q.pop();
		if (current.A == current.B && current.B == current.C) {
			isAble = true;
			break;
		}
		if (current.A < current.B) {
			vector<int> vec;
			vec.push_back(current.A * 2);
			vec.push_back(current.B - current.A);
			vec.push_back(current.C);
			sort(vec.begin(), vec.end());
			if (isVisited(vec[0], vec[1])) {
				q.push({ vec[0], vec[1], vec[2] });
			}
		}

		if (current.B < current.C) {
			vector<int> vec;
			vec.push_back(current.A);
			vec.push_back(current.B * 2);
			vec.push_back(current.C - current.B);
			sort(vec.begin(), vec.end());
			if (isVisited(vec[0], vec[1])) {
				q.push({ vec[0], vec[1], vec[2] });
			}
		}

		if (current.A < current.C) {
			vector<int> vec;
			vec.push_back(current.A * 2);
			vec.push_back(current.B);
			vec.push_back(current.C - current.A);
			sort(vec.begin(), vec.end());
			if (isVisited(vec[0], vec[1])) {
				q.push({ vec[0], vec[1], vec[2] });
			}
		}
	}

	if (isAble) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}
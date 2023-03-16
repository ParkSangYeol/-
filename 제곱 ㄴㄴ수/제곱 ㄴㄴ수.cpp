//BOJ 1016 Á¦°ö ¤¤¤¤¼ö
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	long long int minNum, maxNum;
	int ans;
	vector<bool> visited;
	vector<long long int> primeVec;

	cin >> minNum >> maxNum;
	ans = maxNum - minNum + 1;
	visited = vector<bool>((int)sqrt(maxNum) + 1, false);
	for (int i = 2; i < visited.size(); i++) {
		if (!visited[i]) {
			primeVec.push_back((long long int)i * i);
			for (int j = i; j < visited.size(); j+= i) {
				visited[j] = true;
			}
		}
	}

	auto iter = primeVec.begin();
	visited = vector<bool>(maxNum - minNum + 1, false);
	while (iter != primeVec.end() && (*iter) <= maxNum) {
		long long int temp = minNum;
		if (minNum % (*iter) != 0) {
			temp = minNum + (*iter) - minNum % (*iter);
		}
		while (temp <= maxNum) {
			if (!visited[temp - minNum]) {
				visited[temp - minNum] = true;
				ans--;
			}
			temp += (*iter);
		}
		iter++;
	}

	cout << ans;
}
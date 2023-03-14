//BOJ 9177 ´Ü¾î ¼¯±â
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> dp;
string str1, str2, targetStr;

int solve(int index1, int index2) {
	if (index1 == str1.size() && index2 == str2.size())
		return dp[index1][index2] = 1;
	if (dp[index1][index2] != -1) {
		return dp[index1][index2];
	}
	if (index1 < str1.size() && str1[index1] == targetStr[index1 + index2])
		dp[index1][index2] = max(dp[index1][index2], solve(index1 + 1, index2));
	if (index2 < str2.size() && str2[index2] == targetStr[index1 + index2])
		dp[index1][index2] = max(dp[index1][index2], solve(index1, index2 + 1));
	if (dp[index1][index2] == -1)
		dp[index1][index2] = 0;
	return dp[index1][index2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str1 >> str2 >> targetStr;
		dp = vector<vector<int>>(str1.size() + 1, vector<int>(str2.size() + 1, -1));
		solve(0, 0);
		if (dp[0][0] == 1) {
			cout << "Data set " << i << ": yes\n";
		}
		else {
			cout << "Data set " << i << ": no\n";
		}
	}
}
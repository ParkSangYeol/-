// BOJ 12916 K-Path
#include <iostream>
#include <vector>
#define DIV_NUM 1000000007
using namespace std;

vector<vector<long long int>> mat;

vector<vector<long long int>> squareMatrix(int N, int K) {
	if (K == 1) {
		return mat;
	}
	vector<vector<long long int>> tempMat1 = squareMatrix(N, K >> 1);
	vector<vector<long long int>> tempMat2 = vector<vector<long long int>>(N, vector<long long int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tempMat2[i][j] = 0;
			for (int k = 0; k < N; k++) {
				tempMat2[i][j] += tempMat1[i][k] * tempMat1[k][j] % DIV_NUM;
				tempMat2[i][j] %= DIV_NUM;
			}
		}
	}

	if (K & 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tempMat1[i][j] = 0;
				for (int k = 0; k < N; k++) {
					tempMat1[i][j] += tempMat2[i][k] * mat[k][j] % DIV_NUM;
					tempMat1[i][j] %= DIV_NUM;
				}
			}
		}
		return tempMat1;
	}
	else {
		return tempMat2;
	}
}

int main() {
	int N, K;
	long long int ans = 0;
	cin >> N >> K;

	mat = vector<vector<long long int>>(N, vector<long long int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >>  mat[i][j];
		}
	}
	vector<vector<long long int>> ansMat = squareMatrix (N, K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += ansMat[i][j] % DIV_NUM;
			ans %= DIV_NUM;
		}
	}
	cout << ans % DIV_NUM;
}
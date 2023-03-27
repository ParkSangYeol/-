//BOJ 22345 누적거리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Town {
	int location;
	int numOfPeople;
	long long int cost;
};

bool operator <(Town const& t, long long int const i)
{
	return t.location < i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	int x, a, q;
	vector<Town> towns;
	vector<Town> townsIncrease;
	vector<Town> townsDecrease;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> a >> x;
		towns.push_back({ x, a, 0 });
	}
	sort(towns.begin(), towns.end(), [](const Town& a, const Town& b)-> bool {
		return a.location < b.location;
	});

	townsIncrease.push_back(towns[0]);
	townsDecrease.push_back(towns[N-1]);

	for (int i = 1; i < N; i++) {
		Town tempTown;
		tempTown.location = towns[i].location;
		tempTown.numOfPeople = townsIncrease[i - 1].numOfPeople + towns[i].numOfPeople;
		tempTown.cost = (long long int)(towns[i].location - townsIncrease[i - 1].location) * townsIncrease[i - 1].numOfPeople + townsIncrease[i - 1].cost;
		townsIncrease.push_back(tempTown);

		tempTown.location = towns[N - 1 - i].location;
		tempTown.numOfPeople = townsDecrease[i - 1].numOfPeople + towns[N - i - 1].numOfPeople;
		tempTown.cost = (long long int)(townsDecrease[i - 1].location - towns[N - i - 1].location) * townsDecrease[i - 1].numOfPeople + townsDecrease[i - 1].cost;
		townsDecrease.push_back(tempTown);
	}

	for (int i = 0; i < Q; i++) {
		long long int ans;
		cin >> q;
		auto lowIter = lower_bound(townsIncrease.begin(), townsIncrease.end(), q);
		auto highIter = lower_bound(townsDecrease.rbegin(), townsDecrease.rend(), q);
		if (lowIter == townsIncrease.end()){
			// 큰 값으로 넘어갈 경우
			ans = (townsIncrease.end() - 1)->cost + (long long int)(q - (townsIncrease.end() - 1)->location) * (townsIncrease.end() - 1)->numOfPeople;
		}
		else if (highIter == townsDecrease.rbegin()) {
			// 작은 값으로 넘어갈 경우
			ans = townsDecrease.rbegin()->cost + (long long int)(townsDecrease.rbegin()->location - q) * townsDecrease.rbegin()->numOfPeople;
		}
		else {
			// 중간일 경우
			if (lowIter->location == q)
				ans = lowIter->cost + highIter->cost;
			else {
				lowIter--;
				ans = lowIter->cost + (long long int)(q - lowIter->location) * lowIter->numOfPeople;
				ans += highIter->cost + (long long int)(highIter->location - q) * highIter->numOfPeople;
			}
		}
		cout << ans << '\n';
	}
}
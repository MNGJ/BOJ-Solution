#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<long long> v;

void Input()
{
	cin >> N >> C;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
}

void Solve(int start, int end, vector<long long>& part, long long sum)
{
	if (start > end) {
		part.push_back(sum);
		return;
	}
	else {
		Solve(start + 1, end, part, sum); // 추가하지 않음
		Solve(start + 1, end, part, sum + v[start]); // 추가
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	vector<long long> part1;
	vector<long long> part2;
	Solve(0, N / 2 - 1, part1, 0);
	Solve(N / 2, N - 1, part2, 0);
	sort(part2.begin(), part2.end());
	int cnt = 0;
	for (int i = 0; i < part1.size(); i++)
	{
		long long x = C - part1[i];
		cnt += upper_bound(part2.begin(), part2.end(), x) - part2.begin();
	}

	cout << cnt;

	return 0;
}
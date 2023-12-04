#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N;
vector<tuple<int, int, int>> board;

static bool CmpName(tuple<int, int, int>& v1, tuple<int, int, int>& v2)
{
	return get<2>(v1) > get<2>(v2);
}

void Solve()
{
	sort(board.begin(), board.end(), CmpName);
	cout << get<0>(board[0]) << ' ' << get<1>(board[0]) << '\n';
	cout << get<0>(board[1]) << ' ' << get<1>(board[1]) << '\n';
	for (int i = 2; i < N; i++)
	{
		if (get<0>(board[0]) == get<0>(board[i]) && get<0>(board[1]) == get<0>(board[i]))
			continue;
		cout << get<0>(board[i]) << ' ' << get<1>(board[i]);
		return;
	}
}

void Input()
{
	cin >> N;
	int a, b, c;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		board.push_back(make_tuple(a, b, c));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}
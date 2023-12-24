#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int DP[1002][1002];

void Input()
{
	cin >> str1 >> str2;
}

void Solve()
{
	for(int i = 1; i <= str1.size(); i++)
		for (int j = 1; j <= str2.size(); j++)
		{
			if (i == 0 || j == 0)
				DP[i][j] = 0;
			else if (str1[i-1] == str2[j-1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
			{
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}

	int cnt = DP[str1.size()][str2.size()];
	int i = str1.size();
	int j = str2.size();
	int idx = i;
	vector<char> ans;
	cout << cnt << "\n";
	while (i > 0 && j > 0)
	{
		if (str1[i-1] == str2[j-1])
		{
			ans.push_back(str1[i-1]);
			i--;
			j--;
			idx--;
		}
		else if (DP[i-1][j] > DP[i][j-1])
			i--;
		else
			j--;
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}
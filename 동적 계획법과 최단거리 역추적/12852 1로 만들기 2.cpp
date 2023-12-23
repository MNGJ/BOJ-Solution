#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000001;
vector<int> ans;
int dp[1000001];
int N;
int cnt = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = INF;
	}
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			dp[i]= min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i]= min(dp[i], dp[i / 2] + 1);
		}
		dp[i] = min(dp[i], dp[i-1] + 1);
		
	}

	cout << dp[N]<< '\n';
	int x = N;
	while (x > 0)
	{
		cout << x << " ";
		if (x % 3 == 0 && dp[x/3] + 1 == dp[x])
		{
			x /= 3;
		}
		else if (x % 2 == 0 && dp[x / 2] + 1 == dp[x])
		{
			x /= 2;
		}
		else
		{
			x--;
		}
	}

	return 0;
}
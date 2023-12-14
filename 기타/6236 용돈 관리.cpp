#include <iostream>
using namespace std;

int N, M;
int day_money[100001];
int result, sum = 0;

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> day_money[i];
		sum += day_money[i];
	}
}

void bina_search()
{
	int low = 1;
	int high = sum;
	while (low <= high)
	{
		int mid = (high + low) / 2;
		int total = mid;
		int cnt = 1;
		bool pass = true;
		for (int i = 0; i < N; i++)
		{
			if (mid < day_money[i]) // 하루 쓸 돈이 인출 값보다 더 많으면 불가능
			{
				pass = false;
				break;
			}
			if (total >= day_money[i]) // 남은 금액이 더 많으면
			{
				total -= day_money[i];
			}
			else if (total < day_money[i]) // 인출해야되면 값 초기화 해주고 인출횟수+1
			{
				total = mid;
				total -= day_money[i];
				cnt++;
			}
		}
		if (!pass || cnt > M) // 인출 횟수가 더 많거나 돈이 부족하다면
		{
			low = mid + 1;
		}
		else // 아니라면 결과값 갱신하고 인출값 줄여보기
		{
			result = mid;
			high = mid - 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	bina_search();

	cout << result;

	return 0;
}
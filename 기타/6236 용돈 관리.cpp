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
			if (mid < day_money[i]) // �Ϸ� �� ���� ���� ������ �� ������ �Ұ���
			{
				pass = false;
				break;
			}
			if (total >= day_money[i]) // ���� �ݾ��� �� ������
			{
				total -= day_money[i];
			}
			else if (total < day_money[i]) // �����ؾߵǸ� �� �ʱ�ȭ ���ְ� ����Ƚ��+1
			{
				total = mid;
				total -= day_money[i];
				cnt++;
			}
		}
		if (!pass || cnt > M) // ���� Ƚ���� �� ���ų� ���� �����ϴٸ�
		{
			low = mid + 1;
		}
		else // �ƴ϶�� ����� �����ϰ� ���Ⱚ �ٿ�����
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
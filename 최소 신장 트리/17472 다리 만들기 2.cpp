#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Info
{
	int a;
	int b;
	int dis;
};

bool cmp(const Info& a, const Info& b) { return a.dis < b.dis; }

int N, M;
int arr[12][12];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<Info> infomation;
int u[101];
int island_num = 0;

int Find(int a)
{
	if (u[a] == a) return a;
	else return u[a] = Find(u[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b)
		u[b] = a;
	else
		u[a] = b;
}

void BFS(int y, int x,int cnt)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	arr[y][x] = cnt;
	while (!q.empty())
	{
		int cur_x = q.front().second;
		int cur_y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (arr[ny][nx] == 1)
			{
				q.push({ ny, nx });
				arr[ny][nx] = cnt;
			}
		}
	}
}

void Get_distance(int y, int x, int idx)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		int distance = 0;
		if (arr[ny][nx] == idx)
			continue;
		while (arr[ny][nx] == 0)
		{
			if (ny < 1 || ny > N || nx < 1 || nx > M)
				break;
			distance++;
			ny += dy[i];
			nx += dx[i];
			if (arr[ny][nx] != 0)
				break;
		}
		if(distance >= 2 && arr[ny][nx] != 0)
			infomation.push_back({ idx, arr[ny][nx], distance });
	}
}

void Input()
{
	for (int i = 0; i < 101; i++)
		u[i] = i;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	int cnt = 2;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 1)
			{
				BFS(i, j, cnt);
				cnt++;
				island_num++;
			}
		}
	/*cout << '\n';
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}*/
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j])
			{
				int land = arr[i][j];
				Get_distance(i, j, land);
			}
		}
	sort(infomation.begin(), infomation.end(), cmp);
}

void Solve()
{
	//for (int i = 0; i < infomation.size(); i++)
	//{
	//	cout << "a : " << infomation[i].a << ", b : " << infomation[i].b << ", dis : " << infomation[i].dis << '\n';
	//}
	int sum = 0;
	int bridge_count = 0;
	for (int i = 0; i < infomation.size(); i++)
	{
		int a = Find(infomation[i].a);
		int b = Find(infomation[i].b);
		if (a != b)
		{
			Union(a, b);
			sum += infomation[i].dis;
			bridge_count++;
		}
		if (bridge_count == island_num - 1)
			break;
	}
	if (bridge_count == island_num - 1)
		cout << sum;
	else
		cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}
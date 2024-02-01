#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll, ll> pll;

struct line
{
	pll a;
	pll b;
};

int N;
vector<line> vec;
int arr[3001];
int cnt[3001];

int find(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = find(arr[a]);
}

void union_group(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b)
		arr[b] = a;
	else
		arr[a] = b;
}

int ccw(pll A, pll B, pll C)
{
	ll s = A.x * B.y + B.x * C.y + C.x * A.y;
	s -= (A.x * C.y + B.x * A.y + C.x * B.y);

	if (s > 0) return 1; // 반시계 방향
	else if (s < 0) return -1; // 시계 방향
	else return 0; // 일직선
}

bool isline_intersect(line l1, line l2) 
{
	int std1, std2;

	std1 = ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b);
	std2 = ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b);

	if (std1 <= 0 && std2 <= 0) {
		if (std1 == 0 && std2 == 0) {     //선분이 일직선인 경우
			if (l1.b <= l1.a) swap(l1.a, l1.b);
			if (l2.b <= l2.a) swap(l2.a, l2.b);

			return l1.a <= l2.b && l2.a <= l1.b;
		}
		else return true;   //일직선이 아니면 교차함
	}
	else return false;  //CCW가 같은 방향이 있으면 
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (isline_intersect(vec[i], vec[j]))
			{
				union_group(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = find(arr[i]);
		cnt[arr[i]]++;
	}
	int group_count = 0, group_higher = 0;
	for (int i = 0; i < N; i++)
	{
		if (cnt[i])
		{
			group_count++;
			group_higher = max(group_higher, cnt[i]);
		}
	}
	cout << group_count << '\n';
	cout << group_higher;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back({ {x1, y1}, {x2, y2 } });
	}

	for (int i = 0; i <= N; i++)
	{
		arr[i] = i;
	}

	solve();

	return 0;
}
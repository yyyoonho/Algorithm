#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

//16928
#define DICE 6

int N, M;
int cntMap[101];
queue<int> q;
map<int,int> m;

void Input()
{
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M + N; i++)
	{
		cin >> a >> b;
		m.insert(make_pair(a, b));
	}

	for (int i = 2; i < 101; i++)
	{
		cntMap[i] = INT32_MAX;
	}
}

void Solve()
{
	
	q.push(1);
	while (true)
	{
		bool flag = false;
		int now = q.front();
		q.pop();
		
		for (int i = 1; i <= DICE; i++)
		{
			int next = now + i;
			if (next == 100)
			{
				flag = true;
				cntMap[next] = cntMap[now] + 1;
				break;
			}

			if (next > 100) break;
			if (cntMap[next] < cntMap[now] + 1) continue;

			if (m.end()!=m.find(next))
			{
				if (cntMap[m[next]] < cntMap[now] + 1) continue;

				q.push(m[next]);
				cntMap[m[next]] = cntMap[now] + 1;
			}
			else
			{
				q.push(next);
				cntMap[next] = cntMap[now] + 1;
			}

		}
		
		if (flag) break;
	}

	/*for (int i = 1; i < 101; i++)
	{
		cout << cntMap[i] << " ";
	}*/

	cout << cntMap[100];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solve();

	return 0;
}

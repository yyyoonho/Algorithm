#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//2146
//BFS
//기본에 충실하자 


#define MAXN 101
int N;
int map[MAXN][MAXN];
bool discovered[MAXN][MAXN];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}
}

bool CheckBoundary(int y, int x)
{
	if (x < 0 || x >= N || y < 0 || y >= N) return false;
	
	return true;
}

void LabelingIsland(int y, int x, int label)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(y, x));
	discovered[y][x] = true;
	map[y][x] = label;

	while (!Q.empty())
	{
		int nowY = Q.front().first;
		int nowX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (CheckBoundary(nextY, nextX)==false) continue;
			if (map[nextY][nextX] != -1) continue;
			if (discovered[nextY][nextX]) continue;

			map[nextY][nextX] = label;
			discovered[nextY][nextX] = true;
			Q.push(make_pair(nextY, nextX));
		}
	}
}

int BFS(int label)
{
	int maxBridge = 0;
	queue<pair<int, int> > Q;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == label)
			{
				Q.push(make_pair(i, j));
				discovered[i][j] = true;
			}
		}
	}
	
	while (!Q.empty())
	{
		int Q_size = Q.size();

		for (int i = 0; i < Q_size; i++)
		{
			int nowY = Q.front().first;
			int nowX = Q.front().second;
			Q.pop();

			for (int j = 0; j < 4; j++)
			{
				int nextY = nowY + dy[j];
				int nextX = nowX + dx[j];

				if (CheckBoundary(nextY, nextX) == false) continue;
				if (discovered[nextY][nextX]) continue;	

				if (map[nextY][nextX] != 0 && map[nextY][nextX] != label) return maxBridge;

				discovered[nextY][nextX] = true;
				Q.push(make_pair(nextY, nextX));
			}
		}
		maxBridge++;
	}
}

void Solve()
{
	int ans = INT32_MAX;

	int label = 1;
	for (int i = 0; i < N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if (map[i][j] == -1)
			{
				LabelingIsland(i, j, label);
				label++;
			}
		}
	}

	for (int i = 1; i < label; i++)
	{
		memset(discovered, false, sizeof(discovered));
		int check = BFS(i);
		ans = min(ans, check);
	}

	cout << ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solve();

	return 0;

}

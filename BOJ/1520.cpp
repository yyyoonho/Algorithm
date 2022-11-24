#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//1520
//DFS + DP

#define MAXN 501
int M, N;
int map[MAXN][MAXN];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int dp[MAXN][MAXN];

void Input()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
}

int DFS(int y, int x)
{
	if (y==M-1 && x==N-1)
	{
		return 1;
	}
	
	if (dp[y][x] != -1)
	{
		return dp[y][x];
	}

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N) continue;
		if (map[nextY][nextX] >= map[y][x]) continue;

		dp[y][x] += DFS(nextY, nextX);
	}

	return dp[y][x];
}



void Solve()
{
	int cnt = DFS(0, 0);
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solve();

	return 0;
}

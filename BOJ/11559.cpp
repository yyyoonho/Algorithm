#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//11559

char map[13][7];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
queue<pair<int, int> > Q;
queue<pair<int, int> > waitQ;
bool discovered[13][7];

char colorList[5] = { 'R','G','B','P','Y' };

void Input()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> map[i][j];
		}
	}
}

bool CanGo(int y, int x, char color)
{
	if (y < 0 || y>12 || x < 0 || x>11) return false;
	else if (map[y][x] == '.') return false;
	else if (map[y][x] != color) return false;
	else return true;
}

int BFS()
{
	memset(discovered, false, sizeof(discovered));
	int boomCnt = 0;

	//순차적으로 탐색 후 color와 일치하는 뿌요만 BFS과정 진행 (총 5번반복 = color갯수)
	for (int color = 0; color < 5; color++)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] == colorList[color] && discovered[i][j]==false)
				{
					Q.push(make_pair(i,j));
					waitQ.push(make_pair(i, j));
					discovered[i][j] = true;

					while (!Q.empty())
					{
						int nowY = Q.front().first;
						int nowX = Q.front().second;
						Q.pop();

						for (int k = 0; k < 4; k++)
						{
							int nextY = nowY + dy[k];
							int nextX = nowX + dx[k];

							if (!CanGo(nextY, nextX, colorList[color])) continue;
							if (discovered[nextY][nextX]) continue;

							Q.push(make_pair(nextY, nextX));
							discovered[nextY][nextX] = true;
							waitQ.push(make_pair(nextY, nextX));
						}
					}
					
					if (waitQ.size() >= 4)
					{
						boomCnt++;
						while (!waitQ.empty())
						{
							map[waitQ.front().first][waitQ.front().second] = '.';
							waitQ.pop();
						}
					}
					else
					{
						while (!waitQ.empty())
						{
							waitQ.pop();
						}
					}

				}
			}
		}
	}

	return boomCnt;
}

void DownPuyo()
{
	for (int j = 0; j < 6; j++)
	{
		for (int i = 10; i >=0; i--)
		{
			if (map[i][j] == '.') continue;
			
			int nextY=INT32_MAX;
			for (int k = i+1; k < 12; k++)
			{
				if (map[k][j] == '.') {
					nextY = k;
				}
				else break;
			}

			if (nextY != INT32_MAX)
			{
				map[nextY][j] = map[i][j];
				map[i][j] = '.';
			}
		}
	}
}

void Solve()
{
	int boomCntTotal = 0;
	while (true)
	{
		//뿌요 터트리기
		int boomCnt = BFS();
		if (boomCnt == 0) break;
		else boomCntTotal++;

		//뿌요 내리기
		DownPuyo();

		/*for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}*/
	}

	cout << boomCntTotal;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solve();

	return 0;
}

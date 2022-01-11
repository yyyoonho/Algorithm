#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//백준_11657_타임머신

#define INF 9876543210

struct Data {
	int x;
	int y;
	long long w;
	Data(){}
	Data(int x1, int y1, long long w1) {
		x = x1;
		y = y1;
		w = w1;
	}
};

int N, M;
int a, b, c;
long long dist[501];
Data list[6000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		list[i] = Data(a, b, c);
	}

	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}

	dist[1] = 0;

	for (int i = 1; i < N; i++) { //N-1번 순회
		for (int j = 0; j < M; j++) {
			if (dist[list[j].x] == INF) continue;
			if (dist[list[j].y] > dist[list[j].x] + list[j].w) {
				dist[list[j].y] = dist[list[j].x] + list[j].w;
			}
		}
	}

	bool isCycle = false;

	for (int j = 0; j < M; j++) { //N번째 순회 -> N번째 순회에서도 최단거리가 update될 시, 음의사이클 존재o
		if (dist[list[j].x] == INF) continue;
		if (dist[list[j].y] > dist[list[j].x] + list[j].w) {
			isCycle = true;
			break;
		}
	}

	if (isCycle) {
		cout << -1 << endl;
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) {
				cout << -1 << endl;
			}
			else {
				cout << dist[i] << endl;
			}
		}
	}
	
	return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//백준_1753_최단경로 

#define MAXV 20001
#define INF 2147483647

struct Data {
	int vertex;
	int weight;
	Data(int v1, int w1) {
		vertex = v1;
		weight = w1;
	}
	bool operator<(const Data& b)const {
		return weight > b.weight;
	}
};

priority_queue<Data> pQ;
vector<Data> v[MAXV];
int cost[MAXV];
bool visit[MAXV];
int V, E, K;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> V >> E >> K;

	for (int i = 0; i <= V; i++) cost[i] = INF;

	int x, y, w;
	for (int i = 0; i < E; i++) {
		cin >> x >> y >> w;
		v[x].push_back(Data(y, w));
	}

	pQ.push(Data(K, 0));
	cost[K] = 0;

	while (!pQ.empty()) {
		Data now = pQ.top();
		pQ.pop();

		if (visit[now.vertex]) continue;
		visit[now.vertex] = true;

		for (int i = 0; i < v[now.vertex].size(); i++) {
			Data next = v[now.vertex][i];
			if (visit[next.vertex])continue;
			if (cost[next.vertex] > cost[now.vertex] + next.weight) {
				cost[next.vertex] = cost[now.vertex] + next.weight;
				pQ.push(Data(next.vertex,cost[next.vertex]));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (cost[i] == INF) cout << "INF" << endl;
		else cout << cost[i] << endl;
	}

	return 0;
}
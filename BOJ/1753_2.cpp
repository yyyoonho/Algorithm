#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

//1753
//다익스트라
//개선버전 

using namespace std;

struct Node
{
	Node(int to, int weight): to(to), weight(weight){
	}
	
	int to;
	int weight;
	
	bool operator<(const Node& other) const
	{
		return weight>other.weight;
	}

};

int V,E;
int K;
vector<Node> map[200001];
priority_queue<Node> pq;
int best[200001];

void Input(){
	cin>>V>>E;
	cin>>K;
	
	int a,b,w;
	for(int i=0; i<E; i++)
	{
		cin>>a>>b>>w;
		map[a].push_back(Node(b,w));
	}
	
	for(int i=0; i<=V; i++)
	{
		best[i]=INT32_MAX;
	}
}

void Solve(){
	pq.push(Node(K,0));
	best[K]=0;
	
	while(!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		
		if(best[now.to]<now.weight) continue;
		
		for(int i=0; i<map[now.to].size(); i++)
		{
			Node next = map[now.to][i];
			
			int nextCost = best[now.to]+next.weight;
			if(nextCost>=best[next.to]) continue;
			
			best[next.to]=nextCost;
			pq.push(Node(next.to, nextCost));
		}
	}
	
	for(int i=1; i<=V; i++){
		if(best[i]==INT32_MAX){
			cout<<"INF"<<'\n';
		}
		else cout<<best[i]<<'\n';
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 

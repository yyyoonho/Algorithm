#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
//boj_1504
//다익스트라
//예외처리를 잘하자. 

#define INF 2147483600
#define MAXN 801
int V,E;

vector<int> stopOver;
int dist[MAXN];
bool visited[MAXN];

struct Node{
	int b;
	int c;
	Node(int b1, int c1){
		b=b1;
		c=c1;
	}
	bool operator<(const Node& tmpB)const{
		return c>tmpB.c;
	}
};

vector<Node> map[MAXN];

void Input(){
	cin>>V>>E;
	int a,b,c;
	for(int i=0; i<E; i++){
		cin>>a>>b>>c;
		map[a].push_back(Node(b,c));
		map[b].push_back(Node(a,c));
	}
	for(int i=0; i<2; i++){
		cin>>a;
		stopOver.push_back(a);
	}
}

priority_queue<Node> pQ;

void Djk(int start){
	//초기화 
	for(int i=0; i<=V; i++){
		dist[i]=INF;
	}
	while(!pQ.empty()) pQ.pop();
	memset(visited,0,sizeof(visited));
	
	dist[start]=0;
	pQ.push(Node(start,0));
	
	while(!pQ.empty()){
		Node now=pQ.top();
		pQ.pop();
		
		if(visited[now.b]) continue;
		visited[now.b]=true;
		
		for(int i=0; i<map[now.b].size(); i++){
			Node next=map[now.b][i];
			if(visited[next.b]) continue;
			if(dist[next.b]>dist[now.b]+next.c){
				dist[next.b]=dist[now.b]+next.c;
				pQ.push(Node(next.b,dist[next.b]));
			}
		}
	}
}

void Solve(){
	Djk(1);
	int startToA=dist[stopOver[0]];
	int startToB=dist[stopOver[1]];
	
	Djk(stopOver[0]);
	int AtoB=dist[stopOver[1]];
	int AtoN=dist[V];
	
	Djk(stopOver[1]);
	int BtoA=dist[stopOver[0]]; // <= 사실 AtoB와 동일한 값이기 때문에 따로 구해주지 않아도 된다. 
	int BtoN=dist[V];
	
	if(AtoB>=INF){
		cout<<-1;
		exit(0);
	}
	
	int route1=startToA+AtoB+BtoN;
	int route2=startToB+BtoA+AtoN;
	int ans=INF;
	ans=min(ans,route1);
	ans=min(ans,route2);
	if(ans==INF){
		cout<<-1;
		exit(0);
	}
	cout<<ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
